#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
	int sockfd;
	int ret;
	sockfd = socket(PF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in sevaddr;
	sevaddr.sin_family = PF_INET;
	sevaddr.sin_port = htons(8888);
	sevaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ret = connect(sockfd,(struct sockaddr *)&sevaddr,sizeof(sevaddr));
	if(ret ==-1){
		perror("connect");
		exit(EXIT_FAILURE);
	}
	int i;
	char data[20]="hello TCPservice";

	for(i=0;i<20;i++)  
	{
		//usleep(1000);
		send(sockfd,data,sizeof(data),0);
	}
	close(sockfd);
	return 0;
}



