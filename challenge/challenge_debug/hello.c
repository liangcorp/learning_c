#include <stdio.h>

/*
 * Compile with gcc with different flags
 *
 *  -g
 *
 *  -c
 *
 *  -o
 *
 *  -D DEBUG
 *
 *  -Wall
 *
 *  -Werror
 *
 */

int main(void)
{
	int i;
	#ifdef DEBUG
		printf("Debug message.\n");
	#endif

	printf("Hello world.\n");
	
	return 0;
}
