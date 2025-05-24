#include <stdio.h>
int main(){

    char grade;
    printf("Enter a letter of ur grade: ");
    scanf("%c", &grade);

    switch(grade)
    {
        case 'A':
        printf("\nPerfect");
        break;

        case 'B':
        printf("\nGood");
        break;

        case 'C':
        printf("\nokay");
        break;

        case 'D':
        printf("\naverage");
        break;
        
        case 'E':
        printf("\nstill winning");
        break;

        case 'F':
        printf("\nYou fail");
        break;
        
        default:
        printf("Enter only valid grade");
    }
    return 0;
}