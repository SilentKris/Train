#include <stdio.h>
#include <sys/types.h>      
#include <sys/socket.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
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
	int i;
	char data[20]="hello UDPservice";
	for(i=0;i<20;i++)  
	{
		//usleep(1000);
		sendto(sockfd, data,sizeof(data),0,(const struct sockaddr *)&addr, sizeof(addr));
	}
	close(sockfd);
	return 0;
}

