#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "lista.h"
#include "mshared.h"
#include "utilidades.h"

static datomshared* creardatomshared() {
   datomshared *tmp = malloc (sizeof(datomshared));
   if (tmp == NULL){
      printf("Memoria agotada \n");
      exit(EXIT_FAILURE);
   }
   return tmp;
}

datomshared * nuevodatomshared ( dir_t dir, int key, size_t tamanno, time_t hora_ini ){
   datomshared * d = creardatomshared();
   d->dir = dir;
   d->key = key;
   d->tamanno = tamanno;
   d->hora_ini = hora_ini;
   return d;
}

void eliminardatomshared( datomshared *d ) {
   munmap(d->dir, d->tamanno);
   free(d);
}

posicion buscardatomshared( size_t tamanno, lista l ){
   datomshared * aux;

   if (esListaVacia(l)) return NULL;
   posicion p = primera(l);
   aux = getDato(p,l);
   while (!esfindelista(p, l) && (aux->tamanno!=tamanno)){
      aux = getDato(p,l);
      siguiente(p, l);
   }
   if (aux->tamanno == tamanno) return p;
   return NULL;
}

void insertarmshared(dir_t dir, size_t tamanno, int key, lista l ) {
     
   time_t tiempoactual = time(NULL);
   datomshared *mem = nuevodatomshared(dir, key, tamanno, tiempoactual);
   insertar(mem, l);
}


void mostrarmshared( datomshared *d, lista l ) {
   printf("%p: tamaño: %li. shared key: %d ", d->dir, d->tamanno, d->key);
   imprimirFecha(d->hora_ini);
   printf("\n");
}

void * ObtenerMemoriaShmget (key_t clave, off_t tam,lista l){
   void * p;
   int aux,id,flags=0777;
   struct shmid_ds s;
   if (tam)
      flags=flags | IPC_CREAT | IPC_EXCL;
   if (clave==IPC_PRIVATE) /*no nos vale*/
      {errno=EINVAL; return NULL;}
   if ((id=shmget(clave, tam, flags))==-1)
      return (NULL);
   if ((p=shmat(id,NULL,0))==(void*) -1){
      aux=errno;
   if (tam)
         shmctl(id,IPC_RMID,NULL);
      errno=aux;
      return (NULL);
   }
   shmctl (id,IPC_STAT,&s);
   insertarmshared(p, s.shm_segsz, clave,l);
   return (p);
}