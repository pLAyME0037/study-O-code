#include <stdio.h>

typedef struct
{
    char name[25];
    char password[12];
    char ID[12];
}user;

int main()
{
    user user1={"Betty","password1","id123"};
    user user2={"Arcty","password2","id456"};

    printf("User 1 Name: %9s\n", user1.name);
    printf("User 1 Password: %9s\n", user1.password);
    printf("User 1 ID: %11s\n", user1.ID);

    printf("============================================");

    printf("\nUser 2 Name: %9s", user2.name);
    printf("\nUser 2 Password: %9s", user2.password);
    printf("\nUser 2 ID: %11s", user2.ID);

    return 0;
}