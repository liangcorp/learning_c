#include <stdio.h>

int find_gcd(int num1, int num2);

int main(void)
{
    int num1 = 0;
    int num2 = 0;
    int gcd = 0;

    printf("Input 1st number: ");
    scanf("%d", &num1);

    printf("Input 2nd number: ");
    scanf("%d", &num2);

    gcd = find_gcd(num1, num2);

    printf("The GCD of %d and %d is: %d\n\n", num1, num2, gcd);

    return 0;
}

int find_gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            return find_gcd(a - b, b);
        else
            return find_gcd(a, b - a);
    }

    return a;
}
