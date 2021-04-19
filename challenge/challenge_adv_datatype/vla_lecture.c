#include <stdio.h>

int main(void)
{
    int i;
    int sum = 0;
    int size = 0;
   
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter %d element in the array: ", size);

    for (i=0; i<size; i++)
        scanf("%d", &array[i]);

    for (i=0; i<size; i++)
        sum = sum + array[i];

    printf("Sum is %d\n", sum);

    return 0;
}