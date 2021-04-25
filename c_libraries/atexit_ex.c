#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

int main(void)
{
	int n;

	atexit(sign_off);	/* register the sign_off() function */
	puts("Enter an integer: ");

	if (scanf("%d", &n) != 1)
	{
		puts("That's no integer!");
		atexit(too_bad);	/* register the too_bad() function */
		exit(EXIT_FAILURE);
	}

	return 0;
}

void sign_off(void)
{
	puts("in sign_off...\n");
}

void too_bad(void)
{
	puts("in too_bad...\n");
}