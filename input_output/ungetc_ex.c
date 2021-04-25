#include <stdio.h>

int main(void)
{
    char ch = 0;
    while (isspace(ch = (char)getchar()));

    ungetc(ch, stdin);

    printf("char is %c\n", getchar());
    return 0;
}
