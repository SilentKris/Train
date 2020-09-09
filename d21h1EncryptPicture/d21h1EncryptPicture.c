#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char char_count[40] = {0};
char replace[20] = "hello wrold!";
int offset = 1000;
int flag = 0;


int Encrypt(int fd);
void Unencrypt(int fd);

int main(int argc, char **argv)
{
	int file;
	file = open(argv[1], O_RDWR);
	if(-1 == file)
	{
		perror(argv[1]);
		return -1;
	}
	
	if(0 == strcmp(argv[2], "jiami") && (0 == flag))
		Encrypt(file);
	if(0 == strcmp(argv[2], "jiemi") && (1 == flag)
	else
		printf("你没有输入合法的操作\n");

	printf("%d\n", strcmp(argv[2], "jiami"));
	close(file);
	return 0;

}


int Encrypt(int fd)
{
	int read_size;
	lseek(fd, offset, SEEK_SET);
	read_size = read(fd, char_count, 20);
	if(-1 == read_size)
	{
		perror("This file");
		return -1;
	}
	lseek(fd, offset, SEEK_SET);
	write(fd, replace, read_size);
	flag = 1;
	return 0;
}

void Unencrypt(int fd)
{
	if(1 == flag)
	{
		write(fd, char_count, 20);
		flag = 0;
	}
}
