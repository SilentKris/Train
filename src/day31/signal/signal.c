#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void operation(int signum)
{

	printf("信号捕获%d, 弄不死我!\n", signum);
	exit(1);
}


int main(int argc, char **argv)
{
	signal(SIGINT, SIG_IGN);
	while(1)
	{
		printf("开始休眠1秒钟\n");
		sleep(1);
	}

	return 0;
}
