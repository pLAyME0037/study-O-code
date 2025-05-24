#include <stdio.h>
int main(){

    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age==100){
        printf("Congraturation? you lived for a cenury.");
    }
    else if(age==0){
        printf("Congraturation? you are 0.00 year old.");
    }
    else if(age>=18){
        printf("You are more than 18 years old.You are %d years old.", age);
        
    }
    else{
        printf("You are less than 18 years old.You are %d year(s) old.", age);
    }
    return 0;
}