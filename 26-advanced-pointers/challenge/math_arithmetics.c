#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 6

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int* perform_operation(int *a, int *b, int size, int (*p_arithmetics)(int, int))
{
    int i;
    int *result = NULL;
    result = (int *) calloc(size, sizeof(int));

    for (i = 0; i < size; i++) {
        *(result + i) = p_arithmetics(*(a + i), *(b + i));
    }

    return result;
}

void display(int *array, int size)
{
    int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }

    printf("\n");
}

int main()
{
    int array1[] = {1, 2, 3, 4, 5, 6, 7};
    int array2[] = {1, 2, 3, 4, 5, 6, 7};

    char choice_number = '\0';
    int *result = NULL;

    while (choice_number != '5') {
        printf("Which operation do you want to perform?\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. None\n");
        printf("Enter choice: ");

        scanf(" %c", &choice_number);

        switch (choice_number) {
            case '1':
                result = perform_operation(array1, array2, SIZE, add);
                display(result, SIZE);
                break;
            case '2':
                result = perform_operation(array1, array2, SIZE, subtract);
                display(result, SIZE);
                break;
            case '3':
                result = perform_operation(array1, array2, SIZE, multiply);
                display(result, SIZE);
                break;
            case '4':
                result = perform_operation(array1, array2, SIZE, divide);
                display(result, SIZE);
                break;
            case '5':
                break;
            default:
                printf("Invalid option\n");
                break;
        }
        printf("\n");
    }

    free(result);
    result = NULL;

    return 0;

}
