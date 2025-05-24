#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MAX= 100;
    const int MIN=1;
    int guess;
    int guesses;
    int answer;

    //use the current time as the seed
    srand(time(0));
    //generate a random number between MIN and MAX
    answer= (rand()%MAX) + MIN;

    do{
        printf("\nEnter the guess: ");
        scanf("%d", &guess);

        if(guess>answer){
            printf("\nToo hight");
        }
        else if(guess<answer){
            printf("\nToo Low");
        }
        else{
            printf("\nCorrect");
        }
        guesses++;

    }while (guess != answer);

    printf("\nanswer: %d", answer);
    printf("\nguesses: %d", guesses);
 
    return 0;
}
//