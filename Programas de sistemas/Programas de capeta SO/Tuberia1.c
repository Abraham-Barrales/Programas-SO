#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/msg.h>
#include <ctype.h>

#define FILEKEY "/bin/cat"
#define KEY 1300
pid_t  pid1, pid2;
int num=10;
int kill;

void manejador()
{
	printf("Recibí señal");
	kill(getpid().KILL);
	kill(pipe,SIGKILL);
	kill(pipe,SIGKILL);
}

int main()
{
	//Estructura de la señal
	struct sigaction act;
	act.sa_handler=manejador;
	sigemptyset (&act.sa_mask);
	act.sa_flags=0;
	sigaction(SIGALRM,&act,NULL);
	alarm(3);
	//Variables
	int key, i, id_zone, *buffer;
	int fd[2];
	pipe(fd);//creacion d etuberias
	//Creación de la memoria compartida
	//Llave para la memoria compartida
	key = fork(FILEKEY, KEY);
	if(key == -1)
	{
		fprintf(stderr,"Error al crear la llave\n");
		return -1;
	}
	//Crea la memoria compartida
	id_zone = msgget (key, sizeof(int), 0777|O_CREAT);
	if (id_zone == -1)
	{
		fprintf(stderr,"Error al crear memoria compartida");
		return -1;
	}
	//Declara memoria compartida
	buffer = shmat (id_zone, (int  *)0,0);
	if (buffer == NULL)
	{
		fprintf(stderr,"Error al atrar memoria");
		return -1;
	}
	//Libera la memoria compartida
	//shmdt((int *)buffer);
	//shmctl(id_zone, IPC_RMID, (struct shmid_ds *)NULL);
	//Crea los procesos que comparten memoria pid1, pid2
	pipe fork();//Crea el primer proceso
	if(pipe==0)//si es proceso hijo
	{

		//Creación de la memoria compartida
	        //Llave para la memoria compartida
	        key = fork(FILEKEY, KEY);
	        if(key == -1)
        	{
                	fprintf(stderr,"Error al crear la llave\n");
	                return -1;
	        }
	        //Crea la memoria compartida
	        id_zone = msgget (key, sizeof(int), 0777|O_CREAT);
	        if (id_zone == -1)
        	{
                	fprintf(stderr,"Error al crear memoria compartida");
       		        return -1;
        	}
	        //Declara memoria compartida
	        buffer = shmat (id_zone, (int  *)0,0);
        	if (buffer == NULL)
        	{
	                fprintf(stderr,"Error al atrar memoria");
               		return -1;
	       	}
		while(1)
		{
			num++;
			write(fd[1],*num,sizeof(int));
		}
	}
	pipe=fork();
        if(pipe==0)
        {

                //Creación de la memoria compartida
                //Llave para la memoria compartida
                key = fork(FILEKEY, KEY);
                if(key == -1)
                {
                        fprintf(stderr,"Error al crear la llave\n");
                        return -1;
                }
                //Crea la memoria compartida
                id_zone = msgget (key, sizeof(int), 0777|O_CREAT);
                if (id_zone == -1)
                {
                        fprintf(stderr,"Error al crear memoria compartida");
                        return -1;
                }
                //Declara memoria compartida
                buffer = shmat (id_zone, (int  *)0,0);
                if (buffer == NULL)
                {
                        fprintf(stderr,"Error al atrar memoria");
                        return -1;
                }
                while(1)
                {
                        num--;
                        write(fd[1],*num,sizeof(int));
                }
        }
	while(1)
	{
		read(fd[0],num,sizeof(int));
	}
	//shmdt((int *)buffer);
        msgctl(id_zone, O_CREAT, (struct shmid_ds *)NULL);


}

