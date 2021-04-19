#include <stdio.h>

int fun()
{
	static int count = 0;
	int local_var = 0;

	printf("automatic = %d, static = %d\n", local_var, count);

	local_var++;
	count++;
	return count;
}

int main()
{
	for(int i=0; i<5; i++)
	{
		fun();
	}
	return 0;
}
