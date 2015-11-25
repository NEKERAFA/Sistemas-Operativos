#ifndef _MEMORIA_H_
#define _MEMORIA_H_
#include "lista.h"

#define MALL "mmalloc"
#define MMAP "mmap"
#define MSHR "mshr"

typedef void* dir_t;

// Tipo de dato malloc
typedef struct {
   dir_t dir;
} datomem;

// Esta función devuelve la posición en la que está un dato cuyo campo dir sea el pasado por parámetro
// Devuelve NULL si no encuentra el dato
posicion buscardatomem(dir_t dir, lista l);

#endif // _MEMORIA_H_
