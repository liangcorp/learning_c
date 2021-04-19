/* 
    Author: Chen Liang
    Description: Write a function that calculates the length of a string
        - the function should take as a parameter a const char pointer
        - the function can only determine the length of the string
            using pointer arithmetic
            -- incrementation operator (++pointer) to get to the
                end of the string
        - you are required to use a while loop using the value of
            the pointer to exit
        - the function should subtract two pointers (one pointing
                to the end of the string and one pointer to the
                beginning of the string)
        - the function should return an int that is the length
                of the string passed into the function
    Date: 05-Apr-2021
 */

#include <stdio.h>

int str_length(const char *str)
{
    int length = 0;
    const char *str_end;
    str_end = str;

    while (*str_end)
    {
        str_end++;
    }

    length = str_end - str;

    return length;
}

int main(void)
{
    char *str;
    const char *const_str;

    printf("Enter a string: ");
    scanf("%s", str);
    const_str = str;

    printf("The length is: %d\n", str_length(const_str));

    return 0;
}