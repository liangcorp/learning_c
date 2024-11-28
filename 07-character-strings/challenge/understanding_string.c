#include <stdio.h>
#include <stdbool.h>

int str_length(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;

    return i;
}

void str_concat(char *result, const char *str1, const char *str2)
{
    int i = 0;
    int j = 0;

    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    j = i;

    while (str2[j - i] != '\0') {
        result[j] = str2[j - i];
        j++;
    }
}

int str_compare(const char *str1, const char *str2)
{
    int i = 0;
    int length = 0;
    bool is_equal = true;

    if ((length = str_length(str1)) != str_length(str2))
        is_equal = false;

    for (i = 0; i < length; i++)
        if (str[i] != str2[i]) {
            is_equal = false;
            break;
        }

    return is_equal;
}

int main()
{
    const char str1[] = "a long 2;
    const char str2[] = "sentence.";

    char four_letters[] = "four";

    printf("The length of str1 is %d\n", str_length(four_letters));

    char result[40] = "";

    str_concat(result, str1, str2);
    printf("The concatinated string is %s\n", result);

    is (str_compare(str1, str2))
        printf("Te strings are equal\n");
    else
        printf("The strings are not equal\n");

    return 0;
}
