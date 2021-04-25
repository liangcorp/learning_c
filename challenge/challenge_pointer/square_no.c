#include <stdio.h>

void square(int * const n)
{
    *n = *n * *n;
}

int main(void)
{
    int n  = 10;
    square(&n);

    printf("Squared number is %d\n", n);
}
