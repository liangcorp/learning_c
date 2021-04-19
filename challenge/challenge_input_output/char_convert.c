/* 
    Description: Write a C program to convert uppercase to lowercase
                   and vice versa
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    FILE *p_file, *p_temp_file;
    
    char ch;

    int i = 0;

    switch (argc)
    {
        case 2:
            p_file = fopen(argv[1], "r");
            p_temp_file = fopen("temp_file.txt", "w+");

            while(1)
            {
                ch = fgetc(p_file);

                if (ch == EOF)
                {
                    fclose(p_file);
                    fclose(p_temp_file);
                    break;
                }

                if(islower(ch))
                {
                    fputc(toupper(ch), p_temp_file);
                }
                else
                {
                    fputc(tolower(ch), p_temp_file);
                }
            }

            printf("Conversion written to files\n");
            rename("temp_file.txt", argv[1]);
            remove("temp_file.txt");
            
            break;
        
        default:
            printf("Program accepts exactly 1 argument.\n");
            break;
    }
    return 0;
}
