#include <stdio.h>
#include <signal.h>

int main()
{
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);

    /*
       $ ps
       $ kill -s SIGCONT <pid>
    */
    printf("I am back\n\n");

    return 0;
}
