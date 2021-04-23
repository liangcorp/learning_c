#include <stdio.h>
#include <string.h>

/* 
void send(void * p_data, int n_lenth);

char *data = "blah";

send(data, strlen(data));
 */



int main(void)
{
    int i = 10;
    float f = 2.34;
    char ch = 'k';

    void *vptr = NULL;

    vptr = &i;

    printf("Value of i = %d\n", *(int *)vptr);

    vptr = &f;
    printf("Value of i = %f\n", *(float *)vptr);

    vptr = &ch;
    printf("Value of ch = %c\n", *(char *)vptr);

    return 0;
}