/* 
    Not recommened because function can NOT tell whether a null character
    is included in the string it reads.

    - If a null character is read it will be stored in the string along
        with the rest of the characters read
    - Since a null character terminates a string, this will end your string
        prematurely, right before the first null character.
 */

#include <stdio.h>
#include <string.h>

#define LINE_M 255

int main(void)
{
    char buf[LINE_M];
    int ch = '\0';
    char *p = NULL;

    if (fgets(buf, sizeof(buf), stdin))
    {
        p = strchr(buf, '\n');
        if (p)
        {
            *p = '\0';
        }
        else
        {
            while (((ch = getchar()) != '\n') &&
                !feof(stdin) &&
                !ferror(stdin));
        }
    }
    printf("Our buffer contains: %s\n", buf);
    return 0;
}
