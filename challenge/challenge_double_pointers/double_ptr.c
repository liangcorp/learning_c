/* 
    Author: Chen Liang
    Description: Write a program that creates ,assigns and access
                    some double pointers.
                1. create a normal integer variable and assign it a
                        random value.
                2. create a single integer pointer variable
                3. create a double integer pointer variable
                4. assign the address of the normal integer variable
                        to the single pointer
                5. assign the address of the single pointer to the
                        double pointer variable
    Date 23 Apr 2021

 */
#include <stdio.h>

int main(void)
{
    int i = 10;
    int *ptr = NULL;
    int **double_ptr = NULL;

    ptr = &i;
    double_ptr = &ptr;

    /* Print out the vauble of the integer */
    printf("The integer value: %d\n", i);
    printf("The integer value: %d\n", *ptr);
    printf("The integer value: %d\n", **double_ptr);

    /* Print out the address of the integer */
    printf("The address of the integer: %d\n", &i);
    printf("The address of the integer: %d\n", ptr);
    printf("The address of the integer: %d\n", *double_ptr);

    /* Print out the value of the single pointer */
    printf("The value of single integer: %d\n", ptr);
    printf("The value of single integer: %d\n", *double_ptr);

    /* Print out the address of the single pointer */
    printf("The address of the single pointer: %d\n", &ptr);
    printf("The address of the single pointer: %d\n", double_ptr);

    /* Print out the double pointer value and address */
    printf("The double pointer value: %d\n", double_ptr);
    printf("The double pointer address: %d\n", &double_ptr);

    return 0;
}
