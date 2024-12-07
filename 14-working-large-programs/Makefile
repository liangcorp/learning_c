SRC = mod1.c mod2.c main.c

OBJ = mod1.o mod2.o main.o

# PROG files are dependent of OBJ files
PROG = my_program$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

# OBJ file are dependent of SRC
$(OBJ): $(SRC)
