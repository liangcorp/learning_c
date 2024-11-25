#include <stdio.h>

int main()
{
	int count = 1;

	while (count <= 5) {
		printf("%i\n", count);
		count++;
	}

	int number = 4;

	do {
		printf("\nNumber = %d", number);
		number++;
	} while (number < 4);

	return 0;
}
