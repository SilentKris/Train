#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define N 200
int main(int argc, char **argv)
{
	int len;
	char buf[N];
	int fd = open(argv[1], O_RDONLY);

	while(1)
	{
		 len = read(fd, buf, strlen(buf));

		write(2, buf, len);
	}


	return 0;
}
