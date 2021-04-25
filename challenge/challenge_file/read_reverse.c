#include <stdio.h>

int main(void)
{
    FILE *file_ptr = NULL;
    int len, c, i, j;

    len = 0;
    c = 0;

    file_ptr = fopen("myfile.txt", "r");

    if (file_ptr == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    fseek(file_ptr, 0, SEEK_END);

    len = ftell(file_ptr);

    // Start after EOF and the last line feed character
    for (i=(len-2); i>=0; i--)
    {
        fseek(file_ptr, i, SEEK_SET);
        c = fgetc(file_ptr);
        printf("%c", c);
    }

    printf("\n");

    fclose(file_ptr);
    return 0;
}
