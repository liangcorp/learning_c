#include <stdio.h>

// find the greatest common divisor
int greatest_common_divisor(int x, int y)
{
    int i, gcd;
    int lesser_no = (x < y) ? x : y;

    for (i=1; i<= lesser_no; i++)
    {
        if (y % i == 0 && x % i == 0)
            gcd = i;
    }
    return gcd;
}

// Calculate the absolute value of a number
float absolute_value(float f)
{
    if (f < 0)
        return -f;
    else
        return f;
}

// Compute the square root of a number
float square_root(float f)
{
    int i;

    for (i = 1; i<f; i++)
        if( i * i == f)
            return i;

    return 0;
}

int main(void)
{
    int x, y;
    float f, result;

    printf("Enter two non-negative integers: ");
    scanf("%d %d", &x, &y);

    if (x < 0 || y < 0)
    {
        printf("x and y can't be negative\n");
        return 1;
    }
    result = (float)greatest_common_divisor(x, y);

    printf("The greatest common divisor "
            "between %d and %d is %0.2f\n", x, y, result);
    
    printf("Enter a float number: ");
    scanf("%f", &f);
    printf("Absolute number of %.2f is %.2f\n", f, absolute_value(f));

    f = 0;
    printf("Enter a number: ");
    scanf("%f", &f);
    result = square_root(f);
    
    if(result != 0)
        printf("The squre root of %0.2f is %0.2f\n", f, result);
    else
        printf("Can not find the square root of %0.2f\n", f);
    
    return 0;
}