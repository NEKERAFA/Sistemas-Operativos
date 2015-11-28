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
#include "lista.h"
#include "mmap.h"
#include "utilidades.h"

static datommap* creardatommap() {
   datommap *tmp = malloc (sizeof(datommap));
   if (tmp == NULL){
      printf("Memoria agotada \n");
      exit(EXIT_FAILURE);
   }
   return tmp;
}

datommap* nuevodatommap(dir_t dir, char * nombre, int df, size_t tamanno, time_t hora_ini) {
   datommap * d = creardatommap();
   d->dir = dir;
   d->nombre = nombre;
   d->df = df;
   d->tamanno = tamanno;
   d->hora_ini = hora_ini;
   return d;
}

void eliminardatommap(datommap *d) {
   close(d->df);
   free(d->dir);
   free(d);
}

posicion buscardatommap(char * nombre, lista l) {
   datommap * aux;

   if (esListaVacia(l)) return NULL;
   posicion p = primera(l);
   aux = getDato(p,l);
   while (!esfindelista(p, l) && strcmp(aux->nombre, nombre)){
      aux = getDato(p,l);
      siguiente(p, l);
      printf("%s\n", nombre);
   }
   if (!strcmp(aux->nombre, nombre)) return p;
   return NULL;
}

int proteccionfichero(char * perm) {
   int prot = 0;
   if(perm != NULL && strlen(perm) < 4) {
      if(strchr(perm, 'r')!=NULL) prot |= PROT_READ;
      if(strchr(perm, 'w')!=NULL) prot |= PROT_WRITE;
      if(strchr(perm, 'x')!=NULL) prot |= PROT_EXEC;
   }
   return prot;
}

void insertarmmap(char * file, char * perm, lista l) {
   int prot = 0, map = MAP_PRIVATE, modo = O_RDONLY, df;
   dir_t dir; struct stat s;

   prot = proteccionfichero(perm);
   if(prot & PROT_WRITE) modo = O_RDWR;

   if(stat(file, &s) == -1 || (df = open(file, modo)) == -1)
      perror("Imposible acceder al fichero.");
   else
      if ((dir = mmap(NULL, s.st_size, prot, map, df, 0)) == MAP_FAILED) {
         perror("Error al mapear fichero"); close(df);
      } else {
         time_t tiempoactual = time(NULL);
         datommap *mem = nuevodatommap(dir, file, df, s.st_size, tiempoactual);
         insertar(mem, l);
         printf("Fichero %s mapeado en %p\n", file, dir);
      }
}


void mostrarmmap(datommap *d, lista l) {
   printf("%p: tamaño: %li. mmap %s ", d->dir, d->tamanno, d->nombre);
   imprimirFecha(d->hora_ini);
   printf("\n");
}
