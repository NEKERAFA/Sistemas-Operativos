# Makefile del shell

CC = gcc
CFLAGS = -g -Wall
OBJ_FUN = funciones.o
OBJS = lista.o procesos.o utilidades.o memoria.o malloc.o
OBJ_SHELL = shell.out
OBJ_MAIN = main.c funciones.c lista.c procesos.c

all: shell.out


shell.out: utilidades.o procesos.o lista.o memoria.o malloc.o funciones.o main.c
	echo 'Compilando terminal...'
	$(CC) $(CFLAGS) main.c $(OBJ_FUN) $(OBJS) -o $(OBJ_SHELL)

funciones.o: funciones.c funciones.h lista.o
	echo 'Compilando funciones...'
	$(CC) $(CFLAGS) -c funciones.c

utilidades.o: utilidades.c utilidades.h
	echo 'Compilando utilidades...'
	$(CC) $(CFLAGS) -c utilidades.c

lista.o: lista.c lista.h
	echo 'Compilando modulo lista'
	$(CC) $(CFLAGS) -c lista.c

procesos.o: procesos.c procesos.h
	echo 'Compilando modulo proceso'
	$(CC) $(CFLAGS) -c procesos.c

memoria.o: memoria.c memoria.h
	echo 'Compilando modulo memoria'
	$(CC) $(CFLAGS) -c memoria.c

malloc.o: malloc.c malloc.h
	echo 'Compilando modulo malloc'
	$(CC) $(CFLAGS) -c malloc.c

clean:
	echo 'Limpiando...'
	rm -fv *.o $(OBJ_SHELL) 


