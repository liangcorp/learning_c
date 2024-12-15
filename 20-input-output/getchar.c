#include <stdio.h>

int main()
{
    int ch = 0;
    //  Like getc without the input
    printf("%c\n", getchar());

    while ((ch = getchar() != EOF))
        printf("%c\n", ch);

	return 0;
}
