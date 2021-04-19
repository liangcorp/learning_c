#include <stdio.h>

int main(void)
{
    FILE *file_pointer;

    file_pointer = fopen("myfile.txt", "w+");

    fputs("This is Chen Cource.", file_pointer);
    fputs("I am happy to be here", file_pointer);

    fclose(file_pointer);

    return 0;
}