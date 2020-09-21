#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define N 300

int main(int argc, char **argv)
{
	char char_count[N] = {0};
	int read_size=0, write_size, offset = 0;

	int file_src = open(argv[1], O_RDWR | O_APPEND);
	int file_dest = open(argv[2], O_RDWR | O_CREAT, S_IRWXU);	
	
	if(-1 == file_src)
	{
		perror(argv[1]);
		return -1;
	}
	if(-1 == file_dest)
	{
		perror(argv[2]);
		return -2;
	}
	while(1)
	{
		offset += read_size;

		lseek(file_src, offset, SEEK_SET);
		read_size = read(file_src, char_count, 250);

		if(0 == read_size)
		{
			printf("Copy is done!\n");
			printf("offset is %d\n", offset);
			printf("FOPEN_MAX = %d\n",FOPEN_MAX);
			close(file_src);
			close(file_dest);
			return 0;
		}
		lseek(file_dest, offset, SEEK_SET);
		write(file_dest, char_count, read_size);

	}
}
