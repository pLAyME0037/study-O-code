#include <stdio.h>
#include <math.h>

int main(){

    double A;
    double B;
    double C;

    printf("Enter Triangle AB:");
    scanf("%lf", &A);

    printf("Enter Triangle BC:");
    scanf("%lf", &B);

    C = sqrt(A * A + B * B);

    printf("Triangle AB is:%lf", C);

    return 0;


}