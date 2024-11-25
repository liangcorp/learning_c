#include <stdio.h>

int main()
{
	int number;
	int sign;

	printf("Please type in a number: ");
	scanf("%i", &number);

	if (number < 0)
		sign = -1;
	else if (number == 0)
		sign = 0;
	else
		sign = 1;

	printf("Sign = %i\n", sign);

	int y = 9;
	int x = y > 7 ? 25 : 50;

	if (y > 7)
		x = 25;
	else
		x = 50;

	printf("%d\n", x);

	return 0;
}
