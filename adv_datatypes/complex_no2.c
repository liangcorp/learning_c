#include <stdio.h>
#include <complex.h>
#include <math.h>

#define __STDC_WANT_LIB_EXT1__ 1

int main(void)
{
    #ifdef __STDC_NO_COMPLEX__
        printf("Complex numbers are not supported.\n");
        exit 1;
    #else
        printf("Complex numbers are supported.\n");

        double complex a = 32.123 + 24.456 * I;
        double complex b = 23.789 + 42.987 * I;
        double complex c = 3.0 + 2.0 * I;

        double complex sum = a + b;
        double complex pwr = cpow(a, c);    // Perform complex exponentiation

        printf("a is %f + %fi\n", creal(a), cimag(a));
        printf("b is %f + %fi\n", creal(b), cimag(b));

        printf("a + b is: %f + %fi\n", creal(sum), cimag(sum));
        printf("a - b is: %f + %fi\n", creal(a - b), cimag(a - b));
        printf("a * b is: %f + %fi\n", creal(a * b), cimag(a * b));
        printf("a / b is: %f + %fi\n", creal(a / b), cimag(a / b));
        printf("a ^ b is: %f + %fi\n", creal(pwr), cimag(pwr));
    #endif

    return 0;
}