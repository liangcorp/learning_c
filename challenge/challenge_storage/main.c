#include <stdio.h>

int num = 0;

void display(void);

int main(void)
{
    int i;
    for(i=0; i<5; i++)
    {
        display();
    }
    printf("\n");
    return 0;
}