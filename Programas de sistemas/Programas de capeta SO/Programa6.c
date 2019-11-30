
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){ 
	pid_t pid;
	int n=3,i;
	for(i=0;i<n;i++)
		{
			pid=fork();
			if(pid!=0)
			break;
			else
			pid=fork();
		}
	printf("El padre del proceso %d es %d\n",getpid(),getppid());
}
