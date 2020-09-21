#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int i=0;
	pid_t pid;
	
	printf("Im parent process:%d, my parent process:%d\n", getpid(), getppid());
	for(i=0; i<3; i++)
	{
		pid = fork();
		if(-1 == pid)
		{
			perror("process creat");
			return -1;
		}
		
		if( 0 == pid)
		{
			printf("child proces:%d, parent process:%d\n", getpid(), getppid());
		}
	}


	return 0;
}
