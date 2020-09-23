#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

#define N 256

int sockfd, ret, connfd;

int main(int argc, char **argv)
{
	char *timbuf;
	time_t tim;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6668);
	addr.sin_addr.s_addr = inet_addr("192.168.162.168");  //填写自己的ip地址

	ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)); // 关联sockfd和addr
	if(-1 == ret)
	{
		perror("bind");
		exit(-1);
	}
	listen(sockfd, 32); //开机

	while(1)
	{

		printf("wait...\n");
		connfd = accept(sockfd,NULL,NULL);  //接听(建立通信)
		printf("connect a client\n");

		char buf[256];
		memset(buf, '\0', sizeof(buf));

		while(1)
		{
			ret = read(connfd, buf, sizeof(buf));
			if(ret <= 0)
			{
				puts("client quit");
				break;
			}
			puts(buf);
			tim = time(NULL);
			timbuf = ctime(&tim);
			if(strcmp("time", buf) == 0)
			{
				write(connfd, timbuf, strlen(timbuf));
				puts(timbuf);
			}
			if(strcmp("quit", buf) == 0)
			{
				close(connfd);
				close(sockfd);
				return 0;
			}
			memset(buf, '\0', sizeof(buf));
		}
	}


}
