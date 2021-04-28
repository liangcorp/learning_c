/**
 * @file handle_sign.c
 * @author Chen Liang
 * @brief Write a program that will test a user's multiplication skills
 *          - The program will ask the user to work on an answer to
 *              a simple multiplication program
 *          - Keep track of how many answers are correct
 *        The program will keep running forever unless:
 *          - The user presses Ctrl-C
 *          - The user takes more than 5 seconds to answer the question.
 * @version 0.1
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game(int sig)
{
    printf("\nFinal score: %d\n", score);
    exit(0);
}

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(void)
{
    signal(SIGINT, end_game);
    signal(SIGALRM, end_game);

    while(1)
    {
        int a = rand() % 11;
        int b = rand() % 11;

        char txt[4];

        printf("\nWhat is %d times %d: ", a ,b);

        alarm(5);

        fgets(txt, 4, stdin);

        alarm(0);   /* reset alarm */

        int answer = atoi(txt);

        if (answer == a * b)
            score++;
        else
            printf("\nWrong! Score: %d\n", score);
    }

    return 0;
}