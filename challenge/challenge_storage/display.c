#include <stdio.h>

extern int num;

void display(void)
{
    num++;
    printf("%d ", num);
}
