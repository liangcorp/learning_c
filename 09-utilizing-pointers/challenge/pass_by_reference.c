#include <stdio.h>

void square(int *const p_x)
{
    *p_x = (*p_x) * (*p_x);
}

int main()
{
    int x = 10;

    printf("x is %d\n", x );

    square(&x);

    printf("square of x is %d", x);

    return 0;
}
