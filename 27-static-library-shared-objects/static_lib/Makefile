CC=gcc

static:
	cd libs
	${CC} -c myLib.c -o lib_mylib.o
	ar rcs lib_mylib.a lib_mylib.o
	cd ..
	${CC} -I ./libs/ -c main.c -o main.o
	${CC} -o main main.o ../libs/lib_mylib.a
