#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#define backlog 32
int main(void)
{
	int sockfd,connfd;
	int ret;
	struct sockaddr_in addr;
	bzero(&addr,sizeof(addr));

	addr.sin_family=PF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	sockfd = socket(PF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	
	ret = bind(sockfd, (struct sockaddr *)&addr,sizeof(addr)); 
	if(ret==-1){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	
	listen(sockfd,backlog);
	
	connfd = accept(sockfd,NULL,NULL);
	
	printf("connect a client !\n");
	
	char buf[1024];
	
	while(1)
	{
		usleep(5000);
		bzero(buf,sizeof(buf));
		ret = recv(connfd,buf,sizeof(buf),0);
		if(ret <= 0 ){
			printf("client quit\n");
			break;
		}
		printf("recv %d bytes,buf is %s\n",ret,buf);
	}
	close(connfd);
	close(sockfd);
	return 0;
}

