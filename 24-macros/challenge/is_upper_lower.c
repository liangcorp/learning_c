#include <stdio.h>

#define IS_LOWER(c) (c > 96 && c < 123)

#define IS_UPPER(c) (c > 64 && c < 91)

int main()
{
    char c = '\0';

    printf("Enter any character: ");
    scanf("%c", &c);

    if (IS_LOWER(c) == 1)
        printf("%c is lowercase\n", c);
    else if (IS_UPPER(c) == 1)
        printf("%c is uppercase\n", c);
    else
        puts("Entered character is not in the alphabet");

    return 0;
}
