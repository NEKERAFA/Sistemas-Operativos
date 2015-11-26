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

posicion buscardatomalloc(size_t tamanno, lista l) {
   /*datomalloc * aux;
   if (esListaVacia(l)) return NULL;
   posicion p = primera(l);
   aux = getDato(p,l);
   while (!esfindelista(p, l) && aux->tamanno != tamanno) {
      aux = getDato(p,l);
      siguiente(p, l);
   }
   if (aux->tamanno == tamanno) return p;
   return NULL;*/

   datomalloc * aux;

   if (esListaVacia(l)) return NULL;
   posicion p = primera(l);
   aux = getDato(p,l);
   while (!esfindelista(p, l) && aux->tamanno != tamanno){
      aux = getDato(p,l);
      siguiente(p, l);
      printf("%li\n", tamanno);
   }
   if (aux->tamanno == tamanno) return p;
   return NULL;
}

void insertarmalloc(size_t tamanno, lista l) {
   dir_t dir = (void*) malloc(tamanno);
   if (dir == NULL)
      printf("Error al asignar %li en memoria. No hay espacio suficiente.\n", tamanno);
   else {
      time_t tiempoactual = time(NULL);
      datomalloc *mem = nuevodatomalloc(dir, tamanno, tiempoactual);
      insertar(mem, l);
      printf("asignado %li en %p\n", tamanno, dir);
   }
}

void mostrarmalloc(datomalloc *d, lista l) {
   printf("%p: tamaño: %li. malloc ", d->dir, d->tamanno);
   imprimirFecha(d->hora_ini);
   printf("\n");
}
