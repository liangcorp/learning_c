#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
    void *handle = NULL;
    double (*cosine)(double) = NULL;    /* pointer to a function */
    char *error = NULL;

    handle = dlopen("/usr/lib64/libm.so.6", RTLD_LAZY);

    if (!handle)
    {
        fputs(dlerror(), stderr);
        exit(EXIT_FAILURE);
    }

    dlerror();      /* clear error code */

    cosine = dlsym(handle, "cos");

    if ((error = dlerror()) != NULL)
    {
        fputs(error, stderr);
        exit(EXIT_FAILURE);
    }

    printf("%f\n", (*cosine)(2.0));

    dlclose(handle);

    return 0;
}