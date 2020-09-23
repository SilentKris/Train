#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

#define PORT 5555
#define ADDRESS "0"


int sockfd, ret;

void Udpserver(int sockfd, struct sockaddr_in addr);

int main(int argc, char **argv)
{

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(ADDRESS);  //填写自己的ip地址

	Udpserver(sockfd, addr);

	close(sockfd);
	return 0;
}



void Udpserver(int sockfd, struct sockaddr_in addr)
{

	struct sockaddr_in src_addr; //客户端地址
	char buf[1024];				//

	int ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)); // 关联sockfd和addr

	
	if(-1 == ret)
	{
		perror("bind");
		exit(-1);
	}

	memset(buf, 0, sizeof(buf));

	socklen_t addrlen = sizeof(src_addr);

	while(1)
	{
		ret = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&src_addr, &addrlen);

		printf("recv %d : %s\n", ret, buf);

		sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&src_addr, addrlen);

	}
}
