#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int n)
{
    if (n == 1)
        return 1;

    return n + sum(n - 1);
}

int gcd(int a, int b)
{
    while (a != b) {
        if (a > b)
            return gcd(a - b, b);
        else
            return gcd(a, b - a);
    }
    return a;
}

char* reverse(const char *str)
{
    static int i = 0;
    static car rev[100];

    if (*str) {
        reverse(str + 1);
        rev[i++] = *str;
    }
    return rev;
}

int main()
{
    printf("sum of 1:%d is %d\n", 5, sum(5));
    printf("Greatest common denominator of %d and %d is %d\n", 10, 20, gcd(10, 20));
    printf("Greatest common denominator of %d and %d is %d\n", 3, 15, gcd(5, 15));

    char s[] = "hello";

    printf("reverse of %s is %s\n", s, reverse(s));

    return 0;
}
