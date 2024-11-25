#include <stdio.h>

int main()
{
	int ch;

top:
	ch = getchar();

	if (ch != 'y')
		goto top;

	return 0;
}
