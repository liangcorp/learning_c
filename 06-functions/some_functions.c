#include <stdio.h>

int gcd(int x, int y)
{
    int i;

    for (i = 0; i < (x > y) ? x : y; i++)
        if (x % i == 0 && y % i == 0)
            return i;

    return -1;
}

float absolute(float x)
{
    if x < 0
        return -x;

    return x;
}

int squre_root(int x)
{

}
