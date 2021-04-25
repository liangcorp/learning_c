#include <stdio.h>

int main(void)
{
    const double pi = 3.141592654;

    const int days[12] = { 31, 28, 31, 30 };

    const float *pf;    // pf pointers to a constant float value

    float * const pt;   // pt is a const pointer. Address can't change

    const float * const ptr;    // All is const

    float const *pfc;   // same as const float *pfc;

    return 0;
}
