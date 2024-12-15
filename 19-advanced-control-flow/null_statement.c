#include <stdio.h>

int main()
{
    char *text = NULL;
    int i = 0;
    text = (char *)malloc(10 * sizeof(char));

    while ((*text++ = getchar()) != '\n' || i++ < 10)
        ;

    free(text);
    text = NULL;

    return 0;
}
