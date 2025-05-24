#include <stdio.h>

int main()
{
    FILE * pF= fopen("C:\\Users\\mEAn\\Desktop\\Text Document.txt", "r");

    if(pF == NULL)
    {
        printf("Unable to open File\n");
    }
    else{
        while(fgets(buffer, 255, pF)!= NULL)
        {
            printf("\n%s", buffer);
        }
    }
    fclose(pF);

    return 0;
}