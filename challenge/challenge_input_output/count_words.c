/* 
    Description: Write a program in C to count the number of words
                    and characters in a file OR from standard input
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *p_file = NULL;
    char ch = '\0';
    int char_count, word_count;

    if (argc == 1)
    {
        char_count = 0;
        word_count = 0;

        while((ch = getchar()) != EOF)
        {
            char_count++;
            if(ch == '\n') 
            {
                word_count++; 
            }
        }
        printf("Entered %d characters\n", char_count);
        printf("Entered %d words\n", word_count);
    }
    else if (argc == 2)
    {
        p_file = fopen(argv[1], "r");
        char_count = 0;
        word_count = 0;

        if (p_file != NULL)
        {
            while (1)
            {
                ch = fgetc(p_file);

                if (ch == EOF)
                    break;
                
                char_count++;
                printf("%c", ch);
        
                if (ch == '\n')
                    word_count++;
            }
            fclose(p_file);
            printf("Read in %d characters\n", char_count);
            printf("Read in %d words\n", word_count);
        }
        else
        {
            perror("Reading file\n");
            exit(1);
        }
    }
    
    else
    {
        printf("Invalid number of arguments.\n");
    }

    return 0;
}
