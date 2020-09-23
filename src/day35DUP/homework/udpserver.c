#include <stdio.h>
#include <sys/types.h>      
#include <sys/socket.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
int main(void)
{
	int sockfd;
	int ret;
	struct sockaddr_in addr;
	addr.sin_family = PF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockfd = socket(PF_INET, SOCK_DGRAM, 0);
	if(sockfd==-1){
		printf("socket");
		exit(-1);
	}
	ret = bind(sockfd, (const struct sockaddr *)&addr,sizeof(addr));
	if(ret==-1){
		perror("bind");
		exit(-1);
	}
	char buf[1024];
	while(1){
		usleep(1000);
		memset(buf,0,sizeof(buf));
		ret = recvfrom(sockfd, buf,sizeof(buf),0,NULL,NULL);
		if(ret<=0){
			break;
		}
		printf("recv %d bytes,buf is %s\n",ret,buf);
	}

	close(sockfd);

	return 0;
}

