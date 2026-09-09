#include <stdio.h>

#include "route.h"
#include "notes.h"
#include "table.h"
#include "version.h"
#include "crud.h"
#include "crud_modules.h"
#include "stock.h"
#include "import.h"
#include "patient_invoice.h"
#include "org.h"
#include "user.h"
#include "master_detail.h"

static const Crud_Module *crud_find_module(String_View uri) {
    const Crud_Module *best = NULL;
    for (size_t i = 0; i < crud_modules_count; ++i) {
        String_View p = sv_from_cstr(crud_modules[i]->path);
        if (!sv_starts_with(uri, p)) continue;
        if (!best || strlen(crud_modules[i]->path) > strlen(best->path)) best = crud_modules[i];
    }
    return best;
}

// Extract the integer id from "/<path>/<id>/<suffix>".
static bool parse_uri_id(String_View path,
                         String_View uri,
                         const char *suffix,
                         int        *id)
{
    String_View prefix;
    prefix = sv_from_cstr(temp_sprintf("%.*s/", (int)path.count, path.data));
    if (uri.count <= prefix.count
        || memcmp(uri.data, prefix.data, prefix.count) != 0) {
        return false;
    }
    String_View suffix_sv;
    suffix_sv = sv_from_cstr(suffix);
    if (uri.count <= suffix_sv.count) return false;
    if (memcmp(uri.data + uri.count - suffix_sv.count, suffix_sv.data, suffix_sv.count) != 0) {
        return false;
    }

    String_View id_sv = {
        .data  = uri.data + prefix.count,
        .count = uri.count - prefix.count - suffix_sv.count,
    };
    char buf[32] = {0};
    snprintf(buf, sizeof(buf), "%.*s", (int)id_sv.count, id_sv.data);
    char *end = NULL;
    long value = strtol(buf, &end, 10);
    if (end == buf || *end != '\0') return false;
    *id = (int)value;
    return true;
}

static bool crud_parse_id(const Crud_Module *mod,
                          String_View        uri,
                          const char        *suffix,
                          int               *id)
{
    return parse_uri_id(sv_from_cstr(mod->path), uri, suffix, id);
}

void serve_resource_route(Serve_Context *sc, String_View uri) {
    if (sv_starts_with(uri, sv_from_cstr("/js/"))) {
        String_View rest = { .data = uri.data + 4, .count = uri.count - 4 };
        String_Builder path = {0};
        sb_append_cstr(&path, "./js/");
        sb_append_sv(&path, rest);
        sb_append_null(&path);
        // determine content_type (text/javascript for .js)
        serve_resource(sc, path.items, "text/javascript; charset=utf-8");
        return;
    }
    if (sv_eq(uri, sv_from_cstr("/css/output.css"))) {
        serve_resource(sc, "./css/output.css", "text/css; charset=utf-8");
        return;
    }
    if (sv_eq(uri, sv_from_cstr("/favicon.ico"))) {
        serve_resource(sc, "./resource/image/user1.png", "image/png");
        return;
    }
    if (sv_starts_with(uri, sv_from_cstr("/resource/"))) {
        String_View resource_prefix = sv_from_cstr("/resource/");
        String_View rest = {
            .data  = uri.data + resource_prefix.count,
            .count = uri.count - resource_prefix.count,
        };
        String_Builder path = {0};
        sb_append_cstr(&path, "./resource/");
        sb_append_sv(&path, rest);
        sb_append_null(&path);

        int type_id;
        if (sv_ends_with(rest, sv_from_cstr(".png")))  type_id = 1;
        if (sv_ends_with(rest, sv_from_cstr(".jpg")))  type_id = 2;
        if (sv_ends_with(rest, sv_from_cstr(".svg")))  type_id = 3;
        if (sv_ends_with(rest, sv_from_cstr(".css")))  type_id = 4;
        if (sv_ends_with(rest, sv_from_cstr(".js")))   type_id = 5;
        if (sv_ends_with(rest, sv_from_cstr(".html"))) type_id = 6;
        const char *content_type;
        switch (type_id) {
        case 1: content_type = "image/png";                      break;
        case 2: content_type = "image/jpeg";                     break;
        case 3: content_type = "image/svg+xml";                  break;
        case 4: content_type = "text/css; charset=utf-8";        break;
        case 5: content_type = "text/javascript; charset=utf-8"; break;
        case 6: content_type = "text/html; charset=utf-8";       break;
        default: content_type = "application/octet-stream";      break;
        }
        serve_resource(sc, path.items, content_type);
        return;
    }
    serve_error(sc, 404);
}

void serve_dashboard(Serve_Context *sc);

#define CMP_URI(dst_uri, src_uri) sv_eq((dst_uri), (sv_from_cstr(src_uri)))

void route_request(Serve_Context *sc, String_View method, String_View uri) {
    if (CMP_URI(uri, "/")) {
        serve_dashboard(sc);
        return;
    }
    if (CMP_URI(uri, "/table")) {
        serve_table(sc, method);
        return;
    }
    if (CMP_URI(uri, "/notes")) {
        serve_notes(sc, method);
        return;
    }
    if (CMP_URI(uri, "/version")) {
        serve_version_page(sc);
        return;
    }
    if (CMP_URI(uri, "/api/notes")) {
        serve_notes_api(sc, method);
        return;
    }
    if (CMP_URI(method, "POST") && CMP_URI(uri, "/notes/create")) {
        serve_notes_create(sc);
        return;
    }
    if (CMP_URI(uri, "/users")) {
        serve_users(sc, method);
        return;
    }
    if (CMP_URI(method, "POST") && CMP_URI(uri, "/users/create")) {
        serve_users_create(sc);
        return;
    }
    int user_id = 0;
    if (CMP_URI(method, "GET")
        && parse_uri_id(sv_from_cstr("/users"), uri, "/edit", &user_id)) {
        serve_users_edit(sc, uri);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(sv_from_cstr("/users"), uri, "/update", &user_id)) {
        serve_users_update(sc, uri);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(sv_from_cstr("/users"), uri, "/delete", &user_id)) {
        serve_users_delete(sc, uri);
        return;
    }
    if (CMP_URI(method, "GET") && CMP_URI(uri, "/medicine-stock")) {
        serve_stock_list(sc);
        return;
    }

    if (CMP_URI(method, "GET") && CMP_URI(uri, "/medicine-imports")) {
        serve_import_list(sc);
        return;
    }
    if (CMP_URI(method, "POST") && CMP_URI(uri, "/medicine-imports/create")) {
        serve_import_create(sc);
        return;
    }

    int import_id = 0;
    String_View medicine_imports = sv_from_cstr("/medicine-imports");
    if (CMP_URI(method, "GET")
        && parse_uri_id(medicine_imports, uri, "/edit", &import_id)) {
        serve_import_edit(sc, import_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(medicine_imports, uri, "/update", &import_id)) {
        serve_import_update(sc, import_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(medicine_imports, uri, "/delete", &import_id)) {
        serve_import_delete(sc, import_id);
        return;
    }

    // ---- Patient Medicine Invoice (header + details) ----
    if (CMP_URI(method, "GET") && CMP_URI(uri, "/patient-medicine-invoices")) {
        serve_master_detail_by_table(sc, "PatientMedicineInvoices");
        return;
    }
    if (CMP_URI(method, "POST")
        && CMP_URI(uri, "/patient-medicine-invoices/create")) {
        serve_pmi_create(sc);
        return;
    }
    int pmi_id = 0;
   String_View pmi = sv_from_cstr("/patient-medicine-invoices") ;
    if (CMP_URI(method, "POST") && parse_uri_id(pmi, uri, "/update", &pmi_id)) {
        serve_pmi_update(sc, pmi_id);
        return;
    }
    if (CMP_URI(method, "POST") && parse_uri_id(pmi, uri, "/delete", &pmi_id)) {
        serve_pmi_delete(sc, pmi_id);
        return;
    }

    // ---- Patient Invoice Out (header + details) ----
    if (CMP_URI(method, "GET") && CMP_URI(uri, "/patient-invoice-out")) {
        serve_master_detail_by_table(sc, "PatientInvoiceOut");
        return;
    }
    if (CMP_URI(method, "POST") && CMP_URI(uri, "/patient-invoice-out/create")) {
        serve_pio_create(sc);
        return;
    }
    int pio_id = 0;
    String_View pio = sv_from_cstr("/patient-invoice-out");
    if (CMP_URI(method, "POST")
        && parse_uri_id(pio, uri, "/update", &pio_id)) {
        serve_pio_update(sc, pio_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(pio, uri, "/delete", &pio_id)) {
        serve_pio_delete(sc, pio_id);
        return;
    }

    // ---- Organization Daily Invoice (header + details) ----
    if (CMP_URI(method, "GET") && CMP_URI(uri, "/organization-daily-invoices")) {
        serve_master_detail_by_table(sc, "OrganizationDailyInvoices");
        return;
    }
    if (CMP_URI(method, "POST") && CMP_URI(uri, "/organization-daily-invoices/create")) {
        serve_org_daily_create(sc);
        return;
    }

    int org_daily_inv_id = 0;
    String_View org_daily_inv = sv_from_cstr("/organization-daily-invoices");
    if (CMP_URI(method, "GET")
        && parse_uri_id(org_daily_inv, uri, "/edit", &org_daily_inv_id)) {
        serve_org_daily_edit(sc, org_daily_inv_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(org_daily_inv, uri, "/update", &org_daily_inv_id)) {
        serve_org_daily_update(sc, org_daily_inv_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(org_daily_inv, uri, "/delete", &org_daily_inv_id)) {
        serve_org_daily_delete(sc, org_daily_inv_id);
        return;
    }
    if (CMP_URI(method, "GET")
        && parse_uri_id(org_daily_inv, uri, "/details", &org_daily_inv_id)) {
        serve_org_daily_details(sc, org_daily_inv_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(org_daily_inv, uri, "/details/create", &org_daily_inv_id)) {
        serve_org_daily_detail_create(sc, org_daily_inv_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && sv_starts_with(uri, sv_from_cstr("/organization-daily-invoices/"))
        && sv_ends_with(uri, sv_from_cstr("/delete"))) {
        char buf[512] = {0};
        size_t n = uri.count < sizeof(buf) - 1 ? uri.count : sizeof(buf) - 1;
        memcpy(buf, uri.data, n);
        int ill_id = 0;
        int iid = 0;
        if (sscanf(buf, "/organization-daily-invoices/%d/details/%d/delete", &iid, &ill_id) == 2) {
            serve_org_daily_detail_delete(sc, iid, ill_id);
            return;
        }
    }

    // ---- Organization Invoice Out (header + details) ----
    if (CMP_URI(method, "GET") && CMP_URI(uri, "/organization-invoice-out")) {
        serve_master_detail_by_table(sc, "OrganizationInvoiceOut");
        return;
    }
    if (CMP_URI(method, "POST") && CMP_URI(uri, "/organization-invoice-out/create")) {
        serve_org_out_create(sc);
        return;
    }

    int org_inv_out_id = 0;
    String_View org_inv_out = sv_from_cstr("/organization-invoice-out");
    if (CMP_URI(method, "GET")
        && parse_uri_id(org_inv_out, uri, "/edit", &org_inv_out_id)) {
        serve_org_out_edit(sc, org_inv_out_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(org_inv_out, uri, "/update", &org_inv_out_id)) {
        serve_org_out_update(sc, org_inv_out_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(org_inv_out, uri, "/delete", &org_inv_out_id)) {
        serve_org_out_delete(sc, org_inv_out_id);
        return;
    }
    if (CMP_URI(method, "GET")
        && parse_uri_id(org_inv_out, uri, "/details", &org_inv_out_id)) {
        serve_org_out_details(sc, org_inv_out_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && parse_uri_id(org_inv_out, uri, "/details/create", &org_inv_out_id)) {
        serve_org_out_detail_create(sc, org_inv_out_id);
        return;
    }
    if (CMP_URI(method, "POST")
        && sv_starts_with(uri, sv_from_cstr("/organization-invoice-out/"))
        && sv_ends_with(uri, sv_from_cstr("/delete"))) {
        char buf[512] = {0};
        size_t n = uri.count < sizeof(buf) - 1 ? uri.count : sizeof(buf) - 1;
        memcpy(buf, uri.data, n);
        int inv_id = 0;
        int iid = 0;
        if (sscanf(buf, "/organization-invoice-out/%d/details/%d/delete", &iid, &inv_id) == 2) {
            serve_org_out_detail_delete(sc, iid, inv_id);
            return;
        }
    }
    if (CMP_URI(method, "GET")
        && sv_ends_with(uri, sv_from_cstr("/edit"))
        && sv_starts_with(uri, sv_from_cstr("/notes/"))) {
        serve_notes_edit(sc, uri);
        return;
    }
    if (CMP_URI(method, "POST")
        && sv_ends_with(uri, sv_from_cstr("/update"))
        && sv_starts_with(uri, sv_from_cstr("/notes/"))) {
        serve_notes_update(sc, uri);
        return;
    }
    if (CMP_URI(method, "POST")
        && sv_ends_with(uri, sv_from_cstr("/delete"))
        && sv_starts_with(uri, sv_from_cstr("/notes/"))) {
        serve_notes_delete(sc, uri);
        return;
    }
    const Crud_Module *crud_mod = crud_find_module(uri);
    if (crud_mod) {
        String_View path = sv_from_cstr(crud_mod->path);
        if (sv_eq(uri, path)) {
            if (CMP_URI(method, "GET")) {
                if (find_master_config(crud_mod->table)) {
                    serve_master_detail_by_table(sc, crud_mod->table);
                } else {
                    serve_crud_list(sc, crud_mod);
                }
                return;
            }
            serve_error(sc, 405);
            return;
        }

        int id = 0;
        if (CMP_URI(method, "POST")
            && sv_ends_with(uri, sv_from_cstr("/create"))
            && sv_starts_with(uri, path)) {
            serve_crud_create(sc, crud_mod);
            return;
        }
        if (CMP_URI(method, "GET")
            && crud_parse_id(crud_mod, uri, "/edit", &id)) {
            serve_crud_edit(sc, crud_mod, id);
            return;
        }
        if (CMP_URI(method, "POST")
            && crud_parse_id(crud_mod, uri, "/update", &id)) {
            serve_crud_update(sc, crud_mod, id);
            return;
        }
        if (CMP_URI(method, "POST")
            && crud_parse_id(crud_mod, uri, "/delete", &id)) {
            serve_crud_delete(sc, crud_mod, id);
            return;
        }
    }

    if (sv_starts_with(uri, sv_from_cstr("/css/"))
        || sv_starts_with(uri, sv_from_cstr("/js/"))
        || sv_starts_with(uri, sv_from_cstr("/resource/"))
        || CMP_URI(uri, "/favicon.ico")) {
        serve_resource_route(sc, uri);
        return;
    }

    serve_error(sc, 404);
}
