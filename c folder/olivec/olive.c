/* i learn this form Tsoding Daily */

#ifndef OLIVE_C_
#define OLIVE_C_

#include <stdint.h>
#include <stddef.h>

typedef int Errno;

void swap_int(int *a, int *b);
float lerpf(float a, float b, float t);
void olivec_fill(uint32_t *pixels, size_t width, size_t height, uint32_t color);
void olivec_fill_rect(uint32_t *pixels, size_t pixels_width, size_t pixels_height,
                      int x0, int y0, size_t w, size_t h,
                      uint32_t color);
void olivec_fill_circle(uint32_t *pixels, size_t pixels_width, size_t pixels_heigth,
                        int cx, int cy, int r,
                        uint32_t color);
void olivec_draw_line(uint32_t *pixels, size_t pixels_width, size_t pixels_height,
                      int x1, int y1, int x2, int y2,
                      uint32_t color);
Errno olivec_save_to_ppm_file(uint32_t *pixels, size_t width, size_t height, const char *file_path);
    
#endif /* ifdef OLIVE_C_ */

#ifdef OLIVE_IMPLEMENTATION
#undef OLIVE_IMPLEMENTATION

#include <stdio.h>
#include <errno.h>

void swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

float lerpf(float a, float b, float t) {
    return a + (b - a) * t;
}

void olivec_fill(uint32_t *pixels, size_t width, size_t height, uint32_t color) {

    for (size_t i = 0; i < width*height; ++i) {
        pixels[i] = color;
    }
}

#define RETURN_DEFER(value) do { result = (value); goto defer; } while (0)

Errno olivec_save_to_ppm_file(uint32_t *pixels, size_t width, size_t height, const char *file_path) {

    int result = 0;
    FILE *f = NULL;

    {
        f = fopen(file_path, "wb");
        if (f == NULL) { RETURN_DEFER(errno); }

        fprintf(f, "P6\n%zu %zu 255\n", width, height);
        if (ferror(f)) { RETURN_DEFER(errno); }

        for (size_t i = 0; i < width*height; ++i) {
            // 0xAABBGGRR
            uint32_t pixel = pixels[i];
            uint8_t bytes[3] = {
                (pixel>>(8*0))&0xFF,
                (pixel>>(8*1))&0xFF,
                (pixel>>(8*2))&0xFF,
            };
            fwrite(bytes, sizeof(bytes), 1, f);
            if (ferror(f)) RETURN_DEFER(errno);
        }
    }

defer:
    if (f) fclose(f);
    return result;
}

void olivec_fill_rect(uint32_t *pixels, size_t pixels_width, size_t pixels_height,
                      int x0, int y0, size_t w, size_t h,
                      uint32_t color) {
    for (int dy = 0; dy < (int) h; ++dy) {
        int y = y0 + dy;
        if (0 <= y && y < (int) pixels_height) {
            for (int dx = 0; dx < (int) w; ++dx) {
                int x = x0 + dx;
                if (0 <= x && x < (int) pixels_width) {
                    pixels[y*pixels_width + x] = color;
                }
            }
        }
    }
}

/**
 * @param pixels A pointer to the memory buffer representing image
 * @param pixels_width The total number of horizontal pixels in image
 * @param pixels_heigth	The total number of vertical pixels in image
 * @param cx, cy Center X and Y coords where the circle's middle sits 
 * @param r Radius 
 * @param color hex color value to fill the circle
 */
void olivec_fill_circle(uint32_t *pixels, size_t pixels_width, size_t pixels_heigth,
                        int cx, int cy, int r,
                        uint32_t color) {
    int x1 = cx - r; // Left Edge
    int x2 = cx + r; // Right Edge
    int y1 = cy - r; // Top Edge
    int y2 = cy + r; // Bottom Edge
    for (int y = y1; y <= y2; ++y) {
        if (0 <= y && y < (int) pixels_heigth) {
            for (int x = x1; x <= x2; ++x) {
                if (0 <= x && x < (int) pixels_width) {
                    int dx = x - cx;
                    int dy = y - cy;
                    if (dx*dx + dy*dy <= r*r) {
                        pixels[y*pixels_width + x] = color;
                    }
                }
            }
        }
    }
}

void olivec_draw_line(uint32_t *pixels, size_t pixels_width, size_t pixels_height,
                      int x1, int y1, int x2, int y2,
                      uint32_t color) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (dx != 0) {
        int c = y1 - ( dy*x1 )/dx;

        if (x1 > x2) swap_int(&x1, &x2);
        for (int x = x1; x <= x2; ++x) {
            if (0 <= x && x <= (int) pixels_width) {
                int sy1 = dy*x/dx + c;
                int sy2 = dy*(x + 1)/dx + c;
                if (sy1 > sy2) swap_int(&sy1, &sy2);
                for (int y = sy1; y <= sy2; ++y) {
                    if (0 <= y && y < (int) pixels_height) {
                        pixels[y*pixels_width + x] = color;
                    }
                }
            }
        }
    } else {
        int x = x1;
        if (0 <= x && x < (int) pixels_width) {
            if (y1 > y2) swap_int(&y1, &y2);
            for (int y = y1; y <= y2; ++y) {
                if (0 <= y && y < (int) pixels_height) {
                    pixels[y*pixels_width + x] = color;
                }
            }
        }
    }
}

#endif /* ifdef OLIVE_IMPLEMENTATION */
