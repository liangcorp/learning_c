#include <stdio.h>

#define IS_UPPER(x) (x >= 'A' && x <= 'Z')
#define IS_LOWER(x) (x >= 'a' && x <= 'z')
#define IS_ALPHABET(x) (IS_LOWER(x) || IS_UPPER(x))

#define IS_VOWEL_LOWER(x) (x == 'a' || x == 'e' || x == 'i' \
                            || x == 'o' || x == 'u')
#define IS_VOWEL_UPPER(x) (x == 'A' || x == 'E' || \
                            x == 'I' || x == 'O' || x == 'U')
#define IS_VOWEL(x) (IS_VOWEL_LOWER(x) || IS_VOWEL_UPPER(x))

#define IS_DIGIT(x) (x >= '0' && x <= '9')
#define IS_ALPHANUMBERIC(x) (IS_ALPHABET(x) || IS_DIGIT(X))

#define IS_WHITE_SPACE(x) (x == ' ' || x == '\t' || \
                            x =='\r' || x == '\n')
#define IS_SPECIAL_CHARACTERS(x) (x >= 32 && \
                                    x <= 127 && \
                                    !IS_ALPHABET(x) && \
                                    !IS_DIGIT(x) && \
                                    !IS_WHITE_SPACE(x))
int main(void)
{
    char c = '\0';
    printf("Enter a letter: ");
    c = getchar();

    if IS_UPPER(c)
        printf("Upper\n");
    else if IS_LOWER(c)
        printf("Lower\n");
    else
        printf("Error!\n");

    return 0;

    return 0;
}
