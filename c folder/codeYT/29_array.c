#include <stdio.h>

int main()
{
    double prices[] = {5.0, 9.0, 7.9, 6.5, 4.0, 10.0, 8.34};

    //printf("$%.2lf", prices[2]);

    //printf("%d bytes\n", sizeof (prices));    //48 bytes

    /*
    for(int i = 0; i < i < 6; i++)
    {
        printf("$%.2lf", prices[i]);
    }
    */
   
    for(int i = 0; i < sizeof (prices)/sizeof(prices[0]); i++)
    {
        printf("$%.2lf\t", prices[i]);
    }
    return 0;
}