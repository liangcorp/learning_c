/* 
    Latest function for readinga a string of text is getline()
    Preferred method for reading lines of text
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));

    if (buffer == NULL)
        exit(1);

    printf("Type something: ");
    characters = getline(&buffer, &bufsize, stdin);

    printf("%zu characters were read.\n", characters);
    printf("You typed: '%s'\n", buffer);

    return 0;
}
