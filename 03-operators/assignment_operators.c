#include <stdio.h>

int main()
{
    int a = 0;
    int b = 1;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    a = b;
    printf("a = b; a = %d\n", a);

    a += 1;
    printf("a += 1; a = %d\n", a);

    a -= 1;
    printf("a -= 1; a = %d\n", a);

    a *= 2;
    printf("a *= 2; a = %d\n", a);

    a /= 2;
    printf("a /= 2; a = %d\n", a);

    a %= 2;
    printf("a %%= 2; a = %d\n", a);

    a <<= 2;
    printf("a <<= 2; a = %d\n", a);

    a >>= 2;
    printf("a >>= 2; a = %d\n", a);

    a &= 2;
    printf("a &= 2; a = %d\n", a);

    a ^= 2;
    printf("a ^= 2; a = %d\n", a);

    a |= 2;
    printf("a |= 2; a = %d\n", a);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);

    return 0;
}
