#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	pid_t pid = fork();

	if( 0 < pid)
		exit(1);

	if(0 == pid)
	{
		int i ;
		time_t t;

	 pid = setsid();
	 if(-1 == pid)
	 {
		 perror("setsid");
		 return -1;
	 }


		chdir("/tmp");


		int fdtablesize = getdtablesize();
		for(i = 0; i < fdtablesize; i++)
		{
			close(i);
		}

		umask(0);

		FILE *fp;
		
		fp = fopen("time", "w+");
		freopen("time", "w+", stdout);

		while(1)
		{
			time(&t);
			fprintf(fp, "%d-%d-%d %d:%d:%d\n",
					localtime(&t)->tm_year+1900, 
					localtime(&t)->tm_mon,
					localtime(&t)->tm_mday, 
					localtime(&t)->tm_hour, 
					localtime(&t)->tm_min, 
					localtime(&t)->tm_sec);
			fflush(fp);
			sleep(1);
		}
	}	

	return 0;
}
