#include <stdio.h>

int func_name();

int main()
{
	/* auto is not c++ compatible */
	auto int x;	// auto/local variable

	return 0;
}

int func_name()
{
	auto int y;	// auto/local variable

	return y;
}
