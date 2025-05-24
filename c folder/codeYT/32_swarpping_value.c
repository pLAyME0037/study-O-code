#include <stdio.h>

int main()
{
    char x[15]= "water";    //[15] to avoid bugs and unequal value that tent to give unexpected error
    char y[15]= "soda";
    char temp[15];

    strcpy(temp, x); //x over to temp
    strcpy(x, y);
    strcpy(y, temp);

    printf("x= %s\n", x);
    printf("y= %s\n", y);

    return 0;
}