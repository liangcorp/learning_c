#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_attr_t attr;

void *do_work(void *thread_id)
{
	long t_id;
	size_t my_stack_size;

	t_id = (long)thread_id;
	pthread_attr_getstacksize(&attr, &my_stack_size);

	printf("Thead %ld: stack size = %li bytes\n", t_id, my_stack_size);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t my_thread;
	size_t stack_size;
	pthread_t my_id;
	long t = 5;

	pthread_attr_init(&attr);
	pthread_attr_getstacksize(&attr, &stack_size);
	printf("Default stack size = %li\n", stack_size);
	stack_size = 9000000;
	printf("Amount of stack needed per thread = %li\n", stack_size);
	pthread_attr_setstacksize(&attr, stack_size);

	printf("Create thread with stacksize = %li bytes\n", stack_size);

	my_id = pthread_create(&my_thread, &attr, do_work, (void *)t);

	if (my_id) {
		printf("ERROR: return code from pthread_create is %lu\n",
		       my_id);
		exit(1);
	}

	pthread_exit(NULL);

	return 0;
}
