#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include "lista.h"
#include "mmap.h"
#include "utilidades.h"

static datommap* creardatommap(){
   datommap *tmp = malloc (sizeof(datommap));

   if (tmp == NULL){
      printf("Memoria agotada \n");
      exit(EXIT_FAILURE);
   }

   return tmp;
}

datommap* nuevodatommap( dir_t dir, char * nombre, int dfile, size_t tamanno, time_t hora_ini ) {
   datommap * d = creardatommap();
   d->dir = dir;
   d->tamanno = tamanno;
   d->hora_ini = hora_ini;
   return d;
}

void eliminardatommap(datomalloc *d){
   free(d->dir);
   free(d);
}

/* void Cmd_Mmap (char *arg[]) {
   char * fichero, *perm;
   void *p;
   struct stat s;
   int df, protection=0,map=MAP_PRIVATE,modo=O_RDONLY;
   if ((fichero=arg[0])==NULL)
   { ListarDirecciones(DIRMMAP); return;}
   if (!strcmp (arg[1],"-deassign"))
   { MmapDeassign(arg[2]); return;}
   if ((perm=arg[2])!=NULL && strlen(perm)<4) {
   if (strchr(perm,’r’)!=NULL) protection|=PROT_READ;
   if (strchr(perm,’w’)!=NULL) protection|=PROT_WRITE;
   if (strchr(perm,’x’)!=NULL) protection|=PROT_EXEC;
   }
   if (protection&PROT_WRITE) modo=O_RDWR;
   if (stat(fichero,&s)==-1 || (df=open(fichero, modo))==-1)
   7
   { perror ("imposible acceder al fichero"); return; }
   if ((p=mmap (NULL,s.st_size, protection,map,df,0))==MAP_FAILED)
   { perror ("error mmap");close(df); return; }
   close(df);
   printf ("fichero %s mapeado en %p\n", fichero, p);
   GuardarDireccionMmap (p, s.st_size,fichero,df);
} */
