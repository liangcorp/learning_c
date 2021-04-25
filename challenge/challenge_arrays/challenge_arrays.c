#include <stdio.h>

#define HUNDRED 100

int main(void)
{
    int prime_number[HUNDRED] = {2, 3};
    int counter = 2;
    _Bool is_prime = 1;

    for (int i=5; i<HUNDRED; i+=2)
    {
        for(int j=0; j<HUNDRED; j++)
        {
            if (prime_number[j] == 0)
            {
                break;
            }

            if(i % prime_number[j] == 0)
            {
                is_prime = 0;
            }

        }

        if (is_prime)
        {
            prime_number[counter] = i;
            counter++;
        }

        is_prime = 1;

    }

    printf("Prime numbers:");

    for (counter=0; counter<HUNDRED; counter++)
    {
        if(prime_number[counter] == 0)
        {
            printf("\n");
            return 0;
        }
        printf(" %d", prime_number[counter]);
    }

    printf("\n");

    return 0;
}
