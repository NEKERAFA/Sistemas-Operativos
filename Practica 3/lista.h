#ifndef _LISTA_
#define _LISTA_
   //Declaración de tipos
   struct nodo {
      void * dato;
      struct nodo *sig;
      struct nodo *ant;
   };

   typedef struct nodo nodo;
   typedef nodo *posicion;
   typedef nodo *lista;

   //Cabeceras de funciones

   // Esta función devuelve una nueva lista
   lista crearlista();

   // Esta función comprueba si una lista está vacía
   int esListaVacia(lista l);
   // Esta función comprueba si es la última posición
   // Devuelve -1 si la posición pasada por parámetro no existe
   int esfindelista(posicion p, lista l);
   
   // Esta función devuelve la primera posición de la lista
   // Devuelve NULL si la lista está vacía
   posicion primera(lista l);
   // Esta función devuelve la última posición de la lista
   // Devuelve NULL si la lista está vacía
   posicion ultima(lista l);
   // Esta función devuelve la posición anterior a la posición pasada
   // Devuelve NULL si p es la primera posición o si p = l
   posicion anterior(posicion p, lista l);
   // Esta función devuelve la posición siguiente a la posición pasada
   // Devuelve NULL si p es la última posición
   posicion siguiente(posicion p, lista l);
  
   // Esta función inserta un nuevo dato en la lista
   // Devuelve 0 si se ha insertado el dato y -1 en caso contrario
   int insertar(void * d, lista l);
   // Esta función elimina la posición p de la lista
   void eliminar (void (*eliminardato)(void * dato),posicion p, lista l);
   // Esta función actualiza la posición p con el dato d
   void actualizarDato(void * d, posicion p,lista l);
   
   // Esta función elimina por completo la lista
   void eliminarLista(void (*eliminardato)(void * dato),lista *l);

   // Esta función obtiene el dato guardado en la posición p de la lista
   void * getDato(posicion p, lista l);

   
#endif
