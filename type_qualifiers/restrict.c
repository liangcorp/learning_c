#include <stdio.h>
#include <malloc.h>

int main(void)
{
    int n;
    int array[10];

    int * restrict restar = (int *)malloc(10 * sizeof(int));
    int * par = array;

    for (n=0; n<10;n++)
    {
        par[n] += 5;
        restar[n] += 5;
        array[n] *= 2;
        par[n] += 3;
        restar[n] += 3;

        // void * memcpy(void * restrict s1, const void * restrict s2, size_t n);
        // void * memmove(void * s1, const void * s2, size_t n);
    }
}
