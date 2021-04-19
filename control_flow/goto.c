#include <stdio.h>

int main(void)
{
    const int max_input = 5;
    int i = 0;
    double number, average, sum;
    sum = 0.0;

    for (i=1; i<=max_input; i++)
    {
        printf("%d. Enter a number: ", i);
        scanf("%lf", &number);

        if (number < 0.0)
            goto jump;
        
        sum += number;
    }

    jump:
        average = sum / (i - 1);
        printf("Sum = %.2f\n", sum);
        printf("Average = %.2f", average);

    return 0;
}