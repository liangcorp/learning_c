#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void my_function(void)
{
    printf("in my_function()\n");
    longjmp(buf, 1);

    /* NOT REACHED */
    printf("you will never see this, because I longjmp'd");
}

int main(void)
{
    if (setjmp(buf))
        printf("back in main\n");
    else
    {
        printf("first time through\n");
        my_function();
    }
    return 0;
}
