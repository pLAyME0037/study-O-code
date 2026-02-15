#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "olive.c"

#define WIDTH 800
#define HEIGHT 600

#define COLS (8*2)
#define ROWS (6*2)
#define CELL_WIDTH  (WIDTH/COLS)
#define CELL_HEIGHT (HEIGHT/ROWS)

#define BACKGROUND_COLOR 0xFF202020
#define FOREGROUNG_COLOR 0x6495EDFF

static uint32_t pixels[WIDTH*HEIGHT];

float lerpf(float a, float b, float t) {
    return a + (b - a) * t;
}

bool checkerEx(void) {
    olivec_fill(pixels, WIDTH, HEIGHT, BACKGROUND_COLOR);

    for (int x = 0; x < COLS; ++x) {
        for (int y = 0; y < ROWS; ++y) {
            uint32_t color = BACKGROUND_COLOR;
            if ((x + y) % 2 == 0) {
                color = 0xFF0000FF;
            }
            olivec_fill_rect(pixels, WIDTH, HEIGHT,
                             x*CELL_WIDTH, y*CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT,
                             color);
        }
    }

    const char *file_path = "checker_example.ppm";
    Errno err = olivec_save_to_ppm_file(pixels, WIDTH, HEIGHT, file_path);
    if (err) {
        fprintf(stderr, "ERROR: could not save file %s: %s\n", file_path, strerror(errno));
        return false;
    }
    return true;
}

bool circleEx(void) {
    olivec_fill(pixels, WIDTH, HEIGHT, BACKGROUND_COLOR);

    for (int x = 0; x < COLS; ++x) {
        for (int y = 0; y < ROWS; ++y) {
            float u = (float) x/COLS;
            float v = (float) y/ROWS;
            float t = (float) (u + v)/2;

            size_t radius = CELL_WIDTH;
            if (CELL_HEIGHT < radius) radius = CELL_HEIGHT;
            int cx = x*CELL_WIDTH + CELL_WIDTH/2;
            int cy = y*CELL_HEIGHT + CELL_HEIGHT/2;
            olivec_fill_circle(pixels, WIDTH, HEIGHT,
                               cx, cy, 
                               (size_t) lerpf(radius/4, radius/2, t),
                               FOREGROUNG_COLOR);
        }
    }

    const char *file_path = "circle.ppm";
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

    return 0;
}
