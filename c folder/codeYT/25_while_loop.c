#include <stdio.h>
#include <string.h>

int main()
{
    char name[25];

    printf("\nWhat s your name: ");
    fgets(name, 25, stdin);
    name[strlen(name)-1]='\0';

    while (strlen(name)==0)
    {
    printf("\nyou did not enter your name");/* code */
    printf("\nWhat s your name: ");
    fgets(name, 25, stdin);
    name[strlen(name)-1]='\0';
    }
    printf("Hello%s", name);

    return 0;
}