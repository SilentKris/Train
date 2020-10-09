#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

int sockfd, ret, connfd;

void sighandler(int signum)
{
	printf("signum = %d\n", signum);
	close(connfd);
	close(sockfd);
	raise(9);
}

int main(int argc, char **argv)
{
	signal(SIGINT, sighandler);
//
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6666);
	addr.sin_addr.s_addr = inet_addr("192.168.162.169");  //填写自己的ip地址

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
			ret = recv(connfd, buf, sizeof(buf), 0);
			if(ret <= 0)
			{
				puts("client quit");
				break;
			}
			memset(buf, 0, sizeof(buf));
			printf("resv: %s\n", buf);
		}
	}


	return 0;
}
