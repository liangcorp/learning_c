#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i;

	alarm(5);

	/*
       NEED TO CATCH SIGALRM or process terminates
       signal(SIGALRM, alarmHandler);
    */

	for (i = 1; i < 10; i++) {
		printf("%d\n", i);
		sleep(1);
	}

	return 0;
}
