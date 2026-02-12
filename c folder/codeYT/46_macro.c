#include <stdio.h>
#include <stdlib.h>

#define SQUARE(x) x*x

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

#define REPORT_ERROR(msg) printf("Error in %s at line %d: %s\n", __FILE__, __LINE__, msg);

void clean() {
    system(CLEAR_SCREEN);
}

int main(int argc, char *argv[]) {
    clean();

    printf("%d\n", SQUARE(3));

    REPORT_ERROR("This is the test error");

    return 0;
}
