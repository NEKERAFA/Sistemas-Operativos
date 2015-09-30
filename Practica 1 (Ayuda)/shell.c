#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXENTRADA 2048




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

void ProcesarEntrada (char *tr[])
{
  if (tr[0]==NULL)
	return; 
  if (!strcmp(tr[0],"fin"))
	exit (0);
  else if (!strcmp(tr[0],"quit"))
	exit (0);
  else if (!strcmp(tr[0],"exit"))
	exit (0);
  else if (!strcmp(tr[0],"pid"))
	Cmd_pid(tr[1]);
  else if (!strcmp(tr[0],"pwd"))
	Cmd_pwd();
  else if (!strcmp(tr[0],"cd"))
	Cmd_chdir(tr[1]);
  else printf ("%s no encontrado\n", tr[0]);
}

int main (int argc, char *argv[])
{
  char entrada[MAXENTRADA];
  char *tr[MAXENTRADA/2];

while (1) {
   printf ("-> ");  
   fgets (entrada,MAXENTRADA,stdin);
   TrocearCadena(entrada,tr);
   ProcesarEntrada(tr);
  }
}
