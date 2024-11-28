#include <stdio.h>
#include <string.h>

int main()
{
    char my_string[] = "my string";

    printf("The length of the string is: %d", strlen(my_string));

    char s[100];
    //  s = "Hello" doesn't work in C
    strcpy(s, "Hello");

    memset(s, '\0', sizeof(s) - 1);
    strncpy(s, "Hello", 5); //  Safter than strcpy()

    return 0;
}
