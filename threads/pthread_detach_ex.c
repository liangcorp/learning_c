#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_fn(void *arg)
{
    pthread_detach(pthread_self());
    sleep(1);
    printf("Thread Fn\n");
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, thread_fn, NULL);

    if (ret != 0)
    {
        perror("Thread Creation Error\n");
        exit(1);
    }

    printf("After thread created in Main\n");
    pthread_exit(NULL);
    return 0;
}
