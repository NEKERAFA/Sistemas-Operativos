#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include "lista.h"

enum {HIDDEN_FILES = 1 << 0, SHORT_NAME = 1 << 1};

// Muestra en pantalla el pid actual o el pid padre
void pid( char * parametro );

// Muestra los autores
void author();

// Cambia de directorio
void changedir( char * dir, char * cur_dir );

// Elimina un archivo
void removefile( char * file );

// Lista un directorio
void listdir( int argc, char * argv[] );

//Elimina recursivamente directorios
void deltree( char * dir );

// Crea un hijo y espera a que el hijo termine
void dofork();

// Obtiene la prioridad
void getprioridad( char * parametro );

// Establece la prioridad
void setprioridad( int argc, char * argv[] );

// Ejecuta un programa sin crear un proceso nuevo
void execprog( char * argv[] );

// Ejecuta un programa sin crear un proceso nuevo
void execprogpri( int argc, char * argv[] );

// Crea un proceso en primer plano
void primerplano( char * argv[] );

// Crea un proceso en primer plano con prioridad
void primerplanopri( int argc, char * argv[] );

// Crea un proceso en segundo plano
void segundoplano(char * argv[], lista l);

//Crea un proceso en segundo plano con prioridad
void segundoplanopri(int argc, char *argv[],lista l);

//Muestra los procesos en segundo plano de la terminal
void jobs(int n,char * trozos[], lista l);

//Borra de la lista de procesos en segundo plano todos aquellos que han terminado
void clearjobs(lista l);

// Función recursiva
void showrecursive(char * number);

// Imprime el contenido de Memoria
void memdump(char* dir, char* count);

// Muestra las credenciales
void changeuid(char * argv[]);

// Muestra las direcciones
void showdir();

// Muestra/Reserva memoria
void mmalloc();

// Muestra las listas de memoria
void showmem( lista lalloc, lista lmap );

#endif // _FUNCIONES_H_
