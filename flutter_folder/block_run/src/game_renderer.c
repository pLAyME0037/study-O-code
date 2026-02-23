#include <stdint.h>
#define OLIVEC_IMPLEMENTATION
#include "olive.c"

typedef struct {
    float x, y, w, h;
    uint32_t color;
} GameRenderObj;

void render_frame(uint32_t* pixels, int width, int height, 
                  GameRenderObj* objects, int obj_count) {
    if (pixels == NULL) return;

    Olivec_Canvas oc = olivec_canvas(pixels, width, height, width);
    
    // Clear with a very dark gray (Background)
    olivec_fill(oc, 0xFF181818); 

    for (int i = 0; i < obj_count; i++) {
        GameRenderObj obj = objects[i];
        
        // CLIP: 
        // Only draw if within reasonable screen bounds to prevent olivec crashes
        if (obj.y < -100 || obj.y > height + 100) continue;
        if (obj.x < -width || obj.x > width * 2) continue;

        olivec_rect(oc,
                    (int)obj.x,
                    (int)obj.y,
                    (int)obj.w,
                    (int)obj.h,
                    obj.color);
    }
}
