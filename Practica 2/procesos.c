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
#include "procesos.h"
#include "utilidades.h"

#define ACT  "ACT"
#define CONT "CONT"
#define EXIT "EXIT"
#define SIGN "SIGN"
#define STOP "STOP"
#define UNK  "UNK"

// Muestra el tiempo inicial
void tiempoinicio(time_t tiempo) {
   struct tm * stiempo = (struct tm *) malloc(sizeof(struct tm));
   gmtime_r(&tiempo, stiempo);
   char * ctiempo = (char *) malloc(32*sizeof(char));
   strftime(ctiempo, 32*sizeof(char), "%H:%M:%S", stiempo);
   printf("%10s ", ctiempo);
   free(ctiempo);
   free(stiempo);
}

// Devuelve el estado del proceso
char * estadoproceso(int estado) {
   if (WIFEXITED(estado))
      return EXIT;
   else if (WIFSIGNALED(estado))
      return SIGN;
   else if (WIFSTOPPED(estado))
      return STOP;
   else if (WIFCONTINUED(estado))
      return CONT;
   return ACT;
}

// Devuelve el retorno del proceso
int retornoproceso(int estado) {
   if (WIFEXITED(estado))
      return WEXITSTATUS(estado);
   else if (WIFSIGNALED(estado))
      return WTERMSIG(estado);
   else if (WIFSTOPPED(estado))
      return WSTOPSIG(estado);
   else
      return 0;
}

// Inserta un proceso en la lista de procesos
void insertarproceso(int pid, char * argv[], lista l) {
   int prioridad;
   time_t tiempoactual = time(NULL);
   dato * proc;
   int tamcom = tamannotrozos(argv);
   char * comando = (char *) malloc(tamcom*sizeof(char));

   juntarvector(comando, argv);
   if ((prioridad = getpriority(PRIO_PROCESS, pid)) == -1)
      perror("No se puede obtener la prioridad del proceso");
   else {
      proc = nuevodato(pid, prioridad, ACT, 0, tiempoactual, comando);
      insertar(proc, l);
   }
}

// Actualiza un proceso de la lista de procesos
void actualizaproceso(posicion p, lista l) {
   int estado;
   int prior;
   int waitpidresult;
   dato * proc = getDato(p, l);

   waitpidresult = waitpid(proc->pid, &estado, WNOHANG | WUNTRACED | WCONTINUED);
   if(proc->pid == waitpidresult) {
      prior = getpriority(PRIO_PROCESS, proc->pid);
      if (prior != -1) proc->prio = prior;
      proc->status = estadoproceso(estado);
      proc->retorno = retornoproceso(estado);
      actualizarDato(proc, p, l);
   }
}

// Mostrar proceso
void mostrarproceso(dato * d, lista l) {
   printf("%4i %4i ", d->pid, d->prio);
   tiempoinicio(d->hora_ini);
   printf("%6s %6i ", d->status, d->retorno);
   printf("%s\n", d->comando);
}
