#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funciones.h"

int const TAM_ENTRADA = 1024;

// Prompt del shell
void prompt(char * actual_dir) {
    printf("%s$ ", actual_dir);
}

void leerentrada(char * entrada, int tamano_entrada) {
    char * retorno_entrada;
    retorno_entrada = fgets(entrada, tamano_entrada, stdin);
    if (retorno_entrada == NULL) {
        perror("Error en la entrada");
    }
}

// Divide la cadena en trozos
int dividircadena(char * cadena, char * trozos[]) {
    int i = 1;
    if((trozos[0] = strtok(cadena, " \n\t")) == NULL) { return 0; }
    while((trozos[i] = strtok(NULL, " \n\t")) != NULL) { i++; }
    return i;
}

// Procesa la entrada para ejecutar los comandos
void procesarentrada(char * entrada, char * dir_act, int * salir) {
    char * c_parametros[TAM_ENTRADA/4];
    int n_parametros;
    n_parametros = dividircadena(entrada, c_parametros);

    if (n_parametros > 0) {
        if((!strcmp(c_parametros[0], "exit")) || (!strcmp(c_parametros[0], "quit")) || (!strcmp(c_parametros[0], "fin"))) {
            *salir = 1;
        } else if (!strcmp(c_parametros[0], "pid")) {
            pid(c_parametros[1]);
        } else if (!strcmp(c_parametros[0], "autores")) {
            author();
        } else if (!strcmp(c_parametros[0], "cd")) {
            changedir(c_parametros[1], dir_act);
        } else if (!strcmp(c_parametros[0], "list")) {
            listdir(n_parametros-1, c_parametros+1);
        } else if (!strcmp(c_parametros[0], "delete")) {
            removefile(c_parametros[1]);
        } else {
            printf("%s: Orden no encontrada\n", c_parametros[0]);
        }
    }
}

// Bucle principal
<<<<<<< HEAD
int main(int argc, char * argv[]) {
=======
int main(int argc, char const *argv[]) {
>>>>>>> b3b30fe092815a3c18e4bd248bebcebbf0c7d5df
    int fin = 0;
    char entrada[TAM_ENTRADA];
    char dir_act[2048];
    if (getcwd(dir_act, 2048) == NULL) {
        perror("Imposible obtener el directorio actual");
    }

    printf("Interprete de comando en UNIX\n");
    while(!fin) {
        prompt(dir_act);
        leerentrada(entrada, TAM_ENTRADA);
        procesarentrada(entrada, dir_act, &fin);
    }

    return 0;
}
