#include <stdio.h>

void display(void)
{
    extern int counter;
    counter++;

    printf("%d\n", counter);
}
