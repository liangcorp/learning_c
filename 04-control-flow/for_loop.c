#include <stdio.h>

int main()
{
	int i; // declare outside for C89
	int j;

	// simple loop
	for (i = 0; i < 10; i++) {
		printf("i is %d\n", i);
	}

	// a bit more complicated loop
	for (i = 1, j = 2; i <= 5; i++, j += 2) {
		printf("\t%5d\n", i * j);
	}

	int sum = 0;

	// a lot more complicated loop
	for (i = 1; i < 10; sum += i++)
		;

	// infinite loop
	// for ( ;; )
	// {
	// }

	return 0;
}
