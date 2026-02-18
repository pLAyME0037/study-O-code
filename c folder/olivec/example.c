#include "test.c"

#include "test.h"
#define WIDTH 800
#define HEIGHT 600

#define COLS (8)
#define ROWS (6)
#define CELL_WIDTH  (WIDTH/COLS)
#define CELL_HEIGHT (HEIGHT/ROWS)

#define BACKGROUND_COLOR 0xFF202020
#define FOREGROUND_COLOR 0x6495EDFF

static uint32_t pixels[WIDTH*HEIGHT];

int main(void) {
    if (! checkerEx()) return -1;
    if (! circleEx()) return -1;
    if (! lineEx()) return -1;

    return 0;
}
