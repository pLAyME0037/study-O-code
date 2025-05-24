#include <stdio.h>
#include <ctype.h>
int main()
{
    char unit;
    float temp;

    printf("\nIs the temperature in (C) or (F):");
    scanf("%c", &unit);

    unit = toupper(unit);   //for upper case

    if (unit == 'C'){

    printf("\nEnter the temperatuer in C:");
    scanf("%f", &temp);

    temp = (temp * 9 / 5) + 32;

    printf("\nThe temperature in Farenheit is:%f", temp);
    }
    else if (unit == 'F'){

    printf("\nEnter the temperatuer in F:");
    scanf("%f", &temp);

    temp = ((temp - 32)*5)/9;

    printf("\nThe temperature in Celsius is:%f", temp);
    }
    return 0;
}