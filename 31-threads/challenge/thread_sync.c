#include <stdio.h>
#include <pthread.h>

#define NO_OF_THREAD 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;

void *add_counter(void *data)
{
	int *x = (int *)data;
	pthread_mutex_lock(&lock);
	counter++;
	printf("data: %d, thread id: %lu, global counter: %d\n", *x,
	       pthread_self(), counter);
	printf("data: %d, thread id: %lu, global counter: %d\n", *x,
	       pthread_self(), counter);

	pthread_mutex_unlock(&lock);

	return NULL;
}

int main()
{
	int i;

	pthread_t thread_id[NO_OF_THREAD] = { 0 };
	int values[NO_OF_THREAD];

	for (i = 0; i < NO_OF_THREAD; i++) {
		values[i] = i;
		pthread_create(&thread_id[i], NULL, add_counter, &values[i]);
	}

	for (i = 0; i < NO_OF_THREAD; i++) {
		pthread_join(thread_id[i], NULL);
		pthread_exit(&thread_id[i]);
	}

	return 0;
}
