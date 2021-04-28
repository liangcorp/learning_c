#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
    handler only takes one int as parameter,
    because we are using sa_handler
 */

void termination_handler(int signum)
{
    struct temp_file *p;

    for (p = temp_file_list; p; p = p->next)
        unlink(p->name);
}

int main(void)
{
    struct sigaction new_actin, old_action;

    /* Set up the structure to specify the new action. */
    new_actin.sa_handler = termination_handler;
    sigemptyset(&new_actin.sa_mask);
    new_actin.sa_flags = 0;
    sigaction(SIGINT, NULL, &old_action);

    if (old_action.sa_handler != SIG_IGN)
        sigaction(SIGINT, &new_actin, NULL);

    sigaction(SIGHUP, NULL, &old_action);

    if (old_action.sa_handler != SIG_IGN)
        sigaction(SIGHUP, &new_actin, NULL);

    sigaction(SIGTERM, NULL, &old_action);

    if (old_action.sa_handler != SIG_IGN)
        sigaction(SIGTERM, &new_actin, NULL);

}

