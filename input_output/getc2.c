#include <stdio.h>

int main(void)
{
    char ch = '\0';

    ch = getc(stdin);

    printf("Read in character %c\n", ch);

    return 0;
}
