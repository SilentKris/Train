#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (-1 == pid)
	{
		perror("create failed");
		return -1;
	}
	if(0 == pid)
	{
		int sum = 1, i;
		for(i = 0; i <= 100; i++)
		{
			sum += i;
		}
		printf("sum = %d\n", sum);
		return 0;
		
	}
		if(0 < pid)
			wait();
		printf("This is parent\n");



	return 0;
}
