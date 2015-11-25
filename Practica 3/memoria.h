#ifndef _MEMORIA_H_
#define _MEMORIA_H_
#include "lista.h"
#include <sys/ipc.h>
#include <sys/shm.h>

#define MALL "mmalloc"
#define MMAP "mmap"
#define MSHR "mshr"

typedef void* dir_t;

// Tipo de dato malloc
typedef struct dato {
   dir_t dir;
   size_t tamanno;
   time_t hora_ini;
} datomalloc;

// Tipo de dato mmap
typedef struct dato {
   dir_t dir;
   size_t tamanno;
   char * nombre;
   int dfile;
   time_t hora_ini;
} datommap;

// Tipo de dato mshared
typedef struct dato {
   dir_t dir;
   size_t tamanno;
   int key;
   time_t hora_ini;
} datomshared;

// Estas funciones devuelven un nuevo dato con todos los parámetros inicializados
datomalloc* nuevodatomalloc(dir_t dir, size_t tamanno, time_t hora_ini);
datommap* nuevodatommap(dir_t dir, size_t tamanno, char * nombre, int dfile, time_t hora_ini);
datomshared* nuevodatoshared(dir_t dir, size_t tamanno, int key, time_t hora_ini);

// Esta función elimina un dato
void eliminardatomalloc(datomalloc *d);
void eliminardatommap(datommap *d);
void eliminardatomshared(datomshared *d);

// Esta función devuelve la posición en la que está un dato cuyo campo dir sea el pasado por parámetro
// Devuelve NULL si no encuentra el dato
posicion buscardatomem(dir_t dir, lista l);

#endif // _MEMORIA_H_
