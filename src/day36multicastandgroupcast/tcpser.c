#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
//搭建tcp服务器 （1.处理客户的连接  2.处理客户的请求） 
//tcp并发服务器：  子进程负责：客户的请求  父进程负责:连接请求



pthread_t tid;

void *do_client(void *argv)
{
	int connfd  = *(int *)argv;
	int ret;
	char buf[256];
	//处理客户的请求
	while(1){

		bzero(buf,sizeof(buf));         
		ret = read(connfd,buf,sizeof(buf));  
		if(ret<=0){
			printf("client quit\n");
			break;
		}
		printf("recv:%s\n",buf);
	}
		close(connfd);
		pthread_exit(0);
		printf("mytid = %lu\n", mytid);

}
int main(void)
{
	int sockfd,ret,connfd;
	extern pthread_t tid;
	sockfd = socket(AF_INET, SOCK_STREAM  ,0); 

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);
	addr.sin_addr.s_addr = inet_addr("192.168.2.95");  


	ret = bind(sockfd,(struct sockaddr *)&addr,sizeof(addr));
	if(ret==-1){
		perror("bind");
		exit(-1);
	}

	listen(sockfd,32);  

	while(1){
		printf("wait...\n");
		connfd = accept(sockfd,NULL,NULL);  
		printf("connect a client\n");

		pthread_create(&tid, NULL, do_client, &connfd);
		pthread_detach(tid);

	}
	close(sockfd);

	return 0;
}
