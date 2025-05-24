#include <stdio.h>
void birthday(char x[], int y){

    printf("Happy birthday dear %s!\n", x);
    printf("You are now %d years old.", y);
}
int main(){

    char name[]="mean";
    int age=19;

    birthday(name, age);

    return 0;
}