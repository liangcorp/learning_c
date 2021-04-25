#include <stdio.h>

int main(void)
{
    int ch = 0;

    while ((ch = gerchar()) != EOF)
        printf("%c\n", ch);

    return 0;
}
