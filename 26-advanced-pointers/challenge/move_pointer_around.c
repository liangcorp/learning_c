#include <stdio.h>

int main()
{
    int num = 123;
    int *single_ptr = NULL;
    int **double_ptr = NULL;

    single_ptr = &num;
    double_ptr = &single_ptr;

    printf("%d\n", num);
    printf("%d\n", *single_ptr);
    printf("%d\n", **double_ptr);

    printf("%p\n", &num);
    printf("%p\n", single_ptr);
    printf("%p\n", *double_ptr);

    printf("%p\n", single_ptr);
    printf("%p\n", *double_ptr);

    printf("%p\n", &single_ptr);
    printf("%p\n", double_ptr);

    return 0;
}
