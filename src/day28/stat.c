#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


#define N 200

int main(int argc, char **argv)
{
	int status;
	struct stat buffer;
	status = stat(argv[1], &buffer);
	if(-1 == status)
	{
		perror(argv[1]);
		return -1;
	}
	printf("%ld\n",buffer.st_atime);



	return 0;
}
