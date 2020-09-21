#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define N 200

int main(int argc, char **argv)
{
	int fp[2];
	char buf[N];
	pid_t pid;

	if(pipe(fp) < 0)
	{
		perror("pipe create failed!\n");
		return -1;
	}

	pid = fork();
	if(0 == pid)
	{
		close(fp[1]); //每个进程都有一对描述符，需关掉一个
		int len = read(fp[0],buf, 20 );
		write(STDOUT_FILENO, buf, len);
		puts(strerror(E2BIG));
		close(fp[0]);
	}
	if(pid > 0)
	{
		close(fp[0]);
		write(fp[1], "hello world\n", strlen("hello world\n"));
		close(fp[1]);
	}

	return 0;
}
