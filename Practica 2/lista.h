#ifndef _LISTA_
#define _LISTA_
	//Declaración de tipos
	typedef int dato;
	
	struct nodo {
		dato *dato;
		struct nodo *sig;
		struct nodo *ant;
	};

	typedef struct nodo nodo;
	
	struct list{
		nodo *prim;
		nodo *ultim;
	};

	typedef nodo *posicion;
	typedef struct list *lista;

	//Cabeceras de funciones
	void listaVacia(lista *l);
	int esListaVacia(lista l);
	posicion Primera (lista l);
	posicion Ultima (lista l);
	posicion Anterior (posicion p);
	posicion Siguiente (posicion p);
	dato* getDato (posicion p);
	int insertar (dato *d, lista l);
	int eliminar (posicion p);
	int actualizarDato (dato d,posicion p);
	void eliminarLista(lista l);
#endif