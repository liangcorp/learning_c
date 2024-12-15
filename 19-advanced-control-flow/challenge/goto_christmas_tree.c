#include <stdio.h>
#include <string.h>

int main()
{
	int i = 0;
	int j = 0;
	char star[] = { '*', '*', '*', '*', '*', '*', '*', '*', '*' };

instruction_start:
	if (i == strlen(star) / 2 - 1)
		goto end;
	j = 0;
	i++;

line_beginning:
	if (j < 9) {
		if (4 - i + 1 == j || 4 + i - 1 == j)
			printf("*");
		else
			printf(" ");
		j++;
		goto line_beginning;
	}

	printf("\n");
	goto instruction_start;

end:
	printf("%s\n", star);

	return 0;
}
