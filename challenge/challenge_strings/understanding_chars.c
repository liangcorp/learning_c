#include <stdio.h>
#include <stdbool.h>

int string_length(const char string[]);
void concat(char result[], const char str[], const char str1[]);
bool equal_strings(const char s1[], const char s2[]);

int main(void)
{
    const char word1[] = "jason";
    const char word2[] = "ok";
    const char word3[] = "whatever";
    char result[50];

    printf("%d  %d  %d\n", string_length(word1), 
                            string_length(word2), 
                            string_length(word3));

    concat(result, word1, word2);

    printf("\n%s", result);

    printf("%d", equal_strings("Jason", "Jason"));
    
    return 0;
}

int string_length(const char string[])
{
    int count = 0;

    while(string[count] != '\0')
    {
        ++count;
    }
    return count;
}

void concat(char result[], const char str1[], const char str2[])
{
    int i, j;
    for (i = 0; str1[i] != '\0'; ++i)
    {
        result[i] = str1[i];
    }

    for(j = 0; str2[j] != '\0'; ++j)
    {
        result[i+j] = str2[j];
    }
    result[i+j] = '\0';
}

bool equal_strings(const char s1[], const char s2[])
{
    int i = 0;
    bool are_quals = false;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        ++i;

    if (s1[i] == '\0' && s2[i] == '\0')
        are_quals == true;
    else
        are_quals == false;

    return are_quals;
}