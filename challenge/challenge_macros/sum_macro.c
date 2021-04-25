/* 
    Author: Chen Liang
    Description: Write a program that defines a macro that
                accepts two parameters and returns the sum
                of the give numbers
    Date: 21 Apr 2021
 */

#include <stdio.h>

#define SUM(X, Y) (X + Y)

int main(void)
{
    double x = 0;
    double y = 0;

    printf("Enter two numbers: ");
    scanf("%lf", &x);
    scanf("%lf", &y);

    printf("%.2lf + %.2lf = %.2lf\n", x, y, SUM(x, y));

    return 0;
}
