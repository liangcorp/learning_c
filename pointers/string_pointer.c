/* void copy_string(char to[], char from[])
{
    int i;
    for (i = 0; from[i] != '\0'; ++i)
        to[i] = from[i];

    to[i] = '\0';
}

void copy_string2(char *to, char *from)
{
    for ( ; *from != '\0'; ++from, ++to)
        *to = *from;
    *to = '\0';

} */

void copy_string (char *to, char *from)
{
    while ( *from )         // The null character is equal
        *to++ = *from++;    // to the value 0, so will jump out then

    *to = '\0';
}

int main(void)
{
    char string1[] = "A string to be copied.";
    char string2[50];

    copy_string(string2, string1);
    printf("%s\n", string2);
}
