#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i;
    srand(time(0));

    for (i = 0; i < 10; i++)
    {
        printf(" %d ", rand());
    }

    printf("\n");

    return 0;
}
