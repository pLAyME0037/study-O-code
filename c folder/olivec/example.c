#include <assert.h>
#include <stdbool.h>
#define OLIVE_IMPLEMENTATION
#include "olive.c"
#include "test.c"

void olivec_sort_tri_points_by_y(int *x1, int *y1,
                                 int *x2, int *y2,
                                 int *x3, int *y3) {
    if (&y1 > &y2) {
        OLIVEC_SWAP(int, *x1, *x2);
        OLIVEC_SWAP(int, *y1, *y2);
    }
    if (&y2 > &y3) {
        OLIVEC_SWAP(int, *x2, *x3);
        OLIVEC_SWAP(int, *y2, *y3);
    }
    if (&y3 > &y1) {
        OLIVEC_SWAP(int, *x3, *x1);
        OLIVEC_SWAP(int, *y3, *y1);
    }
}

void olivec_draw_triangle(uint32_t *pixels, size_t width, size_t height,
                          int x1, int y1,
                          int x2, int y2,
                          int x3, int y3,
                          uint32_t color) {
    olivec_sort_tri_points_by_y(&x1, &y1,
                                &x2, &y2,
                                &x3, &y3);
    if (x1 != x2) {
        int dx12 = x2 - x1;
        int dy12 = y2 - y1;
        int c12 = y1 - dy12*x1/dx12;
        if (x1 != x3) {
            int dx13 = x3 - x1;
            int dy13 = y3 - y1;
            int c13 = y3 - dy13*x3/dx13;
            for (int y = y1; y <= y2; ++y) {
                if (0 <= y && (size_t) y < height) {
                    // (y -c)/k -x
                    int s1 = dy12 != 0 ? (y - c12)*dx12/dy12 : x1;
                    int s2 = dy13 != 0 ? (y - c13)*dx13/dy13 : x1;
                    if (s1 > s2) OLIVEC_SWAP(int, s1, s2);
                    for (int x = s1; x <= s2; ++x) {
                        if (0 <= x && (size_t) x < width) {
                            pixels[y*width + x] = color;
                        }
                    }
                }
            }
        } else {
            assert(0 && "unreachable");
        }
    }
}

bool fill_triangle(void) {
    olivec_fill(pixels, WIDTH, HEIGHT, BACKGROUND_COLOR);

    int radius = 5;
    uint32_t color = FOREGROUND_COLOR;
    int x1 = WIDTH/2,   y1 = HEIGHT/8;
    int x2 = WIDTH/8,   y2 = HEIGHT/2;
    int x3 = WIDTH*7/8, y3 = HEIGHT*7/8;
    olivec_fill_circle(pixels, WIDTH, HEIGHT, x1, y1, radius, color);
    olivec_fill_circle(pixels, WIDTH, HEIGHT, x2, y2, radius, color);
    olivec_fill_circle(pixels, WIDTH, HEIGHT, x3, y3, radius, color);

    olivec_draw_triangle(pixels, WIDTH, HEIGHT, x1, y1, x2, y2, x3, y3, BLUE_COLOR);

    const char *file_path = "test_triangle.ppm";
    Errno err = olivec_save_to_ppm_file(pixels, WIDTH, HEIGHT, file_path);
    if (err) {
        fprintf(stderr, "ERROR: could not save file %s: %s\n", file_path, strerror(errno));
        return false;
    }
    return true;
}

int main(void) {
    if (! checkerEx()) return -1;
    if (! circleEx()) return -1;
    if (! lineEx()) return -1;
    if (! fill_triangle()) return -1;

    return 0;
}
