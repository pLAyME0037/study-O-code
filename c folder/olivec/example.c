#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#define OLIVE_IMPLEMENTATION
#include "olive.c"
#include "test.c"

int main(void) {
    if (! checkerEx()) return -1;
    if (! circleEx()) return -1;
    if (! lineEx()) return -1;
    if (! fill_triangle()) return -1;

    return 0;
}
