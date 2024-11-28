#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "The quick brown fox";

    char ch = 'q';

    char *p_got_char =NULL; //  Pointer initialized to NULL
    p_got_char = strchr(str ch); // Store address where ch is found

    char word[] = "dog";

    char *p_found_str = NULL;
    p_found_str = strstr(text, word);

    const char s[2] = " ";  // space and the '\0' char

    char *token;

    //  get the first token
    token = strtok(str, s);

    // Walk through the other tokens
    while (token != NULL) {
        printf("%s\n", token);

        token = strtok(NULL, s);
    }

    return 0;
}
