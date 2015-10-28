#include <stdio.h>
#include "funciones.h"

int main (int argc, char * argv[]){
	if(argc == 1){
		printf("Error: hay que pasarle un path a la funcion \n");
		return 1;
	}else if(argc >2){
		printf("Error: la funcion sólo recibe un argumento");
		return 1;
	}else{
		deltree(argv[1]);
		return 0;
	}
}