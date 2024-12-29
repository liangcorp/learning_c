#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler_divide_by_zero(int signum);

int main()
{
	int result = 0;
	int v1 = 0;
	int v2 = 0;

	void (*sig_handler_return)(int);

	sig_handler_return = signal(SIGFPE, handler_divide_by_zero);

	if (sig_handler_return == SIG_ERR) {
		perror("Signal Error: ");
		return 1;
	}

	v1 = 121;
	v2 = 0;

	result = v1 / v2;

	printf("Result of Divided by Zero is %d\n", result);

	return 0;
}

void handler_divide_by_zero(int signum)
{
	if (signum == SIGFPE) {
		printf("Received SIGFPE, Divided by Zero Exception\n");
		exit(0);
	} else {
		printf("Received %d Signal\n", signum);
	}
}
