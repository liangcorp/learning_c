#include <stdio.h>

int get_greateset_common_denominator(int n, int m, int gcd)
{
    if (gcd > 0)
        if (n % gcd == 0 && m % gcd == 0)
            return gcd;
        else
            gcd = get_greateset_common_denominator(n, m, (gcd - 1));

    return gcd;
}

int main(void)
{
    int n, m, gcd;

    printf("Input 1st number: ");
    scanf("%d", &n);
    printf("Input 2nd number: ");
    scanf("%d", &m);

    gcd = n < m? n : m;

    printf("The GCD of %d and %d is: %d\n", n, m,
                                get_greateset_common_denominator(n, m, gcd));

    return 0;
}
