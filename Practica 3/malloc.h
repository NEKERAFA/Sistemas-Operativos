#ifndef _MALLOC_H_
#define _MALLOC_H_
#include "memoria.h"
#include "lista.h"

// Tipo de dato malloc
typedef struct {
   dir_t dir;
   size_t tamanno;
   time_t hora_ini;
} datomalloc;

// Esta función devuelve un nuevo dato con todos los parámetros inicializados
datomalloc* nuevodatomalloc( dir_t dir, size_t tamanno, time_t hora_ini );

// Esta función elimina un dato.
void eliminardatomalloc( datomalloc *d );

// Inserta una posicion de memoria con malloc al final de la lista de malloc
void insertarmalloc( size_t tamanno, lista l );

// Mostrar malloc
void mostrarmalloc( dir_t dir, lista l );

// Elimina un malloc
void eliminarmalloc( datomalloc*, lista l);

#endif // _MEMORIA_H_
