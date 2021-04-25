/*
    Author: Chen Liang
    Description: Create a static library and then write
                    a program that uses that library
    Date: 24 Apr 2021
 */

#include <stdio.h>
#include <malloc.h>

#include "string_functions.h"

/* Find the frequency of characters in a string */
int frequency_of_char(const char c, const char *string)
{
    int i = 0;
    int count = 0;

    while(string[i] != '\0')
    {
        if (c == string[i])
            count++;
        i++;
    }

    #ifdef DEBUG
        printf("Size of %s is %d\n", string, i);
    #endif

    return count;
}

/* Remove all non-alphabetic characters in a string */
char * remove_all_char(const char * string)
{
    char *result = NULL;
    int i = 0;
    int j = 0;
    size_t size = 0;

    #ifdef DEBUG
        printf("starting remove non-alphabet in %s\n", string);
    #endif

    while(string[i] != '\0')
    {
        if (string[i] >= 64 && string[i] <= 90)
            size++;
        else if (string[i] >= 97 && string[i] <= 122)
            size++;
        i++;
    }

    result = calloc(size + 1, sizeof(char));

    for (i = 0; i < size; i++)
    {
        while (string[j] != '\0')
        {
            if (string[j] >= 'a' && string[j] <= 'z')
            {
                result[i] = string[j];
                j++;
                break;
            }
            else if (string[j] >= 'A' && string[j] <= 'Z')
            {
                result[i] = string[j];
                j++;
                break;
            }
            j++;
        }
    }

    return result;
}

/* Calculate the length of a string without using strlen() */
int calculate_length(const char * string)
{
    int result = 0;
    int i = 0;

    while(string[i] != '\0')
    {
        i++;
        result++;
    }

    return result;
}

/* Concatenate two strings without using strcat() */
char * string_concatenation(const char * fst_str, const char * sec_str)
{
    size_t size_fst_str = calculate_length(fst_str);
    size_t size_sec_str = calculate_length(sec_str);

    /* Don't forget the null character at the end */
    size_t size_result_str = size_fst_str + size_sec_str + 1;

    int i = 0;
    int j = 0;

    char *result = NULL;

    result = calloc(size_result_str, sizeof(char));

    for (i = 0; i < size_fst_str; i++)
    {
        result[i] = fst_str[i];
    }

    for (j = 0; j < size_sec_str; j++)
    {
        result[i] = sec_str[j];
        i++;
    }

    return result;
}

/* Copy a string manually without using strcpy() */
char * copy_string(const char * string)
{
    int i = 0;

    size_t size = calculate_length(string);

    char *result = NULL;

    result = calloc(size + 1, sizeof(char));

    for (i = 0; i < size; i ++)
        result[i] = string[i];

    return result;
}

/* Find the substring of a given string */
_Bool found_substring(const char * sub_str, const char * string)
{
    _Bool found_str = 0;

    int i = 0;
    int j = 0;
    int found_count = 0;

    size_t size_sub_str = calculate_length(sub_str);
    size_t size_str = calculate_length(string);

    /*
        Move the string one charactor to the right each loop.
        Make sure the loop can reach the last character.
     */
    for (i = 0; i <= (size_str - size_sub_str); i++)
    {
        found_count = 0;

        for (j = 0; j < size_sub_str; j++)
        {
            #ifdef DEBUG
                printf("%c %c", sub_str[i], string[i + j]);
            #endif

            if (sub_str[j] == string[i + j])
            {
                found_count++;
            }

            #ifdef DEBUG
                printf("\n\n");
            #endif
        }

        if (found_count == size_sub_str)
        {
            found_str = 1;
            break;
        }
    }

    return found_str;
}
