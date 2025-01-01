#include <stdio.h>
#include <pthread.h>

#define NO_OF_THREADS 10

int counter = 0;

void *add_counter(void *data)
{
	int *x = (int *)data;
	counter++;
	printf("data: %d, thread_id: %lu, global counter: %d\n", *x,
	       pthread_self(), counter);
	printf("data: %d, thread_id: %lu, global counter: %d\n", *x,
	       pthread_self(), counter);

	return NULL;
}

int main()
{
	int i;

	pthread_t thread_id[NO_OF_THREADS] = { 0 };
	int values[NO_OF_THREADS];

	for (i = 0; i < NO_OF_THREADS; i++) {
		values[i] = i;
		pthread_create(&thread_id[i], NULL, add_counter, &values[i]);
	}

	for (i = 0; i < NO_OF_THREADS; i++) {
		pthread_join(thread_id[i], NULL);
		pthread_exit(&thread_id[i]);
	}
	return 0;
}
