#define OLIVE_IMPLEMENTATION
#include "olive.c"
#include "test.c"

int main(void) {
    if (! checkerEx()) return -1;
    if (! circleEx()) return -1;
    if (! lineEx()) return -1;

    return 0;
}
