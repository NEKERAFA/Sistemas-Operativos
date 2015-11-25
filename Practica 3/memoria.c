#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>
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

void eliminardatomshared(datomalloc *d){
   shmdt(d->dir);
   free(d);
}

posicion buscardatomem(dir_t pid, lista l) {
   datoproc * aux;

   if (esListaVacia(l)) return NULL;
   posicion p = primera(l);

   aux = getDato(p,l);

   while (!esfindelista(p, l) && aux->pid != pid){
      aux = getDato(p,l);
      siguiente(p, l);
   }
   if (aux->pid == pid) return p;
   return NULL;
}
