#include <stdio.h>

int main()
{
    int grades[10];
    int count = 10;
    long sum = 0;
    float average = 0.0F;

    printf("\nEnter the 10 grades:\n");

    int i;  //  Declared outside for C89
    for (i = 0; i < count; i++) {
        printf("%2u>  ", i + 1);
        scanf("%d", &grades[i]);
        sum += grades[i];
    }

    average = (float)sum / count;

    printf("Average of the the grades entered is %.2f\n", average);

    return 0;
}
