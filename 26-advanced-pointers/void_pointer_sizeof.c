#include <stdio.h>

int main()
{
    void *pv_data = NULL;
    int *i_data = NULL;
    char *c_data = NULL;
    float *f_data = NULL;

    printf("Size of void pointer = %d\n", sizeof(pv_data));
    printf("Size of integer pointer = %d\n", sizeof(i_data));
    printf("Size of character pointer = %d\n", sizeof(c_data));
    printf("Size of float pointer = %d\n", sizeof(f_data));

    return 0;
}
