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
#include "funciones.h"

// Muestra en pantalla el pid actual o el pid padre
void pid(char * parametro) {
   if (parametro == NULL) { printf("Pid actual: %d\n", getpid()); }
   else if (!strcmp(parametro, "-p")) { printf("Pid padre: %d\n", getppid()); }
   else { printf("Uso: pid [opciones]: Muestra el pid del proceso que ejecuta el shell.\n\nOpciones:\n  -p Muestra el pid del proceso padre del shell\n  -h Ayuda\n"); }
}

// Muestra los autores
void author() {
   printf("Autores: \n");
}

// Muestra el directorio actual
void getdir( char * cur_dir ) {
   if (getcwd(cur_dir, 2048) == NULL) {
      perror("Imposible obtener el directorio actual");
   } else {
      printf("Actualmente en: %s\n", cur_dir);
   }
}

// Cambia de directorio
void changedir( char * dir, char * cur_dir ) {
   int change;

   if (dir == NULL) {
      getdir(cur_dir);
   } else {
      change = chdir(dir);
      if (change == -1) {
         perror("Imposible cambiar el directorio");
      } else {
         getdir(cur_dir);
      }
   }
}

// Elimina un archivo
void removefile( char * file ) {
   struct stat file_info;
   if (file != NULL) {
      if (stat(file, &file_info) == -1) {
         perror("Imposible eliminar el fichero");
      } else {
         if(file_info.st_mode & S_IFDIR) {
            if(rmdir(file) == -1) {
               perror("Imposible eliminar el directorio");
            } else {
               printf("Directorio %s eliminado\n", file);
            }
         } else {
            if(unlink(file) == -1) {
               perror("Imposible eliminar el archivo");
            } else {
               printf("Archivo %s eliminado\n", file);
            }
         }
      }
   } else {
      printf("Uso: delete [archivo]: Elimina archivo. archivo es un fichero o un directorio vacio.\n");
   }
}

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

// Lista un directorio
void listdir( int argc, char * argv[] ) {
   int hidden_files = 0;
   int short_name = 0;
   char * dir_path = ".";
   DIR * pdir;
   struct dirent * sdir;
   int i;

   for (i = 0; i < argc ; ++i) {
      if(!strcmp(argv[i], "-a")) { hidden_files = 1; }
      else if(!strcmp(argv[i], "-s")) { short_name = 1; }
      else { dir_path = argv[i]; }
   }

   if ((pdir = opendir(dir_path)) == NULL) {
      perror("Imposible listar el directorio");
   } else {
      char file_path[2048];
      struct stat file_info;
      struct passwd * user_info;
      struct group * group_info;
      struct tm * shora_fichero;
      time_t thora_actual;
      struct tm * shora_actual;
      char hora_fichero[32];

      shora_fichero = (struct tm *) malloc(sizeof(struct tm));
      shora_actual  = (struct tm *) malloc(sizeof(struct tm));

      while((sdir = readdir(pdir)) != NULL) {
         sprintf(file_path, "%s/%s", dir_path, sdir->d_name);
         if (stat(file_path, &file_info) == -1) {
            perror("STAT: No se puede mostrar el archivo");
         } else {
            if (((sdir->d_name[0] != '.') && (!hidden_files)) || hidden_files) {
               if (!short_name) {
                  // Inodo del fichero
                  printf("%10li ", file_info.st_ino);
                  // Modo de archivo
                  printf("%s ", modoarchivo(file_info.st_mode));
                  // Hard links al fichero
                  printf("%2li ", file_info.st_nlink);
                  // Obtenemos el nombre de usuario
                  user_info = getpwuid(file_info.st_uid);
                  if (user_info == NULL) { printf("%5i ", file_info.st_uid); }
                  else { printf("%10s ", user_info->pw_name); }
                  // Obtenemos el nombre del grupo
                  group_info = getgrgid(file_info.st_gid);
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
               }
               printf("%s\n", sdir->d_name);
            }
         } // endif
       } // endwhile

       free(shora_fichero);
       free(shora_actual);
       closedir(pdir);
   }
}
//elimina recursivamente directorios
void deltree(char * parametro){
   char path[1000];
   DIR * directorio;
   struct dirent * archivo;
   struct stat archivo_info;

   if(parametro == NULL){
      printf("Error: hay que pasar un parametro");
   }else{
      if((directorio=opendir(parametro))==NULL){
         printf("Error: no se ha podido abrir el directorio");
      }else{
         while((archivo = readdir(directorio))!=NULL){
            
            if(!strcmp(archivo->d_name ,".")||!strcmp(archivo->d_name ,"..")){
               continue;
            } else{
               printf("WOLOLO\n");
               printf("Estoy entrando en el resto de entradas de directorio\n");
               sprintf(path,"%s%s%s",parametro,path[strlen(path)-1] == '/' ? "" : "/",archivo->d_name);
               if(stat(path,&archivo_info)== -1){
                  printf("Imposible eliminar el directorio");
               }else{
                  if(archivo_info.st_mode & S_IFDIR){
                     printf("Debe hacerse un borrado recursivo del directorio\n");
                     deltree(path);
                  }else{
                     printf("Debe borrar un archivo\n");
                     removefile(path);
                  }
               }

            }
         }
         removefile(parametro);
      }
   }
}

