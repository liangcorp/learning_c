#include <stdio.h>

int main()
{
    int count = 10;
    int x;
    int *int_ptr;

    int_ptr = &count;
    x = *int_ptr;

    printf("Address of count is %p\n", &count);
    printf("count = %i, x = %i\n", count, x);

    return 0;
}
