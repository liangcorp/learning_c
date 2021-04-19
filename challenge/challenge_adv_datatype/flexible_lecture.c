#include <stdio.h>
#include <malloc.h>

struct my_array
{
    int len;
    int array[];
};

int main(void)
{
    struct my_array *m = NULL;

    int array_size = 0;

    printf("Enter size of the array: ");
    scanf("%d", &array_size);

    m = malloc(sizeof(struct my_array) + array_size * sizeof(int));

    m->len = array_size;
    m->array[0] = 55;
    m->array[1] = 199;
    
    printf("array is %d:$d\n", m->array[0], m->array[1]);
    
    return 0;
}