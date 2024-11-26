#include <stdio.h>

#define MAX 100

int main()
{
    int p;
    int i;
    int primes[50] = {0};
    int prime_index = 2;

    _Bool is_prime;

    primes[0] = 2;
    primes[1] = 3;

    for (p = 5; p < MAX; p+=2) {
        is_prime = 1;   // true

        for (i = 1; is_prime == 1 && p / primes[i] >= primes[i]; i++)
            if (p % primes[i] == 0)
                is_prime = 0;      // false

        if (is_prime == 1) {
            primes[prime_index] = p;
            prime_index++;
        }
    }

    for (i = 0; i < prime_index; i++)
        printf("%d  ", primes[i]);

    printf("\n");

    return 0;
}
