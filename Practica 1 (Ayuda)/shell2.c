#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXENTRADA 2048
#define FIN 1
#define PID 2
#define PWD 3
#define CHDIR 4



void Cmd_pwd()
{
  char dir[MAXENTRADA];
  if (getcwd(dir,MAXENTRADA)==NULL)
	perror("imposible obtener directorio actual");
  else
	printf ("%s\n",dir);
}

void Cmd_chdir(char * dir)
{
  if (dir==NULL)
	Cmd_pwd();
  else if (chdir(dir)==-1)
	perror ("Imposible cambiar directorio");
}


void Cmd_pid(char * arg)
{
  if (arg==NULL)
       printf ("Pid de shell: %d\n",getpid());
  else if (!strcmp ("-p",arg))
      printf ("Pid del padre del shell: %d\n",getppid());
}

int TrocearCadena(char * cadena, char * trozos[])
{
 int i=1;
 if ((trozos[0]=strtok(cadena," \n\t"))==NULL)
    return 0;
 while ((trozos[i]=strtok(NULL," \n\t"))!=NULL)
    i++;
 return i;
}

int  CodigoEntrada (char *tr)
{
  if (!strcmp(tr,"fin"))
	return FIN;
  if (!strcmp(tr,"quit"))
	return FIN;
  if (!strcmp(tr,"exit"))
	return FIN;
  if (!strcmp(tr,"pid"))
	return PID;
  if (!strcmp(tr,"pwd"))
	return PWD;
  if (!strcmp(tr,"cd"))
	return CHDIR;
}

void ProcesarEntrada (char *tr[])
{
  switch (CodigoEntrada(tr[0])){
     case FIN: exit (0); break;
     case PID:  Cmd_pid(tr[1]); break;
     case PWD:  Cmd_pwd();break;
     case CHDIR: Cmd_chdir(tr[1]); break;
     default: printf ("%s no encontrado\n", tr[0]);
  }
}

int main (int argc, char *argv[])
{
  char entrada[MAXENTRADA];
  char *tr[MAXENTRADA/2];

while (1) {
   printf ("-> ");
   fgets (entrada,MAXENTRADA,stdin);
   if (TrocearCadena(entrada,tr)==0)
	continue;
   ProcesarEntrada(tr);
  }
}
