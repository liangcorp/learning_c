/*
    Author: Chen Liang
    Description: Write a C program that generates 50
                    random numbers between -0.5 and 0.5
    Date: 25th Apr 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int i = 0;
    float random_number = 0.0F;

    printf("Random numbers between -0.5 and 0.5:\n");
    for (i = 0; i < 50; i++)
    {
        /*
            There are 3 steps to generate random number
                between -0.5 and 0.5:
            1. Generate random number between 0.00 to 100.00
            2. Divide the number by 100 (i.e. 0.00 to 1.00)
            3. Subtract 0.5 from them (i.e. -0.5 to 0.5)
        */
        random_number = (float)(rand() % 100) / 100 - 0.5;
        printf("%.2f ", random_number);
    }

    printf("\n");

    return 0;
}