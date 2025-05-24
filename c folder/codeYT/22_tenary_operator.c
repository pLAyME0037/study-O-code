#include <stdio.h>
int findmax(int x , int y){
    
    return(x>y)? x:y;
}
int main()
{
    int max= findmax(7, 8);
    printf("%d", max);
    return 0;
}