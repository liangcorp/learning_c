#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char buf[MAX_SIZE];

    int no_letters = 0;
    int no_digits = 0;
    int no_punctuation = 0;

    printf("Enter an interesting string of less than %d characters: ", MAX_SIZE);
    scanf("%s", buf);

    int i = 0;

    while (buf[i]) {
        if (isalpha(buf[i]))
            no_letters++;
        else if (isdigit(buf[i[))
            no_digits++;
        else if (ispunct(buf[i]))
            no_punctuation++;

        i++
    }

    printf("\nYour string contained %d letters, %d digits and %d punctuation characters.\n", no_letters, no_digits, no_punctuation);
    return 0;
}
