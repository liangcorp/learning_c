#include <stdio.h>
#include <stdlib.h>

#define DeclareSort(prefix, type) \
static int \
_DeclareSort_ ## prefix ## _Compare(const void *a, const void *b) \
{ \
    const type *aa; const type *bb; \
    aa = a; bb = b; \
    if (aa < bb) return -1; \
    else if (bb < aa) return 1; \
    else return 0; \
} \
\
void prefix ## _sort(type *a, int n)\
{ \
    qsort(a, sizeof(type), n, _DeclareSort_ ## prefix ## _Compare); \
}

#include <stdlib.h>

/* note: must appear outside of any function, and has no trailing space */

DeclareSort(int, int)

int main(int argc, char const *argv[])
{
    int x = 5;
    int *a = &x;
    int n = 6;
    int_sort(a, n);

    return 0;
}
