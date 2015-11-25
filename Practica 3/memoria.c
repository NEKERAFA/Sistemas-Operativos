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

posicion buscardatop(dir_t dir, lista l) {
   datomem * aux;

   if (esListaVacia(l)) return NULL;
   posicion p = primera(l);

   aux = getDato(p,l);

   while (!esfindelista(p, l) && aux->dir != dir){
      aux = getDato(p,l);
      siguiente(p, l);
   }
   if (aux->dir == dir) return p;
   return NULL;
}
