#include <stdio.h>
#include <string.h>

int str_len(const char *s)
{
    const char *p_begin = s;

    while(*s) {
        s++;
    }

    return s - p_begin;
}

int main()
{
    char str[] = "A sentence";

    printf("%d\n", str_len(str));

    return 0;
}
