#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void * hello_return(void * args)
{
    /* allocate a new string on the heap with "Hello World!" */
    char * hello = strdup("Hello World!\n");
    return (void *) hello;
}

int main(int argc, char const *argv[])
{
    char * str;
    pthread_t thread;   /* thread identifier */

    /*
        create a new thread that runs hello return without arguments
     */
    pthread_create(&thread, NULL, hello_return, NULL);

    /* wait until the thread completes, assign return value to str */
    pthread_join(thread, (void **)&str);
    /* pthread_exit(NULL); */
    printf("%s", str);

    return 0;
}