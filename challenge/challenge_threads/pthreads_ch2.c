/**
 * @file pthreads_ch2.c
 * @author Chen Liang
 * @brief The goal of this challenge is to write thread-safe code
 *          - code that will produce the correct result regardless
 *              of the order that threads are scheduled to run or
 *              if they are accessing shared resources
 *          - The global variable count should be the same value in
 *              each print statement for each thread
 *              ~ When the data is modified by a thread, the same
 *                  thread should be able to read that data before
 *                  it is modifed again by another thread
 *              ~ Data consistency of a shared resource, value is
 *                  changing from statement to statement by another
 *                  thread.
 *          - The counter variable is shared across mutiple threads
 *              without any synchronization constructs to protect it.
 *          - for this challenge, you'll need to edit the code from
 *              challenge 1 to create a mutex variable to ensure that
 *              multiple threads do not access the variable at the
 *              same time and introduce race conditions
 *          - Each thread should try to lock and unlock the mutex when
 *              they are executing any critical section (shared
 *              resources)
 *              ~ Incrementing and printing the global counter variable
 *              ~ after doing this, the counter should display the same
 *                  value in each print statement for that same thread
 *
 * @version 0.1
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <pthread.h>

#define NO_OF_THREADS 10

pthread_mutex_t lock;
int counter = 0;

void *print_counter(void *ptr)
{
    /*
        *(int *)ptr in printf is too messy to read
     */
    int *message;
    message = (int *) ptr;

    pthread_mutex_lock(&lock);  /* lock the resource */

    counter++;

    printf("Message is %d, thread id = %li, "
            "modifed the counter to %d\n",
                                *message, pthread_self(), counter);

    printf("Message is %d, thread id = %li, "
            "read the counter to %d\n",
                                *message, pthread_self(), counter);

    pthread_mutex_unlock(&lock);    /* unlock the resource */
}

int main(void)
{
    int i = 0;
    int j = 0;
    pthread_t thread[NO_OF_THREADS];    /* declare thread */


    for (i = 0; i< NO_OF_THREADS; i++)
    {
        pthread_create(&thread[i], NULL, print_counter, (void *)&i);
    }

    for (i = 0; j< NO_OF_THREADS; j++)
    {
        pthread_join(thread[j], NULL);
        pthread_exit(thread[j]);
    }

    return 0;
}