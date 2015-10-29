#ifndef _LISTA_
#define _LISTA_
	//Declaración de tipos
	struct dato {
		int pid;
		int prio;
		int status;
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
	posicion primera (lista l);
	posicion ultima (lista l);
	posicion anterior (posicion p, lista l);
	posicion siguiente (posicion p,lista l);
	int esfindelista(posicion p, lista l);
	dato* getDato (posicion p,lista l);
	int insertar (dato *d, lista l);
	int eliminar (posicion p, lista l);
	int actualizarDato (dato *d,posicion p,lista l);
	void eliminarLista(lista *l);
	dato* creardato(int pid, int prio, int status, time_t hora_ini, char * comando);
	int eliminardato(dato *d);
#endif