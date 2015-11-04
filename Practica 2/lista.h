#ifndef _LISTA_
#define _LISTA_
   //Declaración de tipos
   struct dato {
      int pid;
      int prio;
      char * status;
      int retorno;
      time_t hora_ini;
      char * comando;
   };

   typedef struct dato dato;

   struct nodo {
      dato *dato;
      struct nodo *sig;
      struct nodo *ant;
   };

   typedef struct nodo nodo;
   typedef nodo *posicion;
   typedef nodo *lista;

   //Cabeceras de funciones
   lista crearlista();

   int esListaVacia(lista l);
   int esfindelista(posicion p, lista l);
   
   posicion primera(lista l);
   posicion ultima(lista l);
   posicion anterior(posicion p, lista l);
   posicion siguiente(posicion p, lista l);
   posicion buscarDato(int pid, lista l);
   
   int insertar(dato *d, lista l);
   void eliminar(posicion p, lista l);
   void actualizarDato(dato *d, posicion p,lista l);
   
   void eliminarLista(lista *l);
<<<<<<< HEAD

   dato* nuevodato(int pid, int prio, char * status, time_t hora_ini, char * comando,int retorno);
   dato* getDato(posicion p, lista l);
=======
   dato* nuevodato(int pid, int prio, char * status, int retorno, time_t hora_ini, char * comando);
>>>>>>> f0a33c5cc4774c1aee73b1b7976eb3362700214a
   void eliminardato(dato *d);
#endif
