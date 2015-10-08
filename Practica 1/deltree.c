#include <stdio.h>
#include "funciones.h"

int main (int argc, char * argv[]){
	if(argc == 1){ //Si sólo se le realiza la llamada con el nombre de la función
		printf("Error: hay que pasarle un path a la funcion \n");
		return 1;
	}else if(argc >2){//Si se pasan más parámetros de los necesarios
		printf("Error: la funcion sólo recibe un argumento");
		return 1;
	}else{//Si se realiza correctamente la llamada
		deltree(argv[1]);
		return 0;
	}
}