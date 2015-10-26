# Makefile del shell

CC = gcc
CFLAGS = -g
OBJS = funciones.o
OBJ_SHELL = shell.out
OBJ_LISTAR = listar.out
OBJ_DELTR = deltree.out

all: funciones lista
	echo -e '\e[32mCompilando terminal...\e[0m'
	$(CC) $(CFLAGS) main.c $(OBJS) -o $(OBJ_SHELL)

funciones:
	echo -e '\e[32mCompilando funciones...\e[0m'
	rm -f funciones.o
	$(CC) $(CFLAGS) -c funciones.c

listar: funciones
	echo -e '\e[32mCompilando modulo listar\e[0m'
	$(CC) $(CFLAGS) listar.c $(OBJS) -o $(OBJ_LISTAR)

deltree: funciones
	echo -e '\e[32mCompilando modulo deltree\e[0m'
	$(CC) $(CFLAGS) deltree.c $(OBJS) -o $(OBJ_DELTR)

lista: 
	echo -e '\e[32mCompilando modulo lista\e[0m'
	$(CC) $(CFLAGS) -c lista.c

gdb:
	echo -e '\e[32mCompilando en modo debug...\e[0m'
	$(CC) -g -O0 main.c funciones.c -o $(OBJ_SHELL)
	$(CC) -g -O0 lista.c funciones.c -o $(OBJ_LISTA)
	$(CC) -g -O0 deltree.c funciones.c -o $(OBJ_DELTR)

clean:
	echo -e '\e[32mLimpiando...\e[0m'
	rm -f *.o $(OBJ_SHELL) $(OBJ_LISTA) $(OBJ_DELTR)

prueba_deltree:
	echo -e '\e[32mPrueba de la funcion deltree\e[0m'
	mkdir ~/Desktop/a/
	mkdir ~/Desktop/a/b/
	mkdir ~/Desktop/a/b/c/
	mkdir ~/Desktop/a/b/c/d/

	touch ~/Desktop/a/b/t.txt
	touch ~/Desktop/a/b/prueba.txt

	./deltree.out ~/Desktop/a/
