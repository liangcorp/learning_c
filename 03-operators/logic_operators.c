#include <stdio.h>

int main()
{
    _Bool a = 1;
    _Bool b = 0;
    _Bool c = 1;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    printf("a && b = %d\n", a && b);
    printf("a || b = %d\n", a || b);
    printf("a ^ b = %d\n", a ^ b);
    printf("a ^ c = %d\n", a ^ c);
    printf("!a = %d\n", !a);

    return 0;
}
