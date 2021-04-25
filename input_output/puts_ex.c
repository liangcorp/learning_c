/* The puts() is used to write a line to the output screen
    automatically appends a newline
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char string[40];
    strcpy(string, "Hello, how are you");
    puts(string);

    return 0;
}
