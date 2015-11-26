#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

void imprimirFecha(time_t fecha) {
   struct tm * tmFecha = (struct tm *) malloc(sizeof(struct tm));
   localtime_r(&fecha, tmFecha);
   char * sfecha = (char *) malloc(32*sizeof(char));
   strftime(sfecha, 32*sizeof(char), "%a %b %d %X %Y", tmFecha);
   printf("%s", sfecha);
   free(sfecha);
   free(tmFecha);
}
