#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int sockfd;



void *revmsg(void *arg)
{
	char buf[256];
	int ret;
	while(1)
	{
		ret = recv(sockfd, buf, sizeof(buf), 0);
		if(ret == -1)
		{
			break;
		}
	}
	pthread_exit(&tid);
}



int main(void)
{
	int ret;
	pthread_t tid;
	pthread
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	printf("Im client, sockfd:%d\n", sockfd);
	if(sockfd == -1){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in cliaddr;
	cliaddr.sin_family = PF_INET;
	cliaddr.sin_port = htons(5555);
	cliaddr.sin_addr.s_addr = inet_addr("192.168.8,141");
	ret = connect(sockfd,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
	if(ret ==-1){
		perror("connect");
		exit(EXIT_FAILURE);
	}

	send(sockfd,data,sizeof(data),0);

	close(sockfd);
	return 0;
}



