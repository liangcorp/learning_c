/*
    Author: Chen Liang
    Description: Write a program that will sort an arry
                    of doubles from lowest to highest
                    using the qsort function
    Date: 25th Apr 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillarray(double ar[], int n)
{
    int i = 0;
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        ar[i] = (double)(rand() % 150000) / 10000;
    }
}

void showarray(const double ar[], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        printf("%.4lf\t", ar[i]);

        if((i + 1) % 6 == 0)
            printf("\n");
    }
}

int compare_double(const void * a, const void * b)
{
    const double x = * (const double *) a;
    const double y = * (const double *) b;

    if (x < y)
        return -1;
    else if (x == y)
        return 0;
    else
        return 1;
}

int main(void)
{
    int n = 40;
    double ar[n];

    fillarray(ar, n);
    showarray(ar, n);
    printf("\n\n");

    qsort(ar, n, sizeof(double), compare_double);

    showarray(ar, n);
    printf("\n");

    return 0;
}