#include <stdio.h>
#include <stdlib.h>

#define LINE_ITEM 5
#define MAX 100

int is_prime(const int n)
{
    int i = n - 1;

    while (i != 1) {
        if (n % i == 0)
            return 0;
        i--;
    }

    return 1;
}

int main()
{
    FILE *fp = NULL;

    if ((fp = fopen("myfile.txt", "r")) == NULL) {
        fprintf(stderr, "ERROR: %s\n", "Failed to open file");
        return 1;
    }

    int i;
    int a[LINE_ITEM];
    char buf[MAX];

    while (fgets(buf, MAX, fp) != 0) {
        sscanf(buf, "%d %d %d %d %d", a, a + 1, a + 2, a + 3, a + 4);

        for (i = 0; i < LINE_ITEM; i++)
            if (a[i] % 2 == 0)
                printf("Even number found: %d\n", a[i]);
            else if (is_prime(a[i]))
                printf("Prime number found: %d\n", a[i]);
            else
                printf("Odd number found: %d\n", a[i]);
    }

    fclose(fp);
    fp = NULL;

    return 0;
}
