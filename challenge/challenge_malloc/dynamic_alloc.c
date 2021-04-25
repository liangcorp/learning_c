/* 
    Author: Chen Liang
    Description: Write a programm that allows an user to input a text string.
                    The program will print the text that was inputted.
                    The program will utilize dynamic memory allocation.
    Date: 6th April 2021
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int no_of_letters = 0;
    char *input = NULL;

    printf("How many charactors for the string: ");
    scanf("%d", &no_of_letters);

    input = (char *) malloc(no_of_letters * sizeof(char));

    if (input != NULL)
    {
        printf("Input your string: ");
        scanf("%s", input);

        printf("Your input string is: %s\n", input);

        free(input);
    }
    else
    {
        printf("ERROR: Unable to locate memory\n");
    }

    return 0;
}
