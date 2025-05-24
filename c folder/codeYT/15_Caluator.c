#include <stdio.h>
int main(){

    char operator;
    double num1;
    double num2;
    double result;

    printf("\nEnter an operator(+ - * /):");
    scanf("%c", &operator);

    printf("\nEnter num1:");
    scanf("%lf", &num1);

    printf("\nEnter num2:");
    scanf("%lf", &num2);

    switch (operator)
    {
    case '+'/* constant-expression */:
    result = num1 + num2;    /* code */
    printf("Result: %.2lf", result);
    break;

    case '-'/* constant-expression */:
    result = num1 - num2;    /* code */
    printf("Result: %.2lf", result);
    break;

    case '*'/* constant-expression */:
    result = num1 * num2;    /* code */
    printf("Result: %.2lf", result);
    break;

    case '/'/* constant-expression */:
    result = num1 / num2;    /* code */
    printf("Result: %.2lf", result);
    break;
    
    default:
    printf("%c is not valid operator");
        break;
    }

   return 0; 
}