#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

void Udpclient(int sockfd, struct sockaddr_in addr);



int main(int argc, char **argv)
{
	int sockfd;

	if(argc != 3)
	{
		fprintf(stdout, "Usage: %s <address> <port>\n", argv[0]);
		return -1;
	}

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));
	addr.sin_addr.s_addr = inet_addr(argv[1]);  //填写自己的ip地址

	Udpclient(sockfd, addr);

	close(sockfd);
	return 0;
}


void Udpclient(int sockfd, struct sockaddr_in addr)
{
	int ret;
	char buf[1024];
	socklen_t addrlen = sizeof(addr);
	memset(buf, 0, sizeof(buf));


	while(1)
	{
		gets(buf);
		puts("input is complete!");

		sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&addr, addrlen);
		ret = recvfrom(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&addr, &addrlen);
		puts(buf);
	}


}
