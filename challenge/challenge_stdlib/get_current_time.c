/*
    Author: Chen Liang
    Description: Write a program to print the current time
                 - Use the time and ctime function
                 - Handle errors using fprintf and exit function
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t current_time = time(NULL);

    if (time(&current_time) == -1)
    {
        fprintf(stderr, "Problem getting time\n");
        exit(EXIT_FAILURE);
    }

    printf("The current time in seconds is %ld\n", current_time);
    printf("The current time is %s\n", ctime(&current_time));

    return 0;
}
