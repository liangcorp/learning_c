#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void my_function()
{
	printf("in my_function()\n");
	longjmp(buf, 1);

	/* NOT REACHED */
	printf("You will never see this, because longjump\n");
}

int main()
{
	if (setjmp(buf)) {
		printf("back in main\n");
	} else {
		printf("first time through\n");
		my_function();
	}

	int i = setjmp(buf);

	printf("i = %d\n", i);

	if (i != 0)
		exit(0);

	longjmp(buf, 42);
	printf("Does this long et printed?\n");

	return 0;
}
