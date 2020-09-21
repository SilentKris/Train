#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fp[2];

	int ret = pipe(fp);
	if(ret != 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		return -1;
	}


	pid_t pid = fork();
	if(0 == pid)
	{
		close(fp[1]);
		dup2(fp[0], STDIN_FILENO);
		execlp("wc", "wc", "-l", NULL);
		close(fp[0]);

		exit(1);
	}

	if(pid > 0)
	{
		close(fp[0]);
		dup2(fp[1], STDOUT_FILENO);
		execlp("ls", "ls", NULL);
		close(fp[1]);
	}
	wait(NULL);

	return 0;
	wait(NULL);
}
