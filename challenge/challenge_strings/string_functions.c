#include <stdio.h>

int no_of_char(const char (*s)[])
{
    int i;

    for (i=0; (*s)[i] != '\0'; i++);

    return i;
}

void join_strings(const char (*x)[], const char (*y)[])
{
    int result_size = no_of_char(x) + no_of_char(y);

    char result[result_size];

    int i, j;

    for (i = 0; i < no_of_char(x); i++)
    {
        result[i] = (*x)[i];
    }
    printf("\n");

    j = 0;
    for (i = no_of_char(x); i < result_size; i++)
    {
        result[i] = (*y)[j];
        j++;
    }

    printf("Result of concatination is:\n");
    for(i=0; i<result_size; i++)
        printf("%c", result[i]);
    printf("\n\n");
}

_Bool are_equal(const char (*x)[], const char (*y)[])
{
    _Bool equal = 1;
    int i;
    int counter = 0;

    if (no_of_char(x) == no_of_char(y))
    {
        for (i=0; i<no_of_char(x); i++)
            if((*x)[i] == (*y)[i])
                counter++;
    }

    if (counter == no_of_char(x))
        equal = 1;
    else
        equal = 0;

    return equal;
}

int main(void)
{
    const char FIRST[] = "some string ";
    const char SECOND[] = "some string ";

    int string_length = 0;
    char result_string[30];
    _Bool equal = 0;

    string_length = no_of_char(&FIRST);

    printf("The length of first string is %d\n", string_length);

    join_strings(&FIRST, &SECOND);

    if (are_equal(&FIRST, &SECOND))
        printf("Both strings are equal.\n");
    else
        printf("Both strings are not equal.\n");

    return 0;
}
