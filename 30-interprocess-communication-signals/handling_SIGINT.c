#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signal_handler(int signal_value);

int main(void)
{
	int i;
	int x;

	signal(SIGINT, signal_handler);
	srand(clock());

	for (i = 1; i <= 100; i++) {
		/* generate random number to raise SIGINT */
		x = 1 + rand() % 50;

		/* raise SIGNINT when x is 25 */
		if (x == 25)
			raise(SIGINT);

		printf("%4d", i);

		if (i % 10 == 0)
			printf("\n");
	}

	return 0;
}

void signal_handler(int signal_value)
{
	int response;
	printf("%s%d%s\n%s", "Interrupt signal ( ", signal_value, " ) received",
	       "Do you wish to continue (1 = yes or 2 = no)");
	scanf("%d", &response);

	while (response != 1 && response != 2) {
		printf("(1 = yes or 2 = no)?");
		scanf("%d", &response);
	}

	if (response == 1)
		signal(SIGINT, signal_handler);
	else
		exit(EXIT_SUCCESS);
}
