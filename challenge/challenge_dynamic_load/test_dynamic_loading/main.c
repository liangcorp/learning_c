/* 
    Author: Chen Liang
    Description: The goal of this challege is to further 
                    your understanding of dynamic loading.
                You need to dynamically load the symbols 
                    from the shared object library file
    Date: 25 Apr 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <dlfcn.h>

void check_for_error(void)
{
    char *error = NULL;

    if ((error = dlerror()) != NULL)
    {
        fputs(error, stderr);
        exit(EXIT_FAILURE);
    }
}


int main(void)
{
    /* A void pointer to handle the dlopen library */
    void *handle = NULL;

    /* function pointers to accept the loaded functions */
    int (* freq_of_char)(const char, const char *) = NULL;
    char * (* rm_non_alphabet_char)(const char *) = NULL;
    int (* cal_len)(const char *) = NULL;
    char * (* str_concat)(const char *, const char *) = NULL;
    char * (* cp_str)(const char *) = NULL;
    _Bool (*fnd_sub_str)(const char *, const char *) = NULL;

    char *error = NULL;
    char *new_str = NULL;   /* created to be able to free memory */

    handle = dlopen("../string_functions/libstring_functions.so",
                                                    RTLD_LAZY);
    
    if (!handle)
    {
        fputs(dlerror(), stderr);
        exit(EXIT_FAILURE);
    }

    dlerror();      /* clear error code */

    freq_of_char = dlsym(handle, "frequency_of_char");
    check_for_error();
    printf("Frequency of W in \"World W\" is %d\n", 
                            freq_of_char('W', "World W"));

    rm_non_alphabet_char = dlsym(handle, "remove_all_char");
    check_for_error();
    new_str =  rm_non_alphabet_char("dwef32gid9A9_");
    printf("Remove non alphabet from \"dwef32gid9A9_\" is %s\n",
                                                            new_str);
    free(new_str);
    
    cal_len = dlsym(handle, "calculate_length");
    check_for_error();
    printf("The length of \"hello world\" is %d\n",
                            cal_len("hello world"));

    str_concat = dlsym(handle, "string_concatenation");
    check_for_error();
    new_str = str_concat("Chen", " Liang");
    printf("String concatination of \"Chen\" and \" Liang\" is %s\n",
                                                            new_str); 
    free(new_str);

    cp_str = dlsym(handle, "copy_string");
    check_for_error();
    new_str = cp_str("Hello");
    printf("Copy string \"Hello\" is %s\n", new_str);
    free(new_str);

    fnd_sub_str = dlsym(handle, "found_substring");
    check_for_error();
    if (fnd_sub_str("orl", "World") == 1)
        printf("\"World\" contains \"orl\"\n");
    else
        printf("\"World\" doesn't contain \"orl\"\n");

    dlclose(handle);

    return 0;
}
