#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void)
{
    double complex z1 = I * I;  // imaginary unit squared
    printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));

    double _Complex z2 = pow(I, 2);
    printf("pow(I, 2) = %.1f%+.1fi\n", creal(z2), cimag(z2));

    double PI = acos(-1);
    double complex z3 = exp(I * PI);    // Euler's formula
    printf("exp(I*PI = %.1f%+.1fi\n", creal(z3), cimag(z3));

    double complex z4 = 1 + 2*I;
    double complex z5 = 1 - 2*I;
    printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z4 * z5), cimag(z4 * z5));
    return 0;
}

