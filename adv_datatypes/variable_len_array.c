#include <stdio.h>

int main(void)
{
    size_t size = 0;

    printf("Enter the number of elements you want to store: ");
    scanf("%zd", &size);

    float values[size];


    size_t rows = 0;
    size_t columns = 0;

    printf("Enter the number of rows: ");
    scanf("%zd", &rows);
    printf("Enter the number of columns: ");
    scanf("%zd", &columns);

    float beans[rows][columns];

    return 0;
}