#include <stdio.h>

void copy_string_by_value(char to[], char from[])
{
    int i;

    for (i = 0; from[i] != '\0'; i++)
        to[i] = from[i];

    to[i] = '\0';
}

void copy_string_by_reference(char *to, char *from)
{
    while (*from)   //  The '\0' character is equal to the value 0 (i.e. false)
        *to++ = *from++;

    *to = '\0';
}

int main()
{
    char string1[] = "A string to be copied.";
    char string2[50];

    copy_string_by_reference(string2, string1);

    printf("%s\n", string2);

    return 0;
}
