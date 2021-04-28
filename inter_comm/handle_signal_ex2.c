#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signal_handler(int signal_value);

int main(void)
{
    int i;  /* counter used to loop 100 times */
    int x;  /* variable to hold random values between 1-50 */

    signal(SIGINT, signal_handler);
    srand(clock());

    /* output numbers 1 to 100 */
    for  (i = 1; i <= 100; i++)
    {
        /* generate random numbers to raise SIGINT */
        x = 1 + rand() % 50;

        /* raise SIGINT when x is 25 */
        if (x == 25)
            raise(SIGINT);
    }
}

void signal_handler(int signal_value)
{
    int response;   /* user's response to signal (1 or 2) */

    printf("%s%d%s\n%s", "\nInterrupt signal ( ", signal_value, ") received ",
            "Do you wish to continue (1 == yes or 2 == no)? ");
    scanf("%d", &response);

    /* check for invalid responses */
    while (response != 1 && response != 2)
    {
        printf("(1 = yes or 2 = no)? ");
        scanf("%d", &response);
    }

    /* determine if it is time to exit */
    if (response == 1)
    {
        /* re-register signal handler for next SIGINT */
        signal(SIGINT, signal_handler);
    }
    else
    {
        exit(EXIT_SUCCESS);
    }

}