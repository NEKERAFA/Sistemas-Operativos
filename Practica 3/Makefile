# Makefile del shell

CC = gcc
CFLAGS = -g -Wall
OBJ_FUN = funciones.o
OBJS = lista.o procesos.o utilidades.o
OBJ_SHELL = shell.out
OBJ_MAIN = main.c funciones.c lista.c procesos.c

all: shell.out


shell.out: utilidades.o procesos.o lista.o funciones.o main.c
	echo -e '\e[32mCompilando terminal...\e[0m'
	$(CC) $(CFLAGS) main.c $(OBJ_FUN) $(OBJS) -o $(OBJ_SHELL)

funciones.o: funciones.c funciones.h  lista.o
	echo -e '\e[32mCompilando funciones...\e[0m'
	$(CC) $(CFLAGS) -c funciones.c

utilidades.o: utilidades.c utilidades.h
	echo -e '\e[32mCompilando utilidades...\e[0m'
	$(CC) $(CFLAGS) -c utilidades.c

lista.o: lista.c lista.h
	echo -e '\e[32mCompilando modulo lista\e[0m'
	$(CC) $(CFLAGS) -c lista.c

procesos.o: procesos.c procesos.h
	echo -e '\e[32mCompilando modulo proceso\e[0m'
	$(CC) $(CFLAGS) -c procesos.c

clean:
	echo -e '\e[32mLimpiando...\e[0m'
	rm -f *.o $(OBJ_SHELL) 


