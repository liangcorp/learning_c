#include <stdio.h>

int main()
{
    int number = 10;
    int *p_number = NULL;

    p_number = &number;

    printf("Address of p_number: %p", &p_number);
    printf("Value of the p_number: %p", p_number);
    printf("Value of the p_number pointing to: %d", *p_number);

    return 0;
}
