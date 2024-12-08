#include <stdio.h>
#include <complex.h>
#include <math.h>

//  #define PI 3.141592654

int main()
{
    double complex dc = I * I;
    printf("dc = %.2f%+.2fi\n", creal(dc), cimag(dc));

    double complex dc2 = pow(I, 2);
    printf("dc2 = %.2f%+.2fi\n", creal(dc2), cimag(dc2));

    double complex dc3 = exp(I * acos(-1));
    printf("dc3 = %.2f%+.2fi\n", creal(dc3), cimag(dc3));

    double complex dc4 = 1 + 2 * I;
    double complex dc5 = 1 - 2 * I;

    double complex conj = dc4 * dc5;
    printf("conjugate of dc4 and dc5 = %.2f%+.2fi\n", creal(conj), cimag(conj));

    return 0;
}
