#include <stdint.h>
#include <stdbool.h>

// Define olive.c implementation
#define OLIVEC_IMPLEMENTATION
#include "olive.c"

// Struct matches the Dart struct exactly
typedef struct {
    float x;
    float y;
    float w;
    float h;
    uint32_t color; // AARRGGBB format
} RenderObject;

// Exported function for Dart FFI
__attribute__((visibility("default"))) __attribute__((used))
void render_frame(uint32_t* pixels, int width, int height, 
                  RenderObject* objects, int obj_count) {
    // 1. Setup olive.c canvas pointing to Dart's pixel buffer
    Olivec_Canvas oc = olivec_canvas(pixels, width, height, width);
    
    // 2. Clear background to dark gray
    olivec_fill(oc, 0xFF222222); 

    // 3. Draw all objects (Obstacles, Points, Player) provided by Dart
    for (int i = 0; i < obj_count; i++) {
        olivec_rect(oc,
                    (int)objects[i].y,
                    (int)objects[i].x,
                    (int)objects[i].w,
                    (int)objects[i].h,
                    objects[i].color);
    }
}
