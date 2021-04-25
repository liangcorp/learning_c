#include <stdio.h>

int main(void)
{
    FILE *file_ptr = NULL;
    int line_count = 0;
    int charactor;

    file_ptr = fopen("myfile.txt", "r");

    if (file_ptr != NULL)
    {
        while((charactor = fgetc(file_ptr)) != EOF)
        {
            if (charactor == 10)
                line_count++;
        }
    }
    else
    {
        perror("Error in opening file");
        return -1;
    }

    printf("Totle lines of text: %d\n", line_count);

    fclose(file_ptr);

    return 0;
}
