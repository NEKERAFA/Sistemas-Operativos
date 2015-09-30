# Makefile del shell

CC = gcc
CFLAGS = -O2
OBJS = funciones.o
OBJ_NAME = shell

all: funciones
	echo -e '\e[32mCompilando terminal...\e[0m'
	$(CC) $(CFLAGS) main.c $(OBJS) -o $(OBJ_NAME)

funciones:
	echo -e '\e[32mCompilando funciones...\e[0m'
	rm -f funciones.o
	$(CC) $(CFLAGS) -c funciones.c

gdb:
	echo -e '\e[32mCompilando en modo debug...\e[0m'
	$(CC) -g -O0 main.c funciones.c -o $(OBJ_NAME)

clean:
	echo -e '\e[32mLimpiando...\e[0m'
	rm -f *.o shell list deltree
