#include <stdio.h>

int main()
{
    // r= read
    // w= write
    // a= open

    FILE * pF= fopen("C:\\Users\\mEAn\\Desktop\\Text Document.txt", "w");

    fprintf(pF,"Apple Banana Grape");

    fclose(pF);

    return 0;
}