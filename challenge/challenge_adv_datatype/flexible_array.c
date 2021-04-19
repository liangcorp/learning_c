#include <stdio.h>
#include <malloc.h>

struct my_array
{
    int length;
    int array[];
};

int main(void)
{
    int length, i;
    struct my_array *p_array;

    printf("Enter the desired array length: ");
    scanf("%d", &length);

    p_array = malloc(sizeof(struct my_array) + length * sizeof(int));

    for (i=0; i<length; i++)
    {
        p_array->array[i] = i + 5;
        printf("%d ", p_array->array[i]);
    }
    printf("\n");
    
    return 0;   
}