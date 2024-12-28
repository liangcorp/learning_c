#include <stdio.h>
#include <string.h>

int main()
{
    char *p1 = "Jason";
    char *p2 = NULL;

    p2 = strdup(p1);
    printf("Duplicated string is: %s", p2);

    char source[] = "Jason";

    /*
       5 bytes of source are copied to a new memory
       allocated dynamically and pointer to copied
       memory is returned.
    */
    char *target = strndup(source, 5);
    printf("%s\n", target);

    return 0;
}
