#include <stdio.h>

void sort (int array[], int size)
//void sort (char array[], int size)
{
    for(int i= 0; i< size- 1; i++)
    {
        for(int j= 0; j< size- i- 1; j++)
        {
            if(array[j]> array[j+ 1])   // big >> small
            //if(array[j]< array[j+ 1]) // small >> big
            {
                int temp= array[j];
                array[j]= array[j+ 1];
                array[j+ 1]= temp;
            }   
        }
    }
}

void printArray(int array[], int size)
//void printArray(char array[], int size)

{
    for(int i= 0; i< size; i++)
    {
        printf("%d", array[i]);
        //printf("%c", array[i]);
    }
}
int main()
{
    //char array[] = {'B', 'F', 'A', 'D', 'C', 'E'};
    int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};

    int size= sizeof(array)/ sizeof(array[0]);

    sort (array, size);

    printArray (array, size); 

    return 0;
}