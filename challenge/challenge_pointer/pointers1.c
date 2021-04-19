#include <stdio.h>

int main(void)
{
    int number = 10;
    int *p_number = NULL;

    p_number = &number;

    printf("value stored in the pointer is %d\n", *p_number);
    printf("value of the pointer is %p\n", p_number);
    printf("address of the pointer is %p\n", &p_number);

    return 0;
}