#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE *file_ptr = NULL;
    FILE *dest_file_ptr = NULL;

    int c = 0;

    file_ptr = fopen("myfile.txt", "r");
    dest_file_ptr = fopen("temp.txt", "w+");

    if (file_ptr == NULL || dest_file_ptr == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    while ((c = fgetc(file_ptr)) != EOF)
    {
        if(islower(c))
            fputc((c - 32), dest_file_ptr);
        else
            fputc(c, dest_file_ptr);
    }

    fclose(file_ptr);
    fclose(dest_file_ptr);

    remove("myfile.txt");
    rename("temp.txt", "myfile.txt");

    return 0;
}
