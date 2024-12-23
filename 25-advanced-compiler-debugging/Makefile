CC=gcc

all:
	${CC} main.c -o main

object_only:
	${CC} main.c -c

all_warning:
	${CC} -Wall main.c -o main

preprocess:
	${CC} -E main.c

assembly:
	${CC} -S main.c

save_temps:
	${CC} -save-temps main.c

math_lib:
	${CC} -Wall test.c -o main -l math

shared_lib:
	${CC} -c Wall -fPIC main.c
	${CC} -shared -o main.so main.o

debug:
	${CC} -g main.c

verbose:
	${CC} -v main.c

c89:
	${CC} -Wall -ansi main.c

unsighed_char:
	${CC} -Wall -funsighed-char main.c

define_macro:
	${CC} -DMY_MACRO main.c

warning_as_error:
	${CC} -Wall -Werror main.c
