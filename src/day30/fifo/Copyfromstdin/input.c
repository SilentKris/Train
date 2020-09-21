#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define N 200

int main(int argc, char **argv)
{
	int ret;
	char buf[N];

	if(0 != access(argv[1], F_OK))
	{

		ret = mkfifo(argv[1], 0640);
		if(-1 == ret)
		{
			perror(argv[1]);
			return -1;
		}
	}

	int fd = open(argv[1], O_WRONLY);

	while(1)
	{
		fgets(buf, sizeof(buf)-1, stdin);

		write(fd, buf, strlen(buf));

	}






	return 0;
}
