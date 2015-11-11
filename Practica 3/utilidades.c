#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Divide la cadena en trozos de un vector
int dividircadena(char * cadena, char * trozos[]) {
   int i = 1;
   if((trozos[0] = strtok(cadena, " \n\t")) == NULL) { return 0; }
   while((trozos[i] = strtok(NULL, " \n\t")) != NULL) { i++; }
   return i;
}

// Devuelve el tamaño de los trozos
int tamannotrozos(char * trozos[]) {
   int tamanno = 0;
   int i = 0;
   while (trozos[i] != NULL) {
      tamanno += strlen(trozos[i]); i++;
   }

   return tamanno+1;
}

// Junta trozos de un vector en una cadena
int juntarvector(char * cadena, char * trozos[]) {
   int i = 1;
   sprintf(cadena, "%s", trozos[0]);
   while (trozos[i] !=  NULL) {
      sprintf(cadena, "%s%s", cadena, trozos[i]); i++;
   }

   return i;
}
