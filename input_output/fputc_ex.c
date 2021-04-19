#include <stdio.h>

int main(void)
{
    FILE * p_file = NULL;
    char c;

    p_file = fopen("myfile.txt", "w");

    if (p_file != NULL)
    {
        for (c='A'; c<='Z'; c++)
            fputc(c, p_file);
            // fputc(c, stdout);
        
        fclose(p_file);
    }

    return 0;
}