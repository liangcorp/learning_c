#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 10

void child_process(void);
void parent_process(void);

int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid == 0) {
		child_process();
	} else if (pid > 0) {
		parent_process();
	} else {
		printf("fork() failed\n");
		return 1;
	}

	return 0;
}

void child_process(void)
{
	int i;

	for (i = 1; i <= MAX_COUNT; i++)
		printf("This line is from child, value = %d\n", i);

	printf("    *** Child process is done ***\n");
}

void parent_process(void)
{
	int i;

	for (i = 1; i <= MAX_COUNT; i++)
		printf("This line is from parent, value = %d\n", i);

	printf("*** Parent is done ***\n");
}
