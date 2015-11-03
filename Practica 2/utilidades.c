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

// Junta trozos de un vector en una cadena
int juntarvector(char * cadena, char * trozos[]) {
   int i = 0;
   int tamanno = 0;
   while (trozos[i] != NULL) {
      tamanno += strlen(trozos[i]); i++;
   }

   cadena = (char *) malloc((tamanno+1)*sizeof(char));

   i = 0;
   while (trozos[i] !=  NULL) {
      sprintf(cadena, "%s", trozos[i]); i++;
   }

   return i;
}
