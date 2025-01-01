#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NO_OF_THREAD 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t events_done = PTHREAD_COND_INITIALIZER;

int number_events_finished = 0;

int counter = 0;

void *add_counter(void *data)
{
	int *x = (int *)data;
	pthread_mutex_lock(&lock);

	if (*x % 2 == 0)
		number_events_finished++;
	else
		pthread_cond_wait(&events_done, &lock);

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

	sleep(1);

	while (1) {
		if (number_events_finished == NO_OF_THREAD / 2) {
			pthread_cond_broadcast(&events_done);
			break;
		}
	}

	for (i = 0; i < NO_OF_THREAD; i++) {
		pthread_join(thread_id[i], NULL);
		pthread_exit(&thread_id[i]);
	}

	return 0;
}
