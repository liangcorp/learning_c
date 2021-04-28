/**
 * @file fork_challenge.c
 * @author Chen Liang
 * @brief Write a program to create one parent with three
 *          children processes (four processes)
 *              - must use the fork function
 *        The program should contain output that identifies each parent
 *          and each child:
 *              - Will need to write if statements to check process
 *                  id's returned from the fork() call, so that the
 *                  output information is correct
 *                  * "parent", "first child", "second child",
 *                      "third child"
 *                  * Utilize the getpid() and getppid() functions
 *                      to display each process id
 * @version 0.1
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = 0;

    pid = fork();

    if (pid == 0)
    {
        printf("First child\n");
        printf("my id is %d\n",  getpid());
        printf("my parentid is %d\n\n", getppid());

        pid = fork();

        if (pid == 0)
        {
            printf("Third child\n");
            printf("my id is %d\n", getpid());
            printf("my parent id is %d\n\n", getppid());
        }
        else if (pid > 0)
        {

        }
        else
        {
            printf("fork() failed\n");
            exit(EXIT_FAILURE);
        }

    }
    else if (pid > 0)
    {
        printf("Parent\n");
        printf("my id is %d\n", getpid());
        printf("my parent id is %d\n\n", getppid());

        pid = fork();

        if (pid == 0)
        {
            printf("Second child\n");
            printf("my id is %d\n", getpid());
            printf("my parent id is %d\n\n", getppid());
        }
        else if (pid > 0)
        {

        }
        else
        {
            printf("fork() failed\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("fork() failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}