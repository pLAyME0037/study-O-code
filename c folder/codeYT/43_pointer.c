#include <stdio.h>

int main()
{
    char name[]= "bob";

    char * pName = name;    // * = indirection operator (value at address)
                            // pName = pointer name
    printf("\nAddress of name: %p", &name);
    printf("\nValue of name: %d", name);
    printf("\nSize of name: %d bytes", sizeof (name));

    printf("\n===============================");

    printf("\nValue of pName: %p", &pName);
    printf("\nValue at stored address(pName): %d", * pName);//dereferencing
    printf("\nSize of pName: %d bytes", sizeof (pName));

    return 0;
}