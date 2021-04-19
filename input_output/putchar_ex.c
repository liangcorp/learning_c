#include <stdio.h>

int main(void)
{
    char string[] = "Helo Jason, \nwhatever!";
    int i = 0;

    while (string[i] != '\0')
    {
        if (string[i] != '\n')
            putchar(string[i]);
        i++;
    }
    printf("\n");

    return 0;
}