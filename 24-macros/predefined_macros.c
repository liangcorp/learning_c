#include <stdio.h>

void sample_function()
{
	printf("Current function name: %s", __func__);
}

int main()
{
	if (__STDC__ == 1)
		printf("Implementation is ISO-conforming.\n");

	char current_filename[] = __FILE__;

	int current_line_number = __LINE__;

	char date_of_compilation[] = __DATE__;

	char time_of_compilation[] = __TIME__;

	return 0;
}
