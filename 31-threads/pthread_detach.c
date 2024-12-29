#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fn(void *arg)
{
	pthread_detach(pthread_self());
	sleep(1);
	printf("Thread fn\n");
	pthread_exit(NULL);

	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	int ret = pthread_create(&tid, NULL, thread_fn, NULL);

	if (ret != 0) {
		perror("Thread Creation Error\n");
		exit(1);
	}

    printf("After thread created in Main\n");
    pthread_exit(NULL);

	return 0;
}
