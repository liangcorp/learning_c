/*  
    Author: Chen Liang
    Description: Write a program to print the value of
                    the following predefined symbolic constants
    Date: 21 Apr 2021
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    if (__STDC__ == 1)
    {
        printf("Current line is %d\n", __LINE__);
        printf("File name is: %s\n", __FILE__);
        printf("The current date is %s\n", __DATE__);
        printf("Time of compilation: %s\n", __TIME__);
    }
    else
    {
        printf("Implementation is not ISO-conforming!\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}