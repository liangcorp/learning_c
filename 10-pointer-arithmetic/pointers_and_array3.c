#include <stdio.h>

int main(void)
{
    long multiple[] = { 15L, 25L, 35L, 45L };
    long *p = multiple;

    int i;

    for (i = 0; i < sizeof(multiple) / sizeof(multiple[0]); i++)
        printf("address p + %d (&multiple[%d]): %llu    *(p + %d) value: %ld\n", i, i, (unsigned long long)(p + i), i, *(p + i));

    printf("\n  Type long occupies: %d bytes\n", (int)sizeof(long));

    return 0;
}
