#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery()
{
    printf("detected an unrecoverable error\n");
    longjmp(buf, 1);
}

int main(void)
{
    while(1)
    {
        if (setjmp(buf))
        {
            printf("back in main\n");
            break;
        }
        else
        {
            error_recovery();
        }
    }
    return 0;
}
