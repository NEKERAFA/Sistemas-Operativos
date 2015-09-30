#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>



#define MAXENTRADA 2048

struct COMANDO{
  char * nombre;
  void (*funcion)(char**);
};

void ProcesarEntrada (char *tr[]); 


void Cmd_fin(char *tr[])
{
  exit(0);
}



void Cmd_pwd(char *tr[])
{
  char dir[MAXENTRADA];
  if (getcwd(dir,MAXENTRADA)==NULL)
	perror("imposible obtener directorio actual");
  else
	printf ("%s\n",dir);
}


void Cmd_chdir(char *tr[])
{
  if (tr[0]==NULL)
	Cmd_pwd(tr);
  else if (chdir(tr[0])==-1)
	perror ("Imposible cambiar directorio");
}

void Cmd_pid(char *tr[])
{  
  if (tr[0]==NULL)
       printf ("Pid de shell: %d\n",getpid());
  else if (!strcmp ("-p",tr[0]))
      printf ("Pid del padre del shell: %d\n",getppid());

}


static struct COMANDO C[]={
   {"fin",Cmd_fin},
   {"exit",Cmd_fin},
   {"quit",Cmd_fin},
   {"pid",Cmd_pid},
   {"pwd", Cmd_pwd},
   {"cd",Cmd_chdir},
   {NULL,NULL},
  };

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

  int i;

  for (i=0; C[i].nombre!=NULL; i++)
    if (!strcmp(C[i].nombre,tr[0])){
        (*C[i].funcion)(tr+1);
	return;
    }
  printf ("%s no encontrado\n",tr[0]);
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


