#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;

    srand(time());

    for (i = 0; i < 10; i++)
        printf(" %d ", rand() % 5 + 1);

    printf("\n");

    return 0;
}
