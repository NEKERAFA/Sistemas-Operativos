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

// Inserta un proceso en la lista de procesos
void insertarproceso(int pid, char * argv[], lista l) {
   int estado;
   int prioridad;
   int waitpidresult;
   time_t tiempoactual = time(NULL);
   dato * proc;
   int tamcom = tamannotrozos(argv);
   char * comando = (char *) malloc(tamcom*sizeof(char));

   juntarvector(comando, argv);
   waitpidresult = waitpid(pid, &estado, WNOHANG | WUNTRACED | WCONTINUED);
   if(pid != waitpidresult)
      printf("No se puede obtener el estado del proceso %i %i", pid, waitpidresult);
   else if ((prioridad = getpriority(PRIO_PROCESS, pid)) == -1)
         perror("No se puede obtener la prioridad del proceso");
      else {
         proc = nuevodato(pid, prioridad, estado, tiempoactual, comando);
         insertar(proc, l);
      }
}

// Actualiza un proceso de la lista de procesos
void actualizaproceso(posicion p, lista l) {
   int estado;
   int waitpidresult;
   dato * proc = getDato(p, l);

   waitpidresult = waitpid(proc->pid, &estado, WNOHANG | WUNTRACED | WCONTINUED);
   if(proc->pid != waitpidresult)
      printf("No se puede obtener el estado del proceso");
   else if ((proc->prio = getpriority(PRIO_PROCESS, proc->pid)) == -1)
      perror("No se puede obtener la prioridad del proceso");
   else {
      proc->status = estado;
      actualizarDato(proc, p, l);
   }
}

// Muestra el estado de un proceso
void mostarestado(int estado) {
   if (WIFEXITED(estado))
      printf("%8s %6i ", "EXITED", WEXITSTATUS(estado));
   else if (WIFSIGNALED(estado))
      printf("%8s %6i ", "KILLSIG", WTERMSIG(estado));
   else if (WIFSTOPPED(estado))
      printf("%8s %6i ", "STOPPED", WSTOPSIG(estado));
   else
      printf("%8s %6s ", "RUNNING", "");
}

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

// Mostrar proceso
void mostrarproceso(posicion p, lista l) {
   dato * d;
   d = getDato(p, l);

   printf("%4i %4i ", d->pid, d->prio);
   tiempoinicio(d->hora_ini);
   mostarestado(d->status);
   printf("%s\n", d->comando);
}
