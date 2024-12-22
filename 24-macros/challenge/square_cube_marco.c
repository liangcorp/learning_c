#include <stdio.h>

#define SQUARE(a) (a) * (a)
#define CUBE(a) (a) * (a) * (a)

int main()
{
	int a = 10;
	printf("Square and cube of %d are %d and %d\n", a, SQUARE(a), CUBE(a));
	return 0;
}
