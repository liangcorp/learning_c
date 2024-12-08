#include <stdio.h>
#include <malloc.h>

int main()
{
	int *restrict int_ptr_a;
	int *restrict int_ptr_b;

	/*
       compiler hint.
       tell the compiler that, for the duration of the scope in which
       int_ptr_a and int_ptr_b are define. They will never access the
       same value

       their use for pointing to integers inside an array is mutually
       exclusive
    */

    int n;
	int array[10];
	int *restrict restar = (int *)malloc(10 * sizeof(int));
	int *par = array;

    for (n = 0; n < 10; n++) {
        par[n] += 5;
        restar[n] += 5;
        array[n] *= 2;
        par[n] += 3;
        restar[n] += 3;
        //  this is the same as restar[n] += 8;
    }

	return 0;
}
