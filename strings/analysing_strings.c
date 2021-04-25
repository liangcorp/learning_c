#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[100];      // input buffer
    int n_letters = 0;  // number of letters in input
    int n_digits = 0;   // number of digits in input
    int n_punct = 0;    // number of puncuation characters

    printf("Enter an interesting string of less than %d characters:\n", 100);
    scanf("%s", buf);   // read a string into buffer

    int i = 0;          // buffer index
    while (buf[i])
    {
        if (isalpha(buf[i]))
            ++n_letters;    // increment letter count
        else if (isdigit(buf[i]))
            ++n_digits;     // increment digit count
        else if (ispunct(buf[i]))
            ++n_punct;

        ++i;
    }

    printf("\n Your string contained %d letters,"
            "%d digits and %d punctuation characters.\n",
            n_letters, n_digits, n_punct);
}
