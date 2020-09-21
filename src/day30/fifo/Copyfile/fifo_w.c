#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>


#define N 200

int main(int argc, char **argv)
{
	int len;
	char buf[N];

	if(argc < 3)
	{
		fprintf(stderr,"Usage:%s <dest file> <src file>\n", argv[0]);
	}

	int fd1 = open(argv[1], O_WRONLY);
	int fd2 = open(argv[2], O_RDONLY);

	if(-1 == fd1)
	{
		perror(argv[1]);
		return -1;
	}
	if(-1 == fd2)
	{
		perror(argv[2]);
		return -1;
	}

	while(1)
	{
		len = read(fd2, buf, sizeof(buf)-1);
		if(0 == len)
		{
			close(fd2);
			close(fd1);
			printf("Copy is done\n");
			return 0;
		}
		
		write(fd1, buf, len);
	}
}
