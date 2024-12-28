#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    char *str;

    /* attempt to access environment variables using getenv() */
    assert((str = getenv("HOME")) != NULL);
    printf("Value of \"HOME Environment Variable\": %s\n", str);

    assert((str = getenv("PATH")) != NULL);
    printf("Value of \"PATH Environment Variable\" : %s\n", str);

    assert((str = getenv("LOGNAME")) != NULL);
    printf("Value of \"LOGNAME Environment Variable\": %s\n", str);

    /* attempt to access environment variable of our choice */
    assert((str = getenv("JASON")) != NULL);
    printf("Value of \"JASON Environment Variable\": %s\n", str);

    return 0;
}
