#include <stdio.h>

int main(void)
{
    int *p_number = NULL;
    int number = 15;
    p_number = &number;

    printf("%d has the address %p\n", number, p_number);
}
