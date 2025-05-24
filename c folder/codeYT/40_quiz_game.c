#include <stdio.h>
#include <ctype.h>

int main()
{
    char question[][100]={"1.What is this letter (i)?",
                          "2.What is this number (2)?",
                          "3.What is this symbol (?)?"};

    char option[][100]= {"A. j", "B. c", "C. i", "D. o",

                       "A. 2", "B. 3", "C. 4", "D. 5",

                       "A. #", "B. ?", "C. -", "D. +",};
    
   
    char answers[3]= {'C','A','B'};

    int numberofQuestions= sizeof(question)/ sizeof(question[0]);

    char guess= ' ';
    int scores= 0;

    printf("\nQuiz Game");

    for(int i=0; i<numberofQuestions; i++)
    {
        printf("\n%s", question[i]);
        printf("\n----------------------------------|");
        
        for(int j=(i * 4); j<(i * 4)+ 4; j++)
    {
        printf("\n%s", option[j]);
    }
        printf("\nguess:");
        scanf("%c", &guess);
        scanf("%*c");
        guess = toupper(guess);

        if(guess == answers[i])
        {
            printf("\nCorrect");
            scores++;
        }
        else{
            
            printf("\nWRONG");
        }
    }
    printf("\n|---------------------|");
    printf("\n| Final Score: %d/%d    |", scores, numberofQuestions);
    printf("\n|---------------------|");

    return 0;
}