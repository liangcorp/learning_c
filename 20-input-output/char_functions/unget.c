#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch = '\0';

    while (isspace(ch = (char)getchar()));

    ungetc(ch, stdin);

    printf("char is %c\n", getchar());
    return 0;
}
