#include <stdio.h>

int main(){

    int rows;
    int columns;
    char symbol;

    printf("\nEnter # of rows: ");
    scanf("%d", &rows);

    printf("Enter # of columns: ");
    scanf("%d", &columns);

    scanf("%c");

    printf("Enter a symbol: ");
    scanf("%c", &symbol);

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            //printf("%d", j);
            printf("%c", symbol);
        }
    printf("\n");
    }

    return 0;
}