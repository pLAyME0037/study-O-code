#include <stdio.h>
int main(){

    /*format specifier % = defines and format a type of data in the displayed

     %c = charator
     %s = string (array of charators)
     %f = float
     %lf = double
     %d = intager

     %.1 = decimal persision
     %1 = minimum field width
     %- = left align
    */

    float Item1 = 5.00;
    float Item2 = 12.00;
    float Item3 = 150.00;

    printf("\nitem 1:$%8.2f", Item1);
    printf("\nitem 2:$%8.2f", Item2);
    printf("\nitem 3:$%8.2f", Item3);

    printf("\nitem 1:$%.2f", Item1);
    printf("\nitem 2:$%.2f", Item2);
    printf("\nitem 3:$%.2f", Item3);

    printf("\nitem 1:$%f", Item1);
    printf("\nitem 2:$%f", Item2);
    printf("\nitem 3:$%f", Item3);

    return 0;
}