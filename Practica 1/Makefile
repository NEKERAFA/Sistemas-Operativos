# Makefile del shell

CC = gcc
CFLAGS = -g
OBJS = funciones.o
OBJ_SHELL = shell.out
OBJ_LISTA = lista.out
OBJ_DELTR = deltree.out

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

deltree: funciones
	echo -e '\e[32mCompilando modulo deltree\e[0m'
	$(CC) $(CFLAGS) deltree.c $(OBJS) -o $(OBJ_DELTR)

gdb:
	echo -e '\e[32mCompilando en modo debug...\e[0m'
	$(CC) -g -O0 main.c funciones.c -o $(OBJ_SHELL)
	$(CC) -g -O0 lista.c funciones.c -o $(OBJ_LISTA)
	$(CC) -g -O0 deltree.c funciones.c -o $(OBJ_DELTR)

clean:
	echo -e '\e[32mLimpiando...\e[0m'
	rm -f *.o $(OBJ_SHELL) $(OBJ_LISTA) $(OBJ_DELTR)

prueba:
	mkdir ~/Escritorio/a/
	mkdir ~/Escritorio/a/b/
	mkdir ~/Escritorio/a/b/c/
	mkdir ~/Escritorio/a/b/c/d/

	touch ~/Escritorio/a/b/t.txt
	touch ~/Escritorio/a/b/skynet.txt
