#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NO_OF_GUESSES 5

int main()
{
    int random_number = 0;
    int input_number = 0;
    int guess_counter = 0;
    int guess_left = 0;

    time_t t;

    srand((unsigned) time(&t));     // initialize random number generator
    random_number = rand() % 21;    // generate the random number

    printf("Guess a number from 0 to 20: ");

    for (guess_counter=0; guess_counter<NO_OF_GUESSES; ++guess_counter)
    {
        scanf("%d", &input_number);

        if (random_number == input_number)
        {
            printf("Corect!\n");
            break;
        }
        else if (input_number < random_number && input_number > -1)
            printf("Too low!\n");
        else if (input_number > random_number && input_number < 21)
            printf("Too high!\n");
        else
            printf("Error input\n");

        guess_left = NO_OF_GUESSES - guess_counter - 1;

        if (guess_counter < 4)
            printf("%d tr%s left. Try again: ", guess_left, 
                                                guess_left == 1 ? "y": "ies");
    }
    
    return 0;
}