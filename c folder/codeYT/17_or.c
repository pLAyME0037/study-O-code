#include <stdio.h>
#include <stdbool.h>
int main()
{
    float temp = 27;
    bool sunny = true;

    if(temp<=32 || temp<38 || sunny==true){
        printf("The weather is good.");
    }
    else{
        printf("The weather is bad.");
    }
    return 0;

}