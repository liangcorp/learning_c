#include <stdio.h>
#include <malloc.h>

struct my_array {
    int length;
    int array[];
};

int main()
{
    int length = 0;
    int i = 0;
    struct my_array *a_ptr = NULL;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    a_ptr = malloc(sizeof(struct my_array) + length * sizeof(int));

    for (i = 0; i < length; i++) {
        printf("Input data for element %d: ", i + 1);
        scanf("%d", (a_ptr->array + i));
    }

    for (i = 0; i < length; i++) {
        printf("%d\n", *(a_ptr->array + i));
    }

    free(a_ptr);
    a_ptr = NULL;

    return 0;
}
