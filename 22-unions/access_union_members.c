#include <stdio.h>

union mixed {
	char c;
	float f;
	int i;
};

union number {
	int x;
	double y;
};

void foo(union number n)
{
	union number x = n;
}

int main()
{
	union number value;

	value.x = 100;
	printf("%d\n", value, x);
	printf("%d\n", value, y);

	value.y = 10.11;
	printf("%d\n", value, x);
	printf("%d\n", value, y);

	union mixed x;

	x.c = 'j';
	printf("%c\n", x.c);

	union number value = { 15 }; // only initilize first element
	union number value = { .x = 15 };

	union number x;
	union number *y = &x;

	y->x = 10;

	return 0;
}
