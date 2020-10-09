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
	printf("Im client, sockfd:%d\n", sockfd);
	if(sockfd == -1){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in sevaddr;
	sevaddr.sin_family = PF_INET;
	sevaddr.sin_port = htons(8888);
	sevaddr.sin_addr.s_addr = inet_addr("192.168.2.95");
	ret = connect(sockfd,(struct sockaddr *)&sevaddr,sizeof(sevaddr));
	if(ret ==-1){
		perror("connect");
		exit(EXIT_FAILURE);
	}
	int i;
	char data[20]="hello TCPservice";
	char buf[1025] = {0};

	for(i=0;i<20;i++)  
	{
		usleep(1000);
		send(sockfd,data,sizeof(data),0);

		recv(sockfd, buf, sizeof(buf), 0);
		puts(buf);
		bzero(buf, sizeof(buf));
	}
	close(sockfd);
	return 0;
}



