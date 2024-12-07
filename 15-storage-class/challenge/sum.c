#include <stdio.h>

int sum(int num)
{
    static int sum = 0;
    sum += num;

    return sum;
}

int main()
{
    printf("%d\n", sum(25));
    printf("%d\n", sum(35));
    printf("%d\n", sum(45));

    return 0;
}
