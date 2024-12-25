#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t cur_time = 0;
	char *cur_t_string;

	cur_time = time(NULL);

	if (cur_time == ((time_t)-1)) {
		fprintf(stderr, "Failure to get the current time.\n");
		exit(EXIT_FAILURE);
	}

	cur_t_string = ctime(&cur_time);

	if (cur_t_string == NULL) {
		fprintf(stderr, "Failure to covert current time\n");
		exit(EXIT_FAILURE);
	}

	printf("\n The Current time is: %s\n", cur_t_string);

	return 0;
}
