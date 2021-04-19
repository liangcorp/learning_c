#include <stdio.h>

int i = 5;

struct date
{
	int year;
	int month;
	int day;
};

struct date today;

void foo(void);

int main(void)
{
	printf("%i    ", i);
	foo();
	printf("%i\n", i);

	return 0;
}
