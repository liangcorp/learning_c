#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char a[] = "123.456xyz";
    char *end = NULL;

    double value = 0;

    value = strtod(a, &end);

    printf("Value = %lf\n", value);

    return 0;
}