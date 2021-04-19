/*
    Author: Chen Liang
    Description: Write a program that takes two command line arguments
                - the first is a character
                - the second is a file name
                
                The program should print only those line the file
                    containing the given character
                    - lines in a file are identified by a '\n'
                    - assumE that no lines is more than 256 char long
                You are required to use fgets() or getline() for
                    reading the file.
                Use puts() to display the output
    Date 10-Apr-2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        perror("Wrong number of arguments. Needs 2.");
        exit(1);
    }

    FILE *file_ptr = NULL;
    char *file_char = NULL;
    size_t max_char_per_line = 256;

    int input_char = (int)*argv[1];

    file_char = (char *)malloc(max_char_per_line * sizeof(char));

    file_ptr = fopen(argv[2], "r");

    while (getline(&file_char, &max_char_per_line, file_ptr) != EOF)
    {
        // Finds the "\n"'s position in string,
        // initialises that character to \0
        file_char[strcspn(file_char, "\n")] = '\0';

        //  Find the first occurrence of input character in string
        if(strchr(file_char, input_char) != NULL)
            puts(file_char);
    }

    free(file_char);
    fclose(file_ptr);

    return 0;
}
