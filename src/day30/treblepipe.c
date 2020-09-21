#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#define N 200


int main(int argc, char **argv)
{
	int i, len, ret, fp[2];
	pid_t pid;
	char buf[N];
	
	ret = pipe(fp);

	assert(!ret);

	for(i = 0; i < 2; i++)
	{
		pid = fork();
		if(0 == pid)
		{
			break;
		}
	}

	if(0 == i)
	{
		write(fp[1], "hello\n", strlen("hello\n"));
		close(fp[1]);
	}
	if(1 == i)
	{
		write(fp[1], "world\n", strlen("hello\n"));
		close(fp[1]);
	}

	if(pid > 0)
	{
		len = read(fp[0], buf, sizeof(buf));
		write(STDOUT_FILENO, buf, len);
	}
	for(i = 2; i > 0; i--)
	{
		wait(NULL);
	}



	return 0;
}
