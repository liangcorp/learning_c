#include <stdio.h>
#include <complex.h>
#include <math.h>

int main()
{
    double complex dc = I * I;
    printf("dc = %.2f%+.2f\n", creal(dc), cimag(dc));

    double complex dc2 = pow(I, 2);
    printf("dc2 = %.2f%+.2f\n", creal(dc2), cimag(dc2));

    double complex dc3 = I * acos(-1);
    printf("dc3 = %.2f%+.2f\n", creal(dc3), cimag(dc3));

    double complex dc4 = 1 + 2 * I;
    double complex dc5 = 1 - 2 * I;

    return 0;
}
