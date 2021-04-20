#include <stdio.h>

int factorial (int n)
{
    int result = 0;

    if (n == 0)
        result = 1;
    else
        result = n * factorial(n - 1);
    /* 
        e.g. n = 3
            result = 3 * factorial(3 - 1)
                         result = 2 * factorial(2 - 1)
                                      result = 1 * factorial(1 - 1)
                                                   result = 1
            result = 3 *         (2 *         (1 *         (1)))
     */
    return result;
}

int main(void)
{
    int j = 0;

    for (j = 0; j < 8; j++)
        printf("%d! = %d\n", j, factorial(j));

    return 0;
}