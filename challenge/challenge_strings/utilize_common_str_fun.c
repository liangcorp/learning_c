#include <stdio.h>
#include <string.h>

void reverse_string(char *str)
{
    int i;
    printf("%s in reverse is:\n", str);
    for (i = (strlen(str) - 1); i >= 0; i--)
        printf("%c", str[i]);
    
    printf("\n");
}

void bubble_sort()
{
    int no_of_strings = 0;
    int i, j;
    int counter = 0;

    printf("Input number of strings: ");
    scanf("%d", &no_of_strings);

    char input_strings[no_of_strings][100];
    char temp[100];

    for (i=0; i<no_of_strings; i++)
        scanf("%s", &input_strings[i]);

    for(i=0; i<no_of_strings; i++)
        for(j=0; j<no_of_strings-1; j++)
        {
            if(strcmp(input_strings[j], input_strings[j+1]) > 0)
            {
                strcpy(temp, input_strings[j]);
                strcpy(input_strings[j], input_strings[j+1]);
                strcpy(input_strings[j+1], temp);
            }
        }
    printf("\nThe strings appears after sorting:\n");
    for(i=0; i<no_of_strings; i++)
        printf("%s\n", input_strings[i]);

}

int main(void)
{
    char input_string[100];

    printf("Enter a string: ");
    scanf("%s", input_string);

    reverse_string(input_string);
    bubble_sort();

    return 0;
}