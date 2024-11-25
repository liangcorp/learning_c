#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NO_GUESSES 5

int main()
{
	time_t t;
	srand((unsigned)time(&t));

	int i;
	int input = 0;
	int random = rand() % 21;

	for (i = 0; i < MAX_NO_GUESSES; i++) {
		printf("You have %d guess%s left.\n", 5 - i,
		       (5 - i) == 1 ? "" : "es");
		printf("Enter a guess: ");
		scanf("%d", &input);

		if (input == random) {
			printf("Congraulations. You guessed it!\n");
			break;
		} else if (input < 0 || input > 20) {
			printf(" I said the number is between 0 and 20\n");
		} else if (input < random) {
			printf("Sorry, %d is wrong. My number is higher than that.\n\n",
			       input);
		} else {
			printf("Sorry, %d is wrong. My number is less than that.\n\n",
			       input);
		}
	}

	return 0;
}
