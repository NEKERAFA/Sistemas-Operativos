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

	lista crearlista(){

		nodo *l = crearnodo();
		l->sig = l;
		l->ant = l;

		return l;
	}

	int esListaVacia(lista l){

		return ((l->sig ==l)&&(l->ant = l));
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

		if (p->sig == l){
			return NULL;
		} else {
			return p->sig;
		}
	}

	int esfindelista(posicion p, lista l){
		return (p->sig == l);
	}

	dato* getDato (posicion p,lista l){
		return p->dato;
	}

	int insertar (dato *d, lista l){
		nodo *tmp = crearnodo();
		posicion p = ultima(l);
		
		tmp->dato = d;
		tmp->ant= p;
		tmp->sig=l;
		
		l->ant = tmp;
		p->sig = tmp;

	}

	int eliminar (posicion p, lista l){
		posicion tmp = p;
		tmp->ant->sig =tmp->sig;
		tmp->sig->ant =tmp->ant;
		free(tmp);
	}

	int actualizarDato (dato *d,posicion p,lista l){
		dato *tmp = p->dato;
		p->dato = d;
		free(tmp);
	}

	void eliminarLista(lista *l){
		while(!esListaVacia(*l)){
			eliminar(primera(*l),*l);
		}
		free(*l);
		*l=NULL;
	}