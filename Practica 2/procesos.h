#ifndef _PROCESOS_H_
#define _PROCESOS_H_
#include "lista.h"

// Inserta un proceso en la lista de procesos
void insertarproceso(int pid, char * argv[], lista l);

// Actualiza un proceso de la lista de procesos
void actualizaproceso( posicion p, lista l );

// Mostrar proceso
void mostrarproceso( posicion p, lista l );

#endif // _PROCESOS_H_
