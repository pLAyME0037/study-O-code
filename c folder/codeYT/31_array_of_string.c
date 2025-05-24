#include <stdio.h>
#include <string.h>

int main()
{
    char laptop[][10]={"acer","macbook","thinkpad","samsung"};

    strcpy(laptop[0], "LG");

    for(int i= 0; i< sizeof (laptop)/ sizeof (laptop[0]); i++)
    {
        printf("%s\n", laptop[i]);
    }

    return 0;
}