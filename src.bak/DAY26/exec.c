#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();

	if(-1 == pid)
	{
		perror("fork filed:");
		return 0;
	}
	if(0 ==  pid)
	{
	//	if(execl("/home/farsight/test/src/DAY26/a.out", "a.out", NULL) == -1)
		if(execvp("/home/farsight/test/src/DAY26/a.out", "a.out", NULL) == -1)
		{
			perror("error");
			exit(1);
		}

		printf("原进程执行语句");

		exit(0);
	}


	return 0;
}
