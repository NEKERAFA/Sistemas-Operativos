#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

	
	void listaVacia(lista *l){
		*l = malloc(sizeof(lista));
		if (l==NULL){
			printf("Error: no queda memoria");
		}else{
			(*l)->prim = NULL;
			(*l)->ultim = NULL;
		}
	}

	int esListaVacia(lista l){
		return (l->prim == NULL);
	}

	posicion Primera (lista l){
		printf("Primera: Función no implementada todavía, por favor, sea paciente\n");
		//return l->prim;
	}

	posicion Ultima (lista l){
		/*
		return l->ultim;
	*/printf("Ultima: Función no implementada todavía, por favor, sea paciente\n");
	}

	posicion Anterior (posicion p){
		/*
		return p->ant;
	*/printf("Anterior: Función no implementada todavía, por favor, sea paciente\n");
	}

	posicion Siguiente (posicion p){
		/*
		return p->sig;
	*/printf("Siguiente: Función no implementada todavía, por favor, sea paciente\n");
	}

	dato* getDato (posicion p){
		/*
		return p->dato;
	*/printf("GetDatos: Función no implementada todavía, por favor, sea paciente\n");
	}

	int insertar (dato *d, lista l){
/*		posicion p,aux;

		p = malloc(sizeof(nodo));
		if (p==NULL){
			printf("No se puede insertar, no queda memoria");
		} else {
			if(l->prim ==NULL){
				p->dato = d;
				p->sig = NULL;
				p->ant = NULL;
				l->prim = p;
				l->ultim = p;	
			} else{
				aux = Ultima(l);
				p->dato = d;
				p->sig = NULL;
				p->ant = aux;

				aux->sig = p;
				l->ultim = p;
			}
		}
	*/printf("Insertar: Función no implementada todavía, por favor, sea paciente\n");
	}

	int eliminar (posicion p){
		printf("Eliminar: Función no implementada todavía, por favor, sea paciente\n");
	}
	
	int actualizarDato (dato d,posicion p){
		printf("Actualizar: Función no implementada todavía, por favor, sea paciente\n");
	}

	void eliminarLista(lista l){
		printf("EliminarLista: Función no implementada todavía, por favor, sea paciente\n");	
	}