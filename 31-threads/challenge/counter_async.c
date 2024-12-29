#include <stdio.h>
#include <pthread.h>

#define NO_OF_THREAD 10

int counter = 0;

void *add_counter(void *message)
{
	counter++;
	printf("Message: %d, thread id: %lu, global counter: %d \n",
	       *(int *)message, pthread_self(), counter);
	printf("Message: %d, thread id: %lu, global counter: %d \n",
	       *(int *)message, pthread_self(), counter);

	return NULL;
}

int main()
{
	int i;

	pthread_t threads[NO_OF_THREAD] = { 0 };

	for (i = 0; i < NO_OF_THREAD; i++)
		pthread_create(threads + i, NULL, add_counter, (void *)&i);

	for (i = 0; i < NO_OF_THREAD; i++)
		pthread_join((threads[i]), NULL);

	pthread_exit(NULL);
	return 0;
}
