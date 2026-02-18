#define OLIVE_IMPLEMENTATION
#include "olive.c"
#include "test.c"

void sort_tri_point_by_y(int *x1, int *y1,
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
void olivec_draw_triangle(uint32_t *pixels, size_t width, size_t height, 
                          int x1, int y1,
                          int x2, int y2,
                          int x3, int y3,
                          uint32_t color) {
    sort_tri_point_by_y(&x1, &y1,
                        &x2, &y2,
                        &x3, &y3);
}

int main(void) {
    int x1 = 50,  y1 = 1;
    int x2 = 150, y2 = 2;
    int x3 = 850, y3 = 3;
    sort_tri_point_by_y(&x1, &y1, &x2, &y2, &x3, &y3);
    printf("x1 = %d, y1 = %d\n", x1, y1);
    printf("x2 = %d, y2 = %d\n", x2, y2);
    printf("x3 = %d, y3 = %d\n", x3, y3);

    /* if (! checkerEx()) return -1; */
    /* if (! circleEx()) return -1; */
    /* if (! lineEx()) return -1; */

    return 0;
}
