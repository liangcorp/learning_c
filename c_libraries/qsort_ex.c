#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int data[5] = { 54, 3, 12, 9, 24 };
    int comp_ints(const void *, const void *);

    qsort(data, 5, sizeof(int), comp_ints);

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", data[i]);
    }

    return 0;
}

int comp_ints(const void *p1, const void *p2)
{
    const int i1 = * (const int *) p1;
    const int i2 = * (const int *) p2;

    return i1 - i2;
}