#include <stdio.h>
#include <unistd.h>
volatile int count = 1;

int main(int argc, char **argv)
{
	int i;
	pid_t pid, ppid;
	printf("函数进程：pid = %d,ppid = %d\n", getpid(), getppid());
	pid = fork();
	if(-1 == pid)
	{
		perror("process");
		return -1;
	}
	else if( 0 == pid)
	{
		while(1){
			printf("Im Child Process:count = %d\n", count+=2);
			sleep(1);
		}
	}
	else
	{
		while(1)
		{
			printf("Im Parent Process:count = %d\n", ++count);
			sleep(1);
		}
	}

	return 0;
}
