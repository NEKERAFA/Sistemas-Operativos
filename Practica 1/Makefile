# Makefile del shell

CC = gcc
CFLAGS = -O2
OBJS = funciones.o
OBJ_SHELL = shell.out
OBJ_LISTA = lista.out

all: funciones
	echo -e '\e[32mCompilando terminal...\e[0m'
	$(CC) $(CFLAGS) main.c $(OBJS) -o $(OBJ_SHELL)

funciones:
	echo -e '\e[32mCompilando funciones...\e[0m'
	rm -f funciones.o
	$(CC) $(CFLAGS) -c funciones.c

lista: funciones
	echo -e '\e[32mCompilando modulo lista\e[0m'
	$(CC) $(CFLAGS) lista.c $(OBJS) -o $(OBJ_LISTA)

gdb:
	echo -e '\e[32mCompilando en modo debug...\e[0m'
	$(CC) -g -O0 main.c funciones.c -o $(OBJ_SHELL)
	$(CC) -g -O0 lista.c funciones.c -o $(OBJ_LISTA)

clean:
	echo -e '\e[32mLimpiando...\e[0m'
	rm -f *.o shell list deltree
