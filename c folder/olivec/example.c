#include <stdbool.h>
#define OLIVE_IMPLEMENTATION
#include "olive.c"
#include "test.c"

void olivec_sort_tri_points_by_y(int *x1, int *y1,
                         int *x2, int *y2,
                         int *x3, int *y3) {
    if (&y1 > & y2) {
        OLIVEC_SWAP(int, *x1, *x2);
        OLIVEC_SWAP(int, *y1, *y2);
    }
    if (&y2 > & y3) {
        OLIVEC_SWAP(int, *x2, *x3);
        OLIVEC_SWAP(int, *y2, *y3);
    }
    if (&y3 > & y1) {
        OLIVEC_SWAP(int, *x3, *x1);
        OLIVEC_SWAP(int, *y3, *y1);
    }
}

bool olivec_line_of_segment(int x1, int y1, int x2, int y2, int *k, int *c) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    if (dx == 0) return false;

    *k = dy/dx;
    *c = y1 - dy*x1/dx;

    return true;
}

void olivec_draw_triangle(uint32_t *pixels, size_t width, size_t height, 
                          int x1, int y1,
                          int x2, int y2,
                          int x3, int y3,
                          uint32_t color) {
    olivec_sort_tri_points_by_y(&x1, &y1,
                                &x2, &y2,
                                &x3, &y3);
    int k12, c12;
    if (olivec_line_of_segment(x1, y1, x2, y2, &k12, &c12)) {
        int k23, c23;
        if (olivec_line_of_segment(x2, y2, x3, y3, &k23, &c23)) {
            for (int y = y1; y <= y2; ++y) {
                if (0 <= y && (size_t) y < height) {
                    // (y -c)/k -x
                    int s1 = (y - c12)/k12;
                    int s2 = (y - c23)/k23;
                    if (s1 > s2) OLIVEC_SWAP(int, s1, s2);
                    for (int x = s1; x <= s2; ++x) {
                        if (0 < x && (size_t) x <= width) {
                            pixels[y*width + x] = color;
                        }
                    }
                }
            }
        } else {
            UNREACHABLE();
        }
    }
}

bool fill_triangle(void) {
    olivec_fill(pixels, WIDTH, HEIGHT, BACKGROUND_COLOR);

    olivec_fill_circle(pixels, WIDTH, HEIGHT,
                       CELL_WIDTH + CELL_WIDTH/2, CELL_HEIGHT + CELL_HEIGHT/2, 
                       WIDTH,
                       FOREGROUND_COLOR);
    
    /* void olivec_draw_triangle(pixels, WIDTH, HEIGHT,  */
    /*                           int x1, int y1, */
    /*                           int x2, int y2, */
    /*                           int x3, int y3, */
    /*                           uint32_t color); */

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
