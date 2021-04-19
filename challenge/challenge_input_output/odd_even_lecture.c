#include <stdio.h>
#include <stdlib.h>

int is_even(const int);
int is_prime(const int);

int main(void)
{
    FILE *f_ptr_in = NULL;
    int num = 0;
    int success = 0;

    f_ptr_in = fopen("numbers.txt", "r");

    if (f_ptr_in == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists \
                and you have read/write permission\n");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully. Reading integers from file.\n\n");

    success == fscanf(f_ptr_in, "%d", &num);

    do
    {
        if(is_prime(num))
            printf("Prime number found: %d\n", num);
        else if(is_even(num))
            printf("Even number found: %d\n", num);
        else
            printf("Odd number found: %d\n", num);

        success = fscanf(f_ptr_in, "%d", &num);

    } while (success != -1);
    
    fclose(f_ptr_in);

    return 0;
}

int is_even(const int num)
{
    return !(num & 1);
}

int is_prime(const int num)
{
    int i = 0;

    if (num < 0)
        return 0;
    
    for (i=2; i<=num/2; i++)
    {
        /* If the number is disible by any number
            other than 1 and self than it's not prime
         */
        if (num % i == 0)
            return 0;
    }

    return 1;
}