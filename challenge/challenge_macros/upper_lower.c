/* 
    Author: Chen Liang
    Description: Write a C program to check whether
                a character is uppercase or lowercase using macros.
    Date: 21 Apr 2021
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define IS_UPPER(c) isupper(c)
#define IS_LOWER(c) islower(c)
#define IS_DIGIT(c) isdigit(c)
#define IS_ALPHABET(c) isalpha(c)
#define IS_VOWELS(c) strchr("aeiou", c)

int main(void)
{
    char c = '\0';

    printf("Enter a character: ");
    scanf("%c", &c);
    if (IS_ALPHABET(c))
    {
        printf("%c belongs to the alphabet.\n", c);
        if(IS_VOWELS(c) > 0)
            printf("%c is vowel\n", c);
        else
            printf("%c is not vowel.\n", c);

        if (IS_LOWER(c))
            printf("%c is lower case.\n", c);
        else if (IS_UPPER(c))
            printf("%c is upper case.\n", c);
        else
            printf("Can't seem to find out\n");
    }
    else if (IS_DIGIT(c))
        printf("%c is a digit\n", c);
    else
        printf("Input Error!\n");

    return 0;
}