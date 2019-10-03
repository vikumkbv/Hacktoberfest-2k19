#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int Guess=0;
    int RandomNo=0;
    int NumberOfGuess;
    time_t t;

    srand((unsigned) time(&t));

    RandomNo = rand() % 21;

    printf("This is a Guess the Number Game.\n");
    printf("You have to choose a number from 0 -20 to Guess the correct Number. \n");

    for(NumberOfGuess=5;NumberOfGuess>0;--NumberOfGuess)
    {
        printf("You have %d tr%s left.\n",NumberOfGuess,NumberOfGuess== 1 ? "y" :"ies");
        printf("Enter the Guess :\n");
        scanf("%d", &Guess);

        if(Guess==RandomNo)
        {
            printf("Congratulations! \nYou guessed it.\n");
            break;
        }
        else if (Guess < 0 || Guess > 20)
            printf("I said  number is from 0 to 20.\n");
        else if (Guess<RandomNo)
        printf("Sorry, but my number is greater than %d.\n",Guess);
        else if (Guess>RandomNo)
        printf("sorry, but my number is smaller than %d.\n", Guess);

    }
    if(Guess!=RandomNo)
    {
        printf("\nSorry you had 5 tries and you failed. The right number is %d.\n", RandomNo);

    }

    return 0;

}
