#include <stdio.h>

int main()
{
    //char a = 'x';   char b = 'z';   char c = 'y';

    //char a;   char b[3];

    short a = 'x';   short b = 'z';   short c = 'y';

    //int a = 'x';   int b = 'z';   int c = 'y';

    //double a = 'x';   double b = 'z';   double c = 'y';

    printf("\n%d bytes", sizeof (a));
    printf("\n%d bytes", sizeof (b));
    printf("\n%d bytes", sizeof (c));

    printf("\nAddress: %p", &a);
    printf("\nAddress: %p", &b);
    printf("\nAddress: %p", &c);

    return 0;
}