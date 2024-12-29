#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

static void hdl(int sig, siginfo_t *siginfo, void *context)
{
	printf("Send PID: %ld, UID: %ld\n", (long)siginfo->si_pid,
	       (long)siginfo->si_uid);
}

int main(int argc, char *argv[])
{
	struct sigaction act;

	memset(&act, '\0', sizeof(act));

	/*
       Use the sa sigaction field because the handles has to additional parameters
       hdl contains a signinfo_t and a void pointer, see the function prototype
    */

	act.sa_sigaction = &hdl;

	/* The SA_SIGINFO flag tell sigaction() to use the sa_sigaction */
	act.sa_flags = SA_SIGINFO;

	if (sigaction(SIGTERM, &act, NULL) < 0) {
		perror("sigaction");
		return 1;
	}

	while (1)
		sleep(10);

	return 0;
}
