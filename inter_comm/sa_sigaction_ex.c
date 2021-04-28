#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

/* handler takes three parameters because w are using sa_sigaction */
static void hdl(int sig, siginfo_t *siginfo, void *context)
{
    printf("Sending PID: %ld, UID: %ld\n", (long)siginfo->si_pid,
                                            (long)siginfo->si_uid);
}

int main(int argc, char const *argv[])
{
    struct sigaction act;

    memset(&act, '\0', sizeof(act));
    /*
        Use the sa_sigaction field because the handles has two
        additional parameters
        hdl contains a siginfo_t and a void pointer, see the
        function prototype
     */

    act.sa_sigaction = &hdl;

    /*
        The SA_SIGINFO flag tells sigaction() to use the sa_sigaction
        field, not sa_handler.
     */
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGTERM, &act, NULL) < 0)
    {
        perror("sigaction");
        return 1;
    }

    while (1)
        sleep(10);

    return 0;
}
