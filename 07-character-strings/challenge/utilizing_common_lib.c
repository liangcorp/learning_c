#include <stdio.h>
#include <string.h>

void reverse_str(void)
{
    int i;
    char s[50];
    memset(s, '\0', 50);
    printf("Enter a string: ");
    scanf("%s", s);

    for (i = strlen(s) - 1; i >= 0; i--)
        printf("%c", s[i]);

    printf("\n");
}

void sort_string()
{
    int i, j, no_of_strings;

    printf("Enter a number for strings: ");
    scanf("%d", &no_of_strings);

    char s[3][50];

    printf("Enter the strings: ");
    for (i = 0; i < no_of_strings; i++)
        scanf("%s", s[i]);

    i = 1;

    char temp[50];
    memset(temp, '\0', 50);

    while (i != 3) {
        j = i;

        while (strcmp(s[j], s[j - 1]) < 0) {
            strncpy(temp, s[j], 50);
            strncpy(s[j], s[j - 1], 50);
            strncpy(s[j - 1], temp, 50);
            j--;
        }
        i++;
    }

    for (i = 0; i < 3; i++)
        printf("%s\n", s[i]);
}

int main()
{
    sort_string();
    return 0;
}
