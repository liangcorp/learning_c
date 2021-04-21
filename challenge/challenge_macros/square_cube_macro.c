/* 
    Author: Chen Liang
    Description: Write a C program to find the square and cube
                of a number using macros.
    Date: 21 Apr 2021
 */

#include <stdio.h>

#define SQUARE(x) (x) * (x)
#define CUBE(x) (x) * (x) * (x)

int main(void)
{
    double x = 0.0;

    printf("Enter a number: ");
    scanf("%lf", &x);

    printf("SQUARE(%.2lf) = %.2lf\n", x, SQUARE(x));
    printf("CUBE(%.2lf) = %.2lf\n", x, CUBE(x));

    return 0;
}
