#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>


void nothing(int signum)
{
    /* DO NOTHING */
}

int main(void)
{
    /* Looking to ignore the SIGINT signal */
    signal(SIGINT, nothing);    /* high overhead approach */
    signal(SIGINT, SIG_IGN);    /* better approach */
    while (1);
}