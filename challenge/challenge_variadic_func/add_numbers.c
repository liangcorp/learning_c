#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double adding_numbers_fix_count(int count, ...)
{
    int i;
    double num = 0.0;
    double sum = 0.0;

    va_list args1;
    va_start(args1, count);

    for (i = 0; i < count; i++)
    {
        num = va_arg(args1, double);
        sum += num;
    }

    va_end(args1);

    return sum;
}

double add_numbers_fix_last(double num1, double num2, ...)
{
    double num = 0;
    double sum = num1 + num2;

    va_list args;
    va_start(args, num2);

    while ((num = va_arg(args, double)) != 0.0)
    {
        sum += num;
    }

    return sum;
}

double get_diff_max_min(int count, ...)
{
    int i;
    double min, max, temp;

    va_list args1;
    va_start(args1, count);

    va_list args2;
    va_copy(args2, args1);

    min = va_arg(args1, double);
    max = va_arg(args2, double);

    // the first argument has already passed to min and max
    for (i = 0; i < (count - 1); i++)
    {
        temp = va_arg(args1, double);
        if (min > temp)
            min = temp;
    }

    for (i = 0; i < (count - 1); i++)
    {
        temp = va_arg(args2, double);
        if (max < temp)
            max = temp;
    }

    va_end(args1);
    va_end(args2);

    return (max - min);
}

int main(void)
{
    double sum = 0;

    sum = adding_numbers_fix_count(3, 3.0, 4.0, 5.5);

    printf("Sum of 3, 4 and 5.5 is %.2lf\n", sum);

    sum = add_numbers_fix_last(3.4, 4.3, 2.5, 3.1, 0.0);
    printf("Sum of 3.4, 4.3, 2.5 and 3.1 is: %.2lf\n", sum);

    printf("Difference between maxium and minium number ");
    printf("of 2.3, 5.6, 99.9 and 54.6 is %.2lf\n",
                        get_diff_max_min(4, 2.3, 5.6, 99.9, 54.6));

    return 0;
}
