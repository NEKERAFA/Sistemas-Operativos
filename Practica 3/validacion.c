
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void testListaVacia(){
	lista l;
	printf("Test crearlista\n");
	l = crearlista();

	if((l!=NULL)&&(l->sig = l)&&(l->ant = l)){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}

	free (l);
}

//Debe dar true si la lista está vacía y false si no lo está	
void testEsListaVacia(){
	lista l = crearlista();
	int ok = esListaVacia(l);
	printf("Test eslistavacia \n");
	dato *d = malloc (sizeof(dato)); 
	nodo *tmp = malloc (sizeof(nodo));
	*d =1;
	tmp->dato = d;
	tmp->ant= l;
	tmp->sig=l;
	
	l->ant = tmp;
	l->sig = tmp;

	if (ok && (!esListaVacia(l))){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}
	free (d);
	free (tmp);
	free (l->ant);
	free (l);
}

void testPrimera(){
	printf("Test Primera \n");
	lista l = crearlista();

	dato *d1,*d2;
	*d1 = 1;
	*d2 = 2;
	insertar(d1,l);
	insertar(d2,l);

	posicion p;
	p = primera(l);

	if (*(getDato(p,l)) == 1){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}
}

void testUltima(){
	printf("Test Ultima \n");
	lista l = crearlista();

	dato *d1,*d2;
	*d1 = 1;
	*d2 = 2;
	insertar(d1,l);
	insertar(d2,l);

	posicion p;
	p = ultima(l);

	if (*(getDato(p,l)) == 2){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}
}

void testAnterior(){
	printf("Test Anterior \n");
	lista l = crearlista();

	dato *d1,*d2;
	*d1 = 1;
	*d2 = 2;
	insertar(d1,l);
	insertar(d2,l);

	posicion p1,p2;
	p1 = ultima(l);
	p2 = primera(l);


	if ((anterior(p1,l)==p2)&&(anterior(p2,l)==NULL)){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}
}

void testSiguiente(){
	printf("Test Siguiente \n");
	lista l = crearlista();

	dato *d1,*d2;
	*d1 = 1;
	*d2 = 2;
	insertar(d1,l);
	insertar(d2,l);

	posicion p1,p2;
	p1 = ultima(l);
	p2 = primera(l);


	if ((siguiente(p2,l)==p1)&&(siguiente(p1,l)==NULL)){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}
}

void testGetDato(){
	printf("Test getDato \n");
	lista l = crearlista();

	dato *d1;
	*d1 = 1;
	posicion p;
	insertar(d1,l);

	p= l->sig;

	dato *d = getDato(p,l);

	if (*d == 1){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}
}

void testInsertar(){
	printf("Test insertar \n");
	lista l = crearlista();

	dato *d1,*d2,*d3;
	*d1 = 1;
	insertar(d1,l);
	*d2 = 2;
	insertar(d2,l);
	*d3 = 3;
	insertar(d3,l);

	if ((*(l->sig->dato)==1)&&(*(l->sig->sig->dato)==2)&&(*(l->sig->sig->sig->dato)==3)){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}

}

void testEliminar(){
	printf("Test eliminar \n");
	lista l = crearlista();

	dato *d1,*d2,*d3;
	*d1 = 1;
	insertar(d1,l);
	*d2 = 2;
	insertar(d2,l);
	*d3 = 3;
	insertar(d3,l);

	eliminar(l->sig->sig,l);

	if ((*(l->sig->dato)==1)&&(*(l->sig->sig->dato)==3)){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}
}

void testActualizarDato(){
	printf("Test actualizarDato \n");
	lista l = crearlista();

	dato *d1,*d2;
	*d1 = 1;
	*d2 = 2;
	insertar(d1,l);

	posicion p1 = primera(l);

	actualizarDato(d2,p1,l);

	if (*(p1->dato)==2){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}	
}

void testEliminarLista(){
	printf("Test eliminarLista \n");
	lista l = crearlista();

	dato *d1,*d2,*d3;
	*d1 = 1;
	insertar(d1,l);
	*d2 = 2;
	insertar(d2,l);
	*d3 = 3;
	insertar(d3,l);

	eliminarLista(&l);

	if (l == NULL){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}
}

void testesfindelista(){
	printf("Test esfindelista \n");
	lista l = crearlista();

	dato *d1,*d2;
	*d1 = 1;
	*d2 = 2;
	insertar(d1,l);
	insertar(d2,l);

	posicion p1,p2;
	p1 = ultima(l);
	p2 = primera(l);


	if (!(esfindelista(p2,l))&&(esfindelista(p1,l))){
		printf("++++ TEST SUPERADO\n\n");
	} else {
		printf("***********************FAIL***********************\n\n");
	}	
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
	testesfindelista();
	testActualizarDato();
	testEliminarLista();
}
