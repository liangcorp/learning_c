#include <stdio.h>

int main(void)
{
    FILE *p_file = NULL;
    char *filename = "myfile.txt";

    p_file = fopen(filename, "w");  // Open myfile.txt to write to it

    if(p_file != NULL)
        printf("Failed to open %s.\n", filename);

    fclose(p_file);
    p_file = NULL;

    if(rename("myfile.txt", "myfile_copy.txt"))
        printf("Failed to rename file.");
    else
        printf("File renamed successfully.");
    
    remove("myfile.txt");
    return 0;
}