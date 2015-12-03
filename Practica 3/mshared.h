#ifndef _MSHARED_H_
#define _MSHARED_H_

#include "memoria.h"
#include "lista.h"

// Tipo de dato mshared
typedef struct {
   dir_t dir;
   int key;
   size_t tamanno;
   time_t hora_ini;
} datomshared;

// Esta función devuelve un nuevo dato con todos los parámetros inicializados
datomshared * nuevodatomshared( dir_t dir, int key, size_t tamanno, time_t hora_ini );

// Esta función elimina un dato.
void eliminardatomshared( datomshared *d );

// Esta función devuelve la posición en la que está un dato cuyo campo key sea el pasado por parámetro
// Devuelve NULL si no encuentra el dato
posicion buscardatomshared( size_t tammano, lista l );

// Inserta una posicion de memoria con malloc al final de la lista de mshared
void insertarmshared(dir_t dir, size_t tamanno, int key, lista l );

// Mostrar mshared
void mostrarmshared( datomshared *d, lista l );

void * ObtenerMemoriaShmget (key_t clave, off_t tam, lista l);

#endif