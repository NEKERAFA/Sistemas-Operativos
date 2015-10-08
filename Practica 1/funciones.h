#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

// Flags de los parámetros
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

#endif // _FUNCIONES_H_
