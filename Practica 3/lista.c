#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

   static nodo *crearnodo(){

      nodo *tmp = malloc (sizeof(nodo));
      return tmp;
   }

   lista crearlista(){
      nodo *l = crearnodo();
      
      if (l != NULL){
         l->sig = NULL;
         l->ant = l;
      }
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
      if (p == NULL) return -1;
      return (p->sig == NULL);
   }

   void * getDato (posicion p,lista l){
      return p->dato;
   }

   int insertar (void *d, lista l){
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

   void eliminar (void (*eliminardato)(void * dato),posicion p, lista l){
      posicion tmp = p;
      tmp->ant->sig =tmp->sig;
      if(p != ultima(l)) tmp->sig->ant =tmp->ant;
      else l->ant = tmp->ant;
      eliminardato(tmp->dato);
      free(tmp);
   }

   void actualizarDato (void *d, posicion p, lista l){
      p->dato = d;
   }

   void eliminarLista(void (*eliminardato)(void * dato),lista *l){
      while(!esListaVacia(*l)){
         eliminar(eliminardato,primera(*l),*l);
      }
      free(*l);
      *l=NULL;
   }