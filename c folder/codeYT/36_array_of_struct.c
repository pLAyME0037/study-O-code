#include <stdio.h>

struct student
{
    char name[12];
    float gpa;
};

int main()
{
    struct student student1={"Apple", 3.0};
    struct student student2={"Banana", 3.2};
    struct student student3={"Grape", 2.5};
    struct student student4={"Pineapple", 2.0};

    struct student student[]={student1,student2,student3,student4};

    for(int i=0; i<sizeof(student)/ sizeof(student[0]); i++)
    {
        printf("\nname=%-12s", student[i].name);
        printf("\ngpa=%.2f", student[i].gpa);
        printf("\n================||");
    }

    return 0;
}
