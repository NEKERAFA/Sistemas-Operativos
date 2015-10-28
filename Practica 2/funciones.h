#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

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
void getprioridad(char * parametro);

// Establece la prioridad
void setprioridad(int argc, char * argv[]);

// Ejecuta un programa sin crear un proceso nuevo
void execprog(char * argv[]);

// Ejecuta un programa sin crear un proceso nuevo
void execprogpri(int argc, char * argv[]);

// Crea un proceso en primer plano
void primerplanopri(int argc, char * argv[]);

#endif // _FUNCIONES_H_
