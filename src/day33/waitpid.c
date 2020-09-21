#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{

	pid_t wpid;
	int status;
	pid_t pid = fork();

	if(0 == pid)
	{
		printf("Im child ,Im sleep!\n");
		sleep(10);
		printf("Im child, Im exit\n");
		exit(0);

	}
	else
	{
		while(1)
		{
			if((wpid = waitpid(pid, &status, WNOHANG)) == -1)
			{
				perror("child process is something is wrong!\n");
				return -1;
			}
			if(wpid == 0)
			{
				printf("Im  parent process, Im wait child process\n");
				sleep(1);
			}
			if(wpid == pid)
			{
				printf("Im parent process, I get child process %d, Im exit\n", pid);
				break;
			}
		}
	}




	return 0;
}
