#include <stdio.h>
#include <string.h>

//  deprecated
//  only use if no NULL character in data

int main()
{
	char buf[255];
	int ch = '\0';

	char *p = NULL;

	if (fgets(buf, sizeof(buf), stdin)) {
		p = strchr(buf, '\n');

		if (p) {
			*p = '\0';
		} else {
			while (((ch = getchar()) != '\n') && !feof(stdin) &&
			       !ferror(stdin))
				;
		}
	} else {
		/* fgets failed, handle error */
	}

    printf("%s\n", buf);

	return 0;
}
