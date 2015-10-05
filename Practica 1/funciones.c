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

// Muestra en pantalla el pid actual o el pid padre
void pid(char * parametro) {
<<<<<<< HEAD
   if (parametro == NULL) { printf("Pid actual: %d\n", getpid()); }
   else if (!strcmp(parametro, "-p")) { printf("Pid padre: %d\n", getppid()); }
   else { printf("Uso: pid [opciones]: Muestra el pid del proceso que ejecuta el shell.\n\nOpciones:\n  -p Muestra el pid del proceso padre del shell\n  -h Ayuda\n"); }
=======
    if (parametro == NULL) { printf("Pid actual: %d\n", getpid()); }
    else if (!strcmp(parametro, "-p")) { printf("Pid padre: %d\n", getppid()); }
    else { printf("Uso: pid [opciones]: Muestra el pid del proceso que ejecuta el shell.\n\nOpciones:\n  -p Muestra el pid del proceso padre del shell\n  -h Ayuda\n"); }
>>>>>>> b3b30fe092815a3c18e4bd248bebcebbf0c7d5df
}

// Muestra los autores
void author() {
<<<<<<< HEAD
   printf("Autores: \n");
=======
    printf("Autores: \n");
>>>>>>> b3b30fe092815a3c18e4bd248bebcebbf0c7d5df
}

// Muestra el directorio actual
void getdir( char * cur_dir ) {
<<<<<<< HEAD
   if (getcwd(cur_dir, 2048) == NULL) {
      perror("Imposible obtener el directorio actual");
   } else {
      printf("Actualmente en: %s\n", cur_dir);
   }
=======
    if (getcwd(cur_dir, 2048) == NULL) {
        perror("Imposible obtener el directorio actual");
    } else {
        printf("Actualmente en: %s\n", cur_dir);
    }
>>>>>>> b3b30fe092815a3c18e4bd248bebcebbf0c7d5df
}

// Cambia de directorio
void changedir( char * dir, char * cur_dir ) {
<<<<<<< HEAD
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
=======
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
>>>>>>> b3b30fe092815a3c18e4bd248bebcebbf0c7d5df
}

// Elimina un archivo
void removefile( char * file ) {
<<<<<<< HEAD
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
=======
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
>>>>>>> b3b30fe092815a3c18e4bd248bebcebbf0c7d5df
}

// Obtiene el tipo de fichero
char filetype(mode_t f_mode) {
<<<<<<< HEAD
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
=======
    switch (f_mode & S_IFMT) {
        case S_IFSOCK:  return 's';
        case S_IFLNK:   return 'l';
        case S_IFREG:   return '-';
        case S_IFBLK:   return 'b';
        case S_IFDIR:   return 'd';
        case S_IFCHR:   return 'c';
        case S_IFIFO:   return 'p';
        default:        return '?';
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
>>>>>>> b3b30fe092815a3c18e4bd248bebcebbf0c7d5df
}

// Lista un directorio
void listdir( int argc, char * argv[] ) {
<<<<<<< HEAD
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
=======
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
                        thora_actual = time(NULL);
                        shora_actual = localtime(&thora_actual);
                        shora_fichero = localtime(&file_info.st_mtime);
                        if ((shora_actual->tm_year) == (shora_fichero->tm_year)) {
                            strftime(hora_fichero, sizeof(hora_fichero), "%b %d %H:%M", shora_fichero);
                        } else {
                            strftime(hora_fichero, sizeof(hora_fichero), "%b %d %Y", shora_fichero);
                        }
                        printf("%s ", hora_fichero);
                    }
                    printf("%s\n", sdir->d_name);
                }
            } // endif
        } // endwhile
        closedir(pdir);
    }
>>>>>>> b3b30fe092815a3c18e4bd248bebcebbf0c7d5df
}
