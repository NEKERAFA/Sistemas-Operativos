#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funciones.h"
#include "procesos.h"
#include "utilidades.h"
#include "lista.h"

int const TAM_ENTRADA = 1024;

typedef struct {
   lista proc;
   lista mmalloc;
   lista mmap;
   lista mshared;
} listas;

// Prompt del shell
void prompt() {
   printf("~$ ");
}

void leerentrada(char * entrada, int tamano_entrada) {
   char * retorno_entrada;
   retorno_entrada = fgets(entrada, tamano_entrada, stdin);
   if (retorno_entrada == NULL) {
      perror("Error en la entrada");
   }
}

// Procesa la entrada para ejecutar los comandos
void procesarentrada(char * entrada, char * dir_act, listas l, int * salir) {
   char * c_parametros[TAM_ENTRADA/4];
   int n_parametros;
   n_parametros = dividircadena(entrada, c_parametros);

   if (n_parametros > 0) {
      if((!strcmp(c_parametros[0], "exit")) || (!strcmp(c_parametros[0], "quit")) || (!strcmp(c_parametros[0], "fin"))) {
         *salir = 1;
      } else if (!strcmp(c_parametros[0], "pid")) {
         pid(c_parametros[1]);
      } else if (!strcmp(c_parametros[0], "autores")) {
         author();
      } else if (!strcmp(c_parametros[0], "cd")) {
         changedir(c_parametros[1], dir_act);
      } else if (!strcmp(c_parametros[0], "list")) {
         listdir(n_parametros-1, c_parametros+1);
      } else if (!strcmp(c_parametros[0], "delete")) {
         removefile(c_parametros[1]);
      } else if (!strcmp(c_parametros[0], "getpriority")) {
         getprioridad(c_parametros[1]);
      } else if (!strcmp(c_parametros[0], "setpriority")) {
         setprioridad(n_parametros-1, c_parametros+1);
      } else if (!strcmp(c_parametros[0], "dofork")) {
         dofork();
      } else if (!strcmp(c_parametros[0], "exec")) {
         execprog(c_parametros+1);
      } else if (!strcmp(c_parametros[0], "execpri")) {
         execprogpri(n_parametros-1, c_parametros+1);
      } else if (!strcmp(c_parametros[0], "pplano")) {
         primerplano(c_parametros+1);
      } else if (!strcmp(c_parametros[0], "pplanopri")) {
         primerplanopri(n_parametros-1, c_parametros+1);
      } else if (!strcmp(c_parametros[0], "splano")) {
         segundoplano(c_parametros+1, l.proc);
      } else if (!strcmp(c_parametros[0], "splanopri")) {
         segundoplanopri(n_parametros-1, c_parametros+1,  l.proc);
      } else if (!strcmp(c_parametros[0], "jobs")) {
         jobs(n_parametros-1,c_parametros+1, l.proc);
      } else if (!strcmp(c_parametros[0], "clearjobs")) {
         clearjobs(l.proc);
      } else if (!strcmp(c_parametros[0], "memdump")) {
         memdump(c_parametros[1], c_parametros[2]);
      } else if (!strcmp(c_parametros[0], "uid")) {
         changeuid(c_parametros+1);
      } else if (!strcmp(c_parametros[0], "recursiva")) {
         showrecursive(c_parametros[1]);
      } else if (!strcmp(c_parametros[0], "direcciones")) {
         showdir();
      } else if (!strcmp(c_parametros[0], "mmalloc")) {
         mmalloc(l.mmalloc);
      } else {
         primerplano(c_parametros);
      }
   }
}

// Bucle principal
int main(int argc, char const *argv[]) {
   int fin = 0;
   char entrada[TAM_ENTRADA];
   char dir_act[2048];
   listas l;
   l.proc = crearlista();
   l.mmalloc = crearlista();

   if (getcwd(dir_act, 2048) == NULL) {
      perror("Imposible obtener el directorio actual");
      exit(-1);
   }

   printf("\n");
   printf("Interprete de comando en UNIX\n");
   while(!fin) {
      prompt();
      leerentrada(entrada, TAM_ENTRADA);
      procesarentrada(entrada, dir_act, l, &fin);
   }

   eliminarLista(&eliminardatop,&l.proc);
   return 0;
}
