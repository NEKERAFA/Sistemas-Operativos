#ifndef _MMAP_H_
#define _MMAP_H_
#include "memoria.h"
#include "lista.h"

// Tipo de dato mmap
typedef struct {
   dir_t dir;
   char * nombre;
   int dfile;
   size_t tamanno;
   time_t hora_ini;
} datommap;

// Esta función devuelve un nuevo dato con todos los parámetros inicializados
datommap* nuevodatommap( dir_t dir, char * nombre, int dfile, size_t tamanno, time_t hora_ini );

// Esta función elimina un dato.
void eliminardatommap( datommap *d );

// Esta función devuelve la posición en la que está un dato cuyo campo pid sea el pasado por parámetro
// Devuelve NULL si no encuentra el dato
posicion buscardatommap( size_t tamanno, lista l );

// Inserta una posicion de memoria con malloc al final de la lista de malloc
void insertarmmap( char * file, lista l );

// Mostrar malloc
void mostrarmmap( datommap *d, lista l );

#endif // _MALLOC_H_
