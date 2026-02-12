#include <stdio.h>

double square(double x);
 
int main() {
    double x = square(3.14);
    //printf("%.4lf", x);
    printf("%.2lf", x);
    return 0;
}

double square(double x) {
    return x*x;
}
