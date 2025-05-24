#include <stdio.h>

int main(){

    /* variable = Allocated space in memory a value.
                  We refer to a variable's name to access the stored value.
                  That variale now behaves as if it was the value it contains.
                  But we need to declare what type of data we are storing.  
    */
   int x = 100; //declaration + initialization
   int y; //declaration
   y = 200; // initialization

   int age = 21;        //integer
   float gpa = 3.50;    //flloating point number
   char grade = 'c';    //single charactors
   char name[] = "pME"; //array of charactors

   printf("Hello %s\n", name);
   printf("You are %d year old\n", age);
   printf("Your average geade is %c\n", grade);
   printf("Your gpa is %f\n", gpa);

   return 0;
}