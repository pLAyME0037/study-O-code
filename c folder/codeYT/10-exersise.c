#include <stdio.h>
int main(){

    const double PI = 3.14159;
    double radious;
    double circumference;

    printf("\nEnter the radious of a circle:");
    scanf("%lf", &radious);

    circumference = 2 * PI * radious;

    printf("\nCircumference: %lf", circumference);

    return 0;
}