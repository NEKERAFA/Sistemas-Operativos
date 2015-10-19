#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void testListaVacia(){
	lista l;
	printf("Test listaVacia\n");
	listaVacia(&l);

	if((l->prim ==NULL)&&(l->ultim ==NULL)){
		printf("Test Superado\n\n");
	}else{
		printf("***********************FAIL***********************\n\n");
	}

}

//Debe dar true si la lista está vacía y false si no lo está	
void testEsListaVacia(){
	lista l;
	posicion p;

	printf("Test esListaVacia \n");
	
	listaVacia(&l);
	
	if(esListaVacia(l)){
		p = malloc(sizeof(nodo));
		p->dato = malloc(sizeof(int));
		*(p->dato) = 1;
		p->sig = NULL;
		p->ant = NULL;

		l->prim = p;	
		if(esListaVacia(l)){
			printf("***********************FAIL***********************\n\n");
		}else{
			printf("Test Superado\n\n");
		}
		
		free(p->dato);
		free(p);
		l->prim = NULL;
	}else{
		printf("***********************FAIL***********************\n\n");	
	}
}

void testPrimera(){
	printf("Test Primera \n");
	printf("Test no implementado \n");
}

void testUltima(){
	printf("Test Ultima \n");
	printf("Test no implementado \n");
}

void testAnterior(){
	printf("Test Anterior \n");
	printf("Test no implementado \n");
}

void testSiguiente(){
	printf("Test Siguiente \n");
	printf("Test no implementado \n");
}

void testGetDato(){
	printf("Test getDato \n");
	printf("Test no implementado \n");
}

void testInsertar(){
	printf("Test insertar \n");
	printf("Test no implementado \n");
}

void testEliminar(){
	printf("Test eliminar \n");
	printf("Test no implementado \n");
}

void testActualizarDato(){
	printf("Test actualizarDato \n");
	printf("Test no implementado \n");
}

void testEliminarLista(){
	printf("Test eliminarLista \n");
	printf("Test no implementado \n");
}

int main (){
	printf("Iniciando la validación del módulo lista \n\n\n");

	testListaVacia();;
	testEsListaVacia();
	testInsertar();
	testGetDato();
	testPrimera();
	testUltima();
	testAnterior();
	testSiguiente();
	testEliminar();
	testActualizarDato();
	testEliminarLista();
}
