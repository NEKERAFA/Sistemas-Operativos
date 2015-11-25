#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include "lista.h"
#include "memoria.h"
#include "utilidades.h"

static datomalloc *creardatomalloc(){
   datomalloc *tmp = malloc (sizeof(datomalloc));

   if (tmp == NULL){
      printf("Memoria agotada \n");
      exit(EXIT_FAILURE);
   }

   return tmp;
}

static datommap *creardatommap(){
   datommap *tmp = malloc (sizeof(datommap));

   if (tmp == NULL){
      printf("Memoria agotada \n");
      exit(EXIT_FAILURE);
   }

   return tmp;
}

static datomshared *creardatomshared(){
   datomshared *tmp = malloc (sizeof(datomshared));

   if (tmp == NULL){
      printf("Memoria agotada \n");
      exit(EXIT_FAILURE);
   }

   return tmp;
}

datomalloc* nuevodatomalloc(dir_t dir, size_t tamanno, time_t hora_ini) {
   datomalloc * d = creardatomalloc();

   d->dir = dir;
   d->tamanno = tamanno;
   d->hora_ini = hora_ini;

   return d;
}

datommap* nuevodatommap(dir_t dir, size_t tamanno, char * nombre, int dfile, time_t hora_ini) {
   datommap * d = creardatommap();

   d->dir = dir;
   d->tamanno = tamanno;
   d->nombre = nombre;
   d->dfile = dfile;
   d->hora_ini = hora_ini;

   return d;
}

datomshared* nuevodatoshared(dir_t dir, size_t tamanno, int key, time_t hora_ini) {
   datomshared * d = creardatomshared();

   d->dir = dir;
   d->tamanno = tamanno;
   d->key = key;
   d->hora_ini = hora_ini;

   return d;
}
void eliminardatomalloc(datomalloc *d){
   free(d->dir);
   free(d);
}

void eliminardatommap(datommap *d){
   munmap(d->dir, d->tamanno);
   free(d);
}

void eliminardatomshared(datomshared *d){
   shmdt(d->dir);
   free(d);
}

posicion buscardatomem(dir_t dir, lista l) {
   if (esListaVacia(l)) return NULL;
   posicion p = primera(l);
   while (!esfindelista(p, l) && getDato(p,l)->dir != dir){
      siguiente(p, l);
   }
   if (getDato(p,l)->dir == dir) return p;
   return NULL;
}
