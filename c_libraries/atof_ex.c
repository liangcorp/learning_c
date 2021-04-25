#include <stdio.h>

long int atof(char const *s);

int main(void)
{
    char a[10] = "3.14";
    float value = atof(a);

    printf("Value = %.2f\n", value);

    return 0;
}