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
int main(void)
{
	struct stat buf1, buf2;


	int fd1 = open("./f1",O_RDWR);
	int fd2 = open("./f2",O_RDWR);
	char buf[128];


	//需求：只要管道有数据，立即读取处理
	while(1){
		stat("./f1", &buf1);
		stat("./f2", &buf2);
		if(&buf1.st_size > 0)
		{
			bzero(buf,sizeof(buf));
			read(fd1,buf,sizeof(buf));
			printf("read f1:%s\n",buf);

		}
		if(&buf2.st_size)
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

