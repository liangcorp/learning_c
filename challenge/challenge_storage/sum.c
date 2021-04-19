#include <stdio.h>

int sum(int num)
{
    static int sum = 0;
    sum += num;

    return sum;
}

int main(void)
{
    printf("%d\n", sum(25));
    printf("%d\n", sum(15));
    printf("%d\n", sum(30));

    return 0;
}