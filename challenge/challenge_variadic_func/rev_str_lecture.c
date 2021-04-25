#include <stdio.h>

char* reverse(char *str);

int main(void)
{
    char str[100];
    char *rev = NULL;

    printf("Enter the string: ");
    scanf("%s", str);

    printf("The orginal string is: %s\n", str);
    rev = reverse(str);

    printf("The reverse string is: %s\n", rev);

    return 0;
}

char* reverse(char *str)
{
    static int i = 0;
    static char rev[100];

    if (*str != NULL)
    {
        reverse(str + 1);
        rev[i++] = *str;
    }

    return rev;
}
