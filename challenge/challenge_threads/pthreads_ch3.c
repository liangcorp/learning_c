/**
 * @file pthreads_ch3.c
 * @author Chen Liang
 * @brief Modified the program from challenge #2 so that certain
 *          threads execute critical sections of code before other
 *          threads do.
 *          - This program should print message from threads that pass
 *              in an even number first (parameter) and those that
 *              pass in an odd number after all the events have printed
 *              ~ Since we are not guaranteed that the threads will
 *                  start in any given order, we must have the odd
 *                  threads wait until all the even threads have printed
 *              ~ we do not care about the order that they print their
 *                  message
 *          - This program will require you to use condition variables
 *              to accomplish the ordering
 *              ~ all of the odd threads will sleep until a certain
 *                  condition is met (all the even threads have
 *                  finished)
 *
 * @version 0.1
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NO_OF_THREADS 10

pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

int counter = 0;
int thread_count = 0;

void *print_counter(void *ptr)
{
    /*
        *(int *)ptr in printf is too messy to read
     */
    int message;
    message = *(int *) ptr;

    _Bool even_thread = 0;

    if (message % 2 == 0)
    {
        even_thread = 1;
    }

    pthread_mutex_lock(&condition_mutex);

    if (even_thread == 0)
    {
        pthread_cond_wait(&condition_cond, &condition_mutex);
    }

    pthread_mutex_unlock(&condition_mutex);

    pthread_mutex_lock(&counter_lock);  /* lock the resource */

    counter++;
    thread_count++;

    printf("Message is %d, thread id = %li, "
            "modifed the counter to %d\n",
                                message, pthread_self(), counter);

    printf("Message is %d, thread id = %li, "
            "read the counter to %d\n",
                                message, pthread_self(), counter);

    if ((NO_OF_THREADS / 2) == thread_count)
    {
        printf("Moving on to odd threads\n");
        pthread_cond_broadcast(&condition_cond);
    }
    pthread_mutex_unlock(&counter_lock);    /* unlock the resource */
}

int main(void)
{
    int i = 0;
    int j = 0;
    pthread_t thread[NO_OF_THREADS];    /* declare thread */


    for (i = 0; i < NO_OF_THREADS; i++)
    {
        pthread_create(&thread[i], NULL, print_counter, (void *)&i);
    }

    for (i = 0; j < NO_OF_THREADS; j++)
    {
        pthread_join(thread[j], NULL);
    }

    pthread_exit(NULL);

    return 0;
}