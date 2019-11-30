#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <ctype.h>
FILE *f;

int num_fork(int n)
{
        int i;
        for(i=1; i<n; i++)
        {
                if(fork()==0)
                {
                        return (i);
                }
        }
        return (0);
}
int main()
{
        char nombre[15];
	int cola_espera[4];
        int timpo, reg, tim_ini, tim_fin, lugar, espera;
        char r[10];
        int n, op,m,hijo;
        i=num_fork(5);
        //char *nomarchivo;
        //nomarchivo="Ids.txt";
        //remove(nomarchivo);
	printf("-----Menu-----\n");
	printf("1. Datos proceso\n");
	printf("2. Ejecuta\n");
	printf("3. Mostrar Espera");
	printf("4. Salir\n");
	scanf("%d",&op);
	switch (op)
	{
		case i:
			
	}
        switch (i)
                {
                        case 1:
					printf("Proceso uno Nombre");
                                        popen();
                                        i=getenv();
                                        fprintf(f,"Id1:%d\n",i);
                                        pclose();
                                        exit(3);

                        case 2:
                                        popen();
					i=getenv();
                                        fprintf(f,"Id2:%d\n",i);
                                        pclose();
                                        exit(3);
                        case 3:
                                        popen();
                                        i=getenv();
                                        fprintf(f,"Id3:%d\n",i);
                                        pclose();
                                        exit(3);
                        case 4:
                                        popen();
                                        i=getenv();
                                        fprintf(f,"Id4:%d\n",i);
                                        pclose();
                                        exit(3);
			default:
                                m=main(hijo);
                                m=main(hijo);
                                m=main(hijo);
                                m=main(hijo);
                                f=popen("Ids.txt","r+");
                                //printf("Valor de wwait %d",m);
                                while (fscanf(f,"%s",r) != EOF)
                                {
                                        printf("%s\n",r);

                                }
                }
}






