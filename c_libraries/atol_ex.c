#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a[10] = "10000000000000";
    long value = atol(a);

    printf("Value = %l\n", value);

    return 0;
}