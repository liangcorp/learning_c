#include <stdio.h>

/* gcc -D DEBUG main.c -o main */

int process (int i, int j, int k)
{
    return i + j + k;
}

int main()
{
    int i, j, k, nread;

    nread = scanf("%d %d %d", &i, &j, &k);

#ifdef DEBUG
    fprintf(stderr, "Number of integers read = %d\n", nread);
    fprintf(stderr, "i = %d, j = %d, k = %d\n", i, j, k);
#endif

    printf("%d\n", process(i, j, k));

    return 0;
}
