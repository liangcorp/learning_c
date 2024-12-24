#include <stdio.h>

#define CHAR 0

void send(void *p_data, int n_length, int type)
{
    if (type == CHAR)
        printf("%c", *(char *)p_data);
}

int main()
{
    char ch = 'k';

    send(ch, strlen(ch), CHAR);

    return 0;
}
