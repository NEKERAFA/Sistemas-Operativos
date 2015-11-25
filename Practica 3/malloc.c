#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include "lista.h"
#include "malloc.h"
#include "utilidades.h"

static datomalloc* creardatomalloc(){
   datomalloc *tmp = malloc (sizeof(datomalloc));

   if (tmp == NULL){
      printf("Memoria agotada \n");
      exit(EXIT_FAILURE);
   }

   return tmp;
}

datomalloc* nuevodatomalloc(dir_t dir, size_t tamanno, time_t hora_ini){
   datomalloc * d = creardatomalloc();
   d->dir = dir;
   d->tamanno = tamanno;
   d->hora_ini = hora_ini;
   return d;
}

void eliminardatomalloc(datomalloc *d){
   free(d->dir);
   free(d);
}

void insertarmalloc(size_t tamanno, lista l) {
   dir_t dir = (void*) malloc(tamanno);
   time_t tiempoactual = time(NULL);
   datomalloc *mem = nuevodatomalloc(dir, tamanno, tiempoactual);

   insertar(mem, l);
}

void mostrarmalloc(datomalloc *d, lista l) {

}

// Elimina un malloc
void eliminarmalloc( datomalloc*, lista l);
