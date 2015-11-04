#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

   static nodo *crearnodo(){

      nodo *tmp = malloc (sizeof(nodo));
      if (tmp == NULL){
         printf("Memoria agotada\n");
         exit(EXIT_FAILURE);
      }

      return tmp;
   }

   static dato *creardato(){
      dato *tmp = malloc (sizeof(dato));

      if (tmp == NULL){
         printf("Memoria agotada \n");
         exit(EXIT_FAILURE);
      }

      return tmp;
   }

   lista crearlista(){

      nodo *l = crearnodo();
      l->sig = NULL;
      l->ant = l;

      return l;
   }

   int esListaVacia(lista l){

      return (l->sig == NULL);
   }

   posicion primera (lista l){
      return (l->sig);
   }

   posicion ultima (lista l){
      return (l->ant);
   }

   posicion anterior (posicion p, lista l){

      if((p == l)||(p->ant == l)){
         return NULL;
      } else {
         return p->ant;
      }
   }

   posicion siguiente (posicion p,lista l){
     return p->sig;
   }

   int esfindelista(posicion p, lista l){
      return (p->sig == NULL);
   }

   dato* getDato (posicion p,lista l){
      return p->dato;
   }

   posicion buscarDato(int pid, lista l) {
      if (esListaVacia(l)) return NULL;
      posicion p = primera(l);

      while (!esfindelista(p, l) && p->dato->pid != pid) siguiente(p, l);
      if (p->dato->pid == pid) return p;
      return NULL;
   }

   int insertar (dato *d, lista l){
      nodo *tmp = crearnodo();
      if (tmp != NULL){
         posicion p = ultima(l);

         tmp->dato = d;
         tmp->ant= p;
         tmp->sig=NULL;

         l->ant = tmp;
         p->sig = tmp;
         return 0;
      } else {
         return -1;
      }
   }

   void eliminar (posicion p, lista l){
      posicion tmp = p;
      tmp->ant->sig =tmp->sig;
      if(p != ultima(l)) tmp->sig->ant =tmp->ant;
      else l->ant = tmp->ant;
      eliminardato(tmp->dato);
      free(tmp);
   }

   void actualizarDato (dato *d, posicion p, lista l){
      p->dato = d;
   }

   void eliminarLista(lista *l){
      while(!esListaVacia(*l)){
         eliminar(primera(*l),*l);
      }
      free(*l);
      *l=NULL;
   }

   dato* nuevodato(int pid, int prio, char * status, int retorno, time_t hora_ini, char * comando){
      dato * d = creardato();

      d->pid = pid;
      d->prio = prio;
      d->status = status;
      d->retorno = retorno;
      d->hora_ini = hora_ini;
      d->comando = comando;
      d->retorno = retorno;

      return d;
   }

   void eliminardato(dato *d){
      free (d->comando);
      free (d->status);
      free (d);
   }
