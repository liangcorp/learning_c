#include <stdio.h>

//  greatest common divisor
int gcd(int x, int y)
{
    int divisor = x < y ? x : y;

    for (; divisor > 0; divisor--)
        if ((x % divisor = 0) && (y % divisor == 0))
            return divisor;
}

// lecture solution
int lecture_gcd(int u, int v)
{
    int temp;

    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;
    }

    return u;
}

// return absolute number
float absolute(float x)
{
    if (x < 0.0F)
        x = -x;
    return x;
}

//  calculate squre root
float square_root(float x)
{
    const float epsilon = 0.00001;
    float guess = 1.0;

    if (x < 0.0F) {
        printf("Negative argument to square root.\n");
        return -1.0;
    }

    while (absolute(guess * guess - x) >= epsilon)
        guess = (x / guess + guess) / 2.0;

    return guess;
}

int main()
{
    printf("%d\n", gcd(15. 10));

    return 0;
}
