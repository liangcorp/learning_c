#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    alarm(5);

    /* NEED TO CATCH SIGALARM
        or process terminates

       signal(SIGALRM, alarm_handler)
     */

    for (int i = 1; i < 10; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
}