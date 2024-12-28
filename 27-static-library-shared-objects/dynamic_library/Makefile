CC=gcc

dynamic:
	cd libs
	${CC} -g -fPIC myLib.c -shared -o libmylib.so
	cd ..
	${CC} -I ./libs/ -c main.c -o main.o
	${CC} -o main main.o -L./libs/ -l mylib
