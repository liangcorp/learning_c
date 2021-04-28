/**
 * @file pthreads_ch1.c
 * @author Chen Liang
 * @brief Write a program in which multiple threads print a message
 *          - Create 10 separate threads and have each thread call one
 *              function that takes an argument
 *              ~ pass a different number for each thread to your
 *                  thread function
 *              ~ might want to use an array to store each thread
 *                  and to store each number
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

int counter = 0;

void *print_counter(void *ptr)
{
    /*
        *(int *)ptr in printf is too messy to read
     */
    int *message;
    message = (int *) ptr;

    counter++;  /* increase the counter */

    printf("Message is %d, thread id = %li, "
            "modifed the counter to %d\n",
                                *message, pthread_self(), counter);

    printf("Message is %d, thread id = %li, "
            "read the counter to %d\n",
                                *message, pthread_self(), counter);

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