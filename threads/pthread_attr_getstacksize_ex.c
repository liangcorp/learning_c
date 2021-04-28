#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_attr_t attr;

void *dowork(void *threadid)
{
    long tid;
    size_t mystacksize;

    tid = (long)threadid;
    pthread_attr_getstacksize(&attr, &mystacksize);

    printf("Thread %ld: stack size = %li bytes\n", tid, mystacksize);

    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t my_thread;
    size_t stacksize;
    pthread_t my_id;
    long t = 5;     /* not important */

    pthead_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stacksize);
    printf("Default stack size = %li\n", stacksize);
    stacksize = 9000000;

    printf("Amount of stack needed per thread = %li\n", stacksize);
    pthread_attr_setstacksize(&attr, stacksize);

    printf("Creating thread with strack size = %li bytes\n", stacksize);

    my_id = pthread_create(&my_thread, &attr, dowork, (void *)t);

    if (my_id)
    {
        printf("ERROR; return code from pthread_create() is %lud\n",
                                                                my_id);
        exit(-1);
    }

    pthread_exit(NULL);
    return 0;
}
