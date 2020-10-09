/*************************************************************************
  > File Name: readfifo.c
  > Author: 
  > Mail: 
  > Created Time: Thu 24 Sep 2020 10:14:32 AM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>

int main(void)
{
	
	char buf[256];

	int fd1 = open("./f1",O_RDWR);
	int fd2 = open("./f2",O_RDWR);
	struct stat buf1, buf2;

	fd_set tmpfs, refs;

	FD_ZERO(&tmpfs);
	FD_SET(fd1, &tmpfs);
	FD_SET(fd2, &tmpfs);


	//需求：只要管道有数据，立即读取处理
	while(1){
		refs = tmpfs;
		select(fd1, &refs, NULL, NULL, NULL);
		if(FD_ISSET(fd1, &refs))
		{			
			bzero(buf,sizeof(buf));
			read(fd1,buf,sizeof(buf));
			printf("read f1:%s, buf1.size = %ld\n",buf,buf1.st_size);
		}
		if(FD_ISSET(fd2, &refs))
		{
			bzero(buf,sizeof(buf));
			read(fd2,buf,sizeof(buf));
			printf("read f2:%s\n",buf);
		}

	}

	close(fd1);
	close(fd2);




	return 0;
}

