#ifndef _PROCESOS_H_
#define _PROCESOS_H_
#include "lista.h"

#define ACT  "ACT"
#define CONT "CONT"
#define EXIT "EXIT"
#define SIGN "SIGN"
#define STOP "STOP"

typedef struct dato {
      int pid;
      int prio;
      char * status;
      int retorno;
      time_t hora_ini;
      char * comando;
   } datoproc;

// Esta función devuelve un nuevo dato con todos los parámetros inicializados
datoproc* nuevodatoproc(int pid, int prio, char * status, int retorno, time_t hora_ini, char * comando);

// Esta función elimina un dato.
void eliminardatoproc(datoproc *d);

// Esta función devuelve la posición en la que está un dato cuyo campo pid sea el pasado por parámetro
// Devuelve NULL si no encuentra el dato
posicion buscarDato(int pid, lista l);
   

// Inserta un proceso en la lista de procesos
void insertarproceso(int pid, char * argv[], lista l);

// Actualiza un proceso de la lista de procesos
void actualizaproceso( posicion p, lista l );

// Mostrar proceso
void mostrarproceso( datoproc * d, lista l );

#endif // _PROCESOS_H_
