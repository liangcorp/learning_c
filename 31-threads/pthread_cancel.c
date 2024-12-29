#include <stdio.h>
#include <pthread.h>

void *my_function(void *ptr)
{
	printf("Hello world");
	pthread_cancel(pthread_self());
	return NULL;
}

int main()
{
	pthread_t thread = 0;

	pthread_create(&thread, NULL, my_function, NULL);

	pthread_join(thread, NULL);

	return 0;
}
