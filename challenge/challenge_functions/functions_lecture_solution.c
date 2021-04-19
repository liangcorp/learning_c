#include <stdio.h>

int greatest_common_divisor(int u, int v);
float absolute_value(float x);
float square_root(float x);

int main()
{
    int x, y, error_code;
    float f, result;

    printf("Enter two non-negative integers: ");
    scanf("%d %d", &x, &y);

    if (x < 0 || y < 0)
    {
        printf("Input integers can't be negative\n");
    }
    else
    {
        result = (float)greatest_common_divisor(x, y);

        printf("The greatest common divisor "
            "between %d and %d is %0.2f\n", x, y, result);
    }

    printf("Enter a float number: ");
    scanf("%f", &f);
    printf("Absolute number of %.2f is %.2f\n", f, absolute_value(f));


    f = 0;
    printf("Enter a number: ");
    scanf("%f", &f);
    result = square_root(f);
    
    if(result != -1.0)
        printf("The squre root of %0.2f is %0.2f\n", f, result);
    else
        printf("Can not find the square root of %0.2f\n", f);

    return 0;
}

int greatest_common_divisor(int u, int v)
{
    int temp;

    while(v != 0)
    {
        temp = u % v;
        u = v;
        v = temp;
    }

    return u;
}

float square_root(float x)
{
    const float epsilon = 0.00001;
    float guess = 1.0;
    float return_value = 0.0;
    
    if (x < 0)
    {
        printf("Negative argument to square_root.\n");
        return_value = -1.0;
    }
    else
        while (absolute_value(guess * guess - x) >= epsilon)
        {
            guess = (x / guess + guess) / 2.0;
            return_value = guess;
        }            

    return return_value;
}

float absolute_value(float x)
{
    if (x < 0)
        x = -x;
    
    return x;
}