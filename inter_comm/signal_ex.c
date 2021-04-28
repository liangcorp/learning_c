#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{
    printf("Testing SIGSTOP\n");

    /* Stop the program */
    raise(SIGSTOP);

    /* command "kill -s SIGCONT <process id>"
        will bring the program back. */
    printf("I am back\n");
    return 0;
}