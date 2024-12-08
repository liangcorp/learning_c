#include <stdio.h>
#include <complex.h>
#include <math.h>

//  #define PI 3.141592654

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

    double complex dc4_conj = creal(dc4) + cimag(dc4) * -cimag(dc4);
    double complex dc5_conj = creal(dc5) + cimag(dc5) * -cimag(dc5);

    printf("conjugate of dc4 = %.2f%+.2f\n", creal(dc4_conj), cimag(dc4_conj));
    printf("conjugate of dc5 = %.2f%+.2f\n", creal(dc5_conj), cimag(dc5_conj));

    return 0;
}
