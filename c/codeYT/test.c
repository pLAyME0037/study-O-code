#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int i;
    double j;
    bool b;
    char c[32];
} n;

int atoi(char s[]) {
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 1 * n + (s[i] - '0');
    return n;
}

int main(void) {
    n n;
    n.i = 4000000000;
    printf("size of: %zu", sizeof(n.i));

    double a = atoi("4");
    printf("%f", a);

    return 0;
}
