#include <stdio.h>

int main()
{
    // & = AND
    // | = OR
    // ^ = XOR
    // << = SHIFT LEFT
    // >> = SHIFT RIGHT

    int x = 6;  //00000110
    int y = 12; //00001100
    int z = 0;  //00000000

    z = x & y;
    printf("\nAND = %d", z);

    z = x | y;
    printf("\nOR = %d", z);

    z = x ^ y;
    printf("\nXOR = %d", z);

    z = x << 1 ;//2 //3 ...
    printf("\nSHIFT LEFT = %d", z);

    z = x >> 2 ;//3 //4 ....
    printf("\nSHIFT RIGHT = %d", z);

    return 0;
}