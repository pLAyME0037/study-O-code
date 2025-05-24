#include <stdio.h>
int main(){

    int age;
    char name[25];
    printf("What is your name?");
    scanf("%s", &name);

    printf("How old are you?");
    scanf("%d", &age);  //& - address of operator

    printf("\nHello %s. How are you?", name);
    printf("\ni am %d years old", age);

    return 0;
}