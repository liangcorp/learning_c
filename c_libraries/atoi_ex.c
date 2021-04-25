#include <stdio.h>

int atoi(char const *s);

int main(void)
{
    char a[10] = "100";
    int value = atoi(a);

    printf("Value = %d\n", value);

    return 0;
}