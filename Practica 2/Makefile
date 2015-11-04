# Makefile del shell

CC = gcc
CFLAGS = -g -Wall
OBJ_FUN = funciones.o
OBJS = lista.o procesos.o utilidades.o
OBJ_SHELL = shell.out
OBJ_LISTAR = listar.out
OBJ_DELTR = deltree.out
OBJ_MAIN = main.c funciones.c lista.c procesos.c

all: utilidades proceso lista funciones
	echo -e '\e[32mCompilando terminal...\e[0m'
	$(CC) $(CFLAGS) main.c $(OBJ_FUN) $(OBJS) -o $(OBJ_SHELL)

funciones: lista
	echo -e '\e[32mCompilando funciones...\e[0m'
	rm -f funciones.o
	$(CC) $(CFLAGS) -c funciones.c

utilidades:
	echo -e '\e[32mCompilando utilidades...\e[0m'
	rm -f utilidades.o
	$(CC) $(CFLAGS) -c utilidades.c

listar: funciones
	echo -e '\e[32mCompilando modulo listar\e[0m'
	$(CC) $(CFLAGS) listar.c $(OBJ_FUN) -o $(OBJ_LISTAR)

deltree: funciones
	echo -e '\e[32mCompilando modulo deltree\e[0m'
	$(CC) $(CFLAGS) deltree.c $(OBJ_FUN) -o $(OBJ_DELTR)

lista: 
	echo -e '\e[32mCompilando modulo lista\e[0m'
	$(CC) $(CFLAGS) -c lista.c

proceso: lista utilidades
	echo -e '\e[32mCompilando modulo proceso\e[0m'
	$(CC) $(CFLAGS) -c procesos.c

gdb:
	echo -e '\e[32mCompilando en modo debug...\e[0m'
	$(CC) -g -O0 $(OBJ_MAIN) -o $(OBJ_SHELL)
	$(CC) -g -O0 listar.c funciones.c -o $(OBJ_LISTAR)
	$(CC) -g -O0 deltree.c funciones.c -o $(OBJ_DELTR)

clean:
	echo -e '\e[32mLimpiando...\e[0m'
	rm -f *.o $(OBJ_SHELL) $(OBJ_LISTAR) $(OBJ_DELTR)

prueba_deltree:
	echo -e '\e[32mPrueba de la funcion deltree\e[0m'
	mkdir ~/Desktop/a/
	mkdir ~/Desktop/a/b/
	mkdir ~/Desktop/a/b/c/
	mkdir ~/Desktop/a/b/c/d/

	touch ~/Desktop/a/b/t.txt
	touch ~/Desktop/a/b/prueba.txt

