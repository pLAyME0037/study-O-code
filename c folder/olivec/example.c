#define OLIVE_IMPLEMENTATION
#include "olive.c"
#include "test.c"

void sort_tri_point_by_y(int *x1, int *y1,
                         int *x2, int *y2,
                         int *x3, int *y3) {
    if (&y1 > & y2) {
        OLIVEC_SWAP(int, &x1, &x2);
    }
}
void olivec_draw_triangle(uint32_t *pixels, size_t width, size_t height, 
                          int x1, int y1,
                          int x2, int y2,
                          int x3, int y3,
                          uint32_t color) {
    sort_tri_point_by_y(int x1, int y1,
                        int x2, int y2,
                        int x3, int y3);
}

int main(void) {
    if (! checkerEx()) return -1;
    if (! circleEx()) return -1;
    if (! lineEx()) return -1;

    return 0;
}
