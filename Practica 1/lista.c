#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funciones.h"

// Bucle principal
int main(int argc, char * argv[]) {
    listdir( argc-1, argv+1 );
    return 0;
}
