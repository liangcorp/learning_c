#include <stdio.h>

int main(void)
{
    void *pv_data = NULL;   // void pointer
    int *i_data = NULL;     // integer pointer
    char *c_data = NULL;    // character pointer
    float *f_data = NULL;   // float pointer

    // size of void pointer
    printf("size of void pointer = %d\n\n", sizeof(pv_data));

    // size of integer pointer
    printf("size of integer pointer = %d\n\n", sizeof(i_data));
    
    // size of character pointer
    printf("size of character pointer = %d\n\n", sizeof(c_data));

    // size of float pointer
    printf("size of float pointer = %d\n\n", sizeof(f_data));

    return 0;
}