#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery(char *error)
{
	printf("%s\n", error);
	longjmp(buf, 1);
}

int main()
{
	int i;
	char *error = "UNRECOVERABLE ERROR!";

	while (1) {
		if (setjmp(buf)) {
            printf("back in main\n");
			break;
        }
		else
			error_recovery(error);
	}

	return 0;
}
