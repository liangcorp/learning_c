#include <stdio.h>

void sum(size_t size)
{
    int array[size], i, sum;
    sum = 0;

    for (i=0; i<size; i++)
    {
        printf("Enter the numbers: ");
        scanf("%d", &array[i]);
        sum += array[i];
    }

    printf("Sum is %d\n", sum);
}

int main(void)
{
    size_t size = 0;

    printf("Enter number of elements: ");
    scanf("%zd", &size);
    sum(size);

    return 0;
}
