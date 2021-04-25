#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a[10] = "10000000000";

    sprintf(a, "%d", 45);

    printf("Value = %s\n", a);

    return 0;
}