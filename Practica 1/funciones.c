#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <limits.h>
#include "funciones.h"

// Obtiene el tipo de fichero
char filetype(mode_t f_mode) {
   switch (f_mode & S_IFMT) {
      case S_IFSOCK:  return 's';
      case S_IFLNK:   return 'l';
      case S_IFREG:   return '-';
      case S_IFBLK:   return 'b';
      case S_IFDIR:   return 'd';
      case S_IFCHR:   return 'c';
      case S_IFIFO:   return 'p';
      default:		return '?';
   }
}

char * modoarchivo(mode_t f_mode) {
   static char permisos[12];
   strcpy(permisos, "---------- ");

   permisos[0] = filetype(f_mode);
   if (f_mode & S_IRUSR) permisos[1]='r';
   if (f_mode & S_IWUSR) permisos[2]='w';
   if (f_mode & S_IXUSR) permisos[3]='x';
   if (f_mode & S_IRGRP) permisos[4]='r';
   if (f_mode & S_IWGRP) permisos[5]='w';
   if (f_mode & S_IXGRP) permisos[6]='x';
   if (f_mode & S_IROTH) permisos[7]='r';
   if (f_mode & S_IWOTH) permisos[8]='w';
   if (f_mode & S_IXOTH) permisos[9]='x';
   if (f_mode & S_ISUID) permisos[3]='s';
   if (f_mode & S_ISGID) permisos[6]='s';
   if (f_mode & S_ISVTX) permisos[9]='t';
   return permisos;
}

// Muestra en pantalla el pid actual o el pid padre
void pid(char * parametro) {
   if (parametro == NULL) { printf("Pid actual: %d\n", getpid()); }
   else if (!strcmp(parametro, "-p")) { printf("Pid padre: %d\n", getppid()); }
   else { printf("Uso: pid [opciones]: Muestra el pid del proceso que ejecuta el shell.\n\nOpciones:\n  -p Muestra el pid del proceso padre del shell\n  -h Ayuda\n"); }
}

// Muestra los autores
void author() {
   printf("Este shell ha sido realizado por: \n");
   printf("Rafael Alcalde Azpiazu (rafael.alcalde.azpizu@udc.es) \n");
   printf("Ivan Anta Porto  (i.anta@udc.es)\n");

}

// Muestra el directorio actual
void getdir( char * cur_dir ) {
   if (getcwd(cur_dir, 2048) == NULL) {
      perror("Imposible obtener el directorio actual");
   } else {
      printf("Actualmente en: %s\n", cur_dir);
   }
}

// Cambia de directorio de trabajo
void changedir( char * dir, char * cur_dir ) {
   int change;

   if (dir == NULL) { getdir(cur_dir);
   } else {
      change = chdir(dir);
      if (change == -1) { perror("Imposible cambiar el directorio");
      } else { getdir(cur_dir); }
   }
}

// Elimina un archivo
void removefile( char * file ) {
   struct stat file_info;
   if (file != NULL) {
      if (stat(file, &file_info) == -1) { perror("Imposible eliminar el fichero");
      } else {
         // Comprueba que sea un directorio y lo elimina
         if(filetype(file_info.st_mode) == 'd') {
            if(rmdir(file) == -1) { perror("Imposible eliminar el directorio");
            } else { printf("Directorio %s eliminado\n", file); }
         // Si no elimina el archivo
         } else {
            if(unlink(file) == -1) { perror("Imposible eliminar el archivo");
            } else { printf("Archivo %s eliminado\n", file); }
         }
      }
   } else { printf("Uso: delete [archivo]: Elimina archivo. archivo es un fichero o un directorio vacio.\n"); }
}

// Obtiene los argumentos para listar
int getarg(int argc, char * argv[], char * *path) {
   int flags = 0;
   int i;

   if (argc > 3) { printf("Uso: lista [opciones] [ruta]: Lista el directorio actual.\n\nOpciones:\n  -a Muestra los achivos ocultos\n  -s Muestra el nombre completo\n");
   } else {
      // Bucle for que recorre los argumentos
      for (i = 0; i < argc ; ++i) {
         if(argv[i][0] == '-') {
            // Si el string es una a, entonces guarda en la flag que se vean los archivos ocultos
            if(!strcmp(argv[i]+1, "a")) { flags |= HIDDEN_FILES; }
            // Si el string es una a, entonces guarda en la flag que se vean los archivos con nombre corto
            else if(!strcmp(argv[i]+1, "s")) { flags |= SHORT_NAME; }
            // Si no deja de seguir buscando
            else {
               printf("Uso: lista [opciones] [ruta]: Lista el directorio actual.\n\nOpciones:\n  -a Muestra los achivos ocultos\n  -s Muestra el nombre completo\n");
               flags = -1;
               break;
            }
         // Guarda el directorio
         } else { *path = argv[i]; }
      }

      return flags;
   }
}

// Imprime información sobre el fichero
void print_fileinfo(struct stat file_info) {
   struct passwd * user_info = getpwuid(file_info.st_uid);;
   struct group * group_info = getgrgid(file_info.st_gid);
   struct tm * shora_fichero = (struct tm *) malloc(sizeof(struct tm));
   struct tm * shora_actual = (struct tm *) malloc(sizeof(struct tm));
   time_t thora_actual;
   char * hora_fichero = (char *) malloc(sizeof(char)*32);


   // Inodo del fichero, Modo de archivo y hard links del fichero
   printf("%10li %s %4li", file_info.st_ino, modoarchivo(file_info.st_mode), file_info.st_nlink);
   // Nombre del usuario
   if (user_info == NULL) { printf("%5i ", file_info.st_uid); }
   else { printf("%10s ", user_info->pw_name); }
   // Nombre del grupo
   if (group_info == NULL) { printf("%5i ", file_info.st_gid); }
   else { printf("%10s ", group_info->gr_name); }
   // Obtenemos la hora del sistema y del archivo
   time(&thora_actual);
   gmtime_r(&thora_actual, shora_actual);
   gmtime_r(&file_info.st_mtime, shora_fichero);
   if ((shora_actual->tm_year) == (shora_fichero->tm_year)) {
      strftime(hora_fichero, sizeof(hora_fichero), "%b %d %H:%M", shora_fichero);
   } else {
      strftime(hora_fichero, sizeof(hora_fichero), "%b %d %Y ", shora_fichero);
   }
   printf("%s ", hora_fichero);

   // Eliminamos los punteros reservados
   free(shora_fichero);
   free(shora_actual);
   free(hora_fichero);
}

// Imprime la dirección real del link
void printslnk(char * path) {
   char * path_link = (char *) malloc(1024*sizeof(char));

   // Obtiene la ruta real del archivo
   if(realpath(path, path_link) == NULL) {
      printf("\n");
      perror("Fallo al seguir link simbólico");
   } else { printf(" -> %s\n", path_link); }

   free(path_link);
}

// Lista un directorio
void listdir( int argc, char * argv[] ) {
   int flags;
   int df;
   char * dir_path = ".";
   struct dirent * sdir;
   DIR * pdir;
   int i;

   // Obtiene los argumentos
   if ((flags = getarg(argc, argv, &dir_path)) != -1) {
      // Abre el directorio
      if ((pdir = opendir(dir_path)) == NULL) {
         perror("Imposible listar el directorio");
      } else {
         char file_path[2048];
         struct stat file_info;

         // Recorre el directorio
         while((sdir = readdir(pdir)) != NULL) {
            sprintf(file_path, "%s/%s", dir_path, sdir->d_name);
            if (lstat(file_path, &file_info) == -1) {
               perror("STAT: No se puede mostrar el archivo");
            } else {
               // Compruebo si la flag está desactivada para archivos ocultos
               if (((sdir->d_name[0] != '.') && !(flags & HIDDEN_FILES)) || (flags & HIDDEN_FILES)) {
                  // Si no está la flag de nombre corto, imprimo información completa de la entrada
                  if (!(flags & SHORT_NAME)) { print_fileinfo(file_info); }
                  // Si es un soft link, muestro a donde apunta
                  if(!(flags & SHORT_NAME) && (filetype(file_info.st_mode) == 'l')) {
                     printf("%s", sdir->d_name);
                     printslnk(file_path);
                  } else { printf("%s\n", sdir->d_name); }
               }
            }
          } // endwhile

          closedir(pdir);
      }
   }
}
//elimina recursivamente directorios
void deltree(char * parametro){
   char path[1000];
   DIR * directorio;
   struct dirent * archivo;
   struct stat archivo_info;
   path[0]='\0';

   if(parametro == NULL){//Si no se le pasa ninguna ruta a la funcion
      printf("Error: hay que pasar un parametro");
   }else{
      if((directorio=opendir(parametro))==NULL){//Si no se puede abrir el directorio
         perror("Error: no se ha podido abrir el directorio: ");
      }else{
         while((archivo = readdir(directorio))!=NULL){//Se leen todas las entradas de directorio
            if(!strcmp(archivo->d_name ,".")||!strcmp(archivo->d_name ,"..")){//Se excluyen del procesado los directorios . y ..
               continue;
            } else{
               sprintf(path,"%s%s%s",parametro,path[strlen(path)-1] == '/' ? "" : "/",archivo->d_name);
               if(stat(path,&archivo_info)== -1){//se comprueba si hay acceso a la entrada de directorio
                  printf("Imposible eliminar el directorio\n");
               }else{
                  if(archivo_info.st_mode & S_IFDIR){//Si la entrada es un directorio se llama de nuevo a esta función
                     deltree(path);
                  }else{//Si no es un directorio se elimina el archivo
                     removefile(path);
                  }
               }
            }
         }
         removefile(parametro);//Finalmente borramos el directorio actual
         closedir(directorio);//Y cerramos el directorio
      }
   }
}
