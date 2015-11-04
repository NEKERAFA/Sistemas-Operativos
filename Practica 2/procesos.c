#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>
#include "lista.h"
#include "utilidades.h"

// Inserta un proceso en la lista de procesos
insertarproceso(int pid, char * argv[], lista l) {
   int * estado = (int *) malloc(sizeof(int));
   int prioridad;
   time_t tiempoactual = time(NULL);
   dato * proc;
   char * comando;
   int rwait = waitpid(pid, &estado, WNOHANG | WUNTRACED | WCONTINUED);

   juntarvector(comando, argv);
   if((pid != rwait) && (rwait != 0))
      perror("No se puede obtener el estado del proceso");
   else if ((prioridad = getpriority(PRIO_PROCESS, pid)) == -1)
         perror("No se puede obtener la prioridad del proceso");
      else {
         proc = nuevodato(pid, prioridad, *estado, tiempoactual, comando);
         insertar(proc, l);
      }

   free(estado);
}

// Actualiza un proceso de la lista de procesos
actualizaproceso(posicion p, lista l) {
   int * estado = (int *) malloc(sizeof(int));
   int waitpidresult;
   dato * proc = getDato(p, l);

   waitpidresult = waitpid(proc->pid, &estado, WNOHANG | WUNTRACED | WCONTINUED);
   if((waitpidresult != 0) && (proc->pid != waitpidresult))
      perror("No se puede obtener el estado del proceso");
   else if (proc->pid != waitpidresult)
      if ((proc->prio = getpriority(PRIO_PROCESS, proc->pid)) == -1)
         perror("No se puede obtener la prioridad del proceso");
      else {
         proc->status = *estado;
         actualizarDato(proc, p, l);
      }
}
