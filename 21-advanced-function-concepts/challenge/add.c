#include <stdio.h>
#include <stdarg.h>

long sum(int count, ...)
{
    va_list args;
    long sum = 0L;
    int value = 0;
    int i;

    va_start(args, count);

    for (i = 0; i < count; i++) {
        value = va_arg(args, int);
        sum += value;
    }

    va_end(args);

    return sum;
}

int main()
{
    printf("%ld\n", sum(2, 10, 20));
    printf("%ld\n", sum(3, 10, 20, 30));
    printf("%ld\n", sum(4, 10, 20, 30, 40));

    return 0;
}
