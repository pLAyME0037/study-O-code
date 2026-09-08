#include <math.h>
#include <string.h>

#define LERPF(a, b, t) ((1 - (t)) * (a) + (t) * (b))
#define TWO_PI         6.28318530717958647692

typedef struct {
    float (*func)(float x, void* data);
    void  *data;
} instrument_t;

float func_sine(float x, void *data) {
    (void)data;
    return sinf(x*TWO_PI);
}

float func_square(float x, void *data) {
    float *p = (float *)data;
    x = x - floorf(x);
    if (x <= *p) return 1;
    return -1;
}

float func_saw_tooth(float x, void *data) {
    float *p = data;
    if (*p <= 0.0) *p = 0.0001;
    if (*p >= 0.9) *p = 0.9999;
    x = x - floorf(x);
    if (x <= *p) {
        return LERPF(-1, 1, x / *p);
    }
    return LERPF(1, -1, (x - *p)/(1 - *p));
}

instrument_t instrument_sine(void) {
    return (instrument_t) {
        .func = func_sine,
        .data = NULL
    };
}

instrument_t instrument_square(void) {
    static float data = 0.5;
    return (instrument_t) {
        .func = func_square,
        .data = &data
    };
}

instrument_t instrument_saw_tooth() {
    static float data = 0.25;
    return (instrument_t) {
        .func = func_saw_tooth,
        .data = &data
    };
}

float instrument_run(instrument_t instrument, float x) {
    return instrument.func(x, instrument.data);
}

