#include <stdio.h>
#include <string.h>

void reverse_string(char *str, size_t size)
{
    if (size > 0)
    {
        printf("%c", str[size - 1]);
        reverse_string(str, (size - 1));
    }
}

int main(void)
{
    char str[20];

    printf("Enter the string: ");
    scanf("%s", str);

    reverse_string(str, strlen(str));

    printf("\n");
    
    return 0;
}