/* 
    Author: Chen Liang
    Description: Write a program that takes a input, a set
                    of numbers from a file and write even,
                    odd and prime numbers to standard output
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *ptr_file = NULL;
    size_t line_size = 200;
    char *line = NULL;
    char num[5][10];
    int i;

    ptr_file = fopen("numbers.txt", "r");
    line = (char *)malloc(line_size * sizeof(char));


    if (ptr_file == NULL)
    {
        perror("failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    while(getline(&line, &line_size, ptr_file) != EOF)
    {
        sscanf(line, "%s\t%s\t%s\t%s\t%s", num[0], num[1],
                                           num[2], num[3], num[4]);

        for (i=0; i<5; i++)
        {
            if (atoi(num[i]) % 2 == 0)
                printf("Even number found: %s\n", num[i]);
            else
                printf("Odd number found: %s\n", num[i]);
        }
    }

    fclose(ptr_file);
    free(line);
    return 0;
}
