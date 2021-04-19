#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void error_recovery(void)
{
    printf("Error in code\n");
    longjmp(buf, 1);
}

int main(void)
{
    int i;

    while(1 == 1)
    {
        i = setjmp(buf);
        if(i == 0)
        {
            error_recovery();
        }
        else
        {
            exit(0);
        }
        
    }    

    return 0;
}