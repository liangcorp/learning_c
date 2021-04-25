#ifndef STRING_FUNCTIONS_H_INCLUDED
#define  STRING_FUNCTIONS_H_INCLUDED

/* Find the frequency of characters in a string */
int frequency_of_char(const char c, const char *string);

/* Remove all non-alphabetic characters in a string */
char * remove_all_char(const char *string);

/* Calculate the length of a string without using strlen() */
int calculate_length(const char * string);

/* Concatenate two strings without using strcat() */
char * string_concatenation(const char * fst_str, const char * sec_str);

/* Copy a tring manually without using strcpy() */
char * copy_string(const char * string);

/* Find the substring of a given string */
_Bool found_substring(const char * sub_str, const char * string);

#endif