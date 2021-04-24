#include <stdio.h>
#include <malloc.h>

#include "string_functions.h"

int main(void)
{
    int count = frequency_of_char('C', "ChenC");

    printf("%d\n", count);

    char *stripped = remove_all_char("dibiel32giA");
    printf("result after removal is %s\n", stripped);
    free(stripped);

    int size = calculate_length("Word");
    printf("The length of \"Word\" is %d\n", size);

    char *concatenated_str = string_concatenation("Chen ", "Liang");
    printf("%s\n", concatenated_str);
    free(concatenated_str);    

    char *copy = copy_string("Copied string");
    printf("%s\n", copy);
    free(copy);

    if (found_substring("Liang", "Chen Liang") == 1)
        printf("String found\n");
    else
        printf("String not found\n");

    return 0;
}