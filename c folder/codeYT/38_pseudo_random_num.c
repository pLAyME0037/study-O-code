#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); //srand - seed random

    int number1= (rand()%20)+1;
    int number2= (rand()%20)+1;
    int number3= (rand()%20)+1;

    printf("\t%d", number1);
    printf("\t%d", number2);
    printf("\t%d", number3);

    return 0;
}
