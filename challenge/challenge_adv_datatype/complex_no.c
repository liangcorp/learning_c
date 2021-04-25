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
        printf("Complex number is supported\n");
    #endif

    double complex a = 2.3 + 4.5 * I * I;
    printf("a is %.2f%+.2fi\n", creal(a), cimag(a));

    double complex b = 2.3 + 4.5 * pow(I, 2);
    printf("b is %.2f%+.2fi\n", creal(b), cimag(b));

    double complex c = cpow(I * acos(-1), acos(-1));
    printf("c is %.2f%+.2fi\n", creal(c), cimag(c));

    double complex d = 1 + 2 * I;
    double complex e = conj(d);

    printf("Conjugate of %.2f%+.2fi is %.2f%+.2fi\n", creal(d),
                                                          cimag(d),
                                                          creal(e),
                                                          cimag(e));

    return 0;
}
