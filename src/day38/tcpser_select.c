#include <stdio.h>
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
#include <sys/wait.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


//搭建tcp服务器 （1.处理客户的连接 sockfd   2.处理客户的请求 connfd） 
//io多路服务器 模拟的并发服务器

int do_client(int connfd)
{
    int ret;
    char buf[256];
    //处理客户的请求
    while(1){

        bzero(buf,sizeof(buf));         
        ret = read(connfd,buf,sizeof(buf));  
        if(ret<=0){
            printf("client quit\n"); 
            close(connfd);
            break;
        }
        printf("recv:%s\n",buf);
        //解析客户端请求 根据请求给响应数据
    }
}


//tcp服务器初始化
int tcp_init(char *ip,int port)
{
    int sockfd,ret;
    sockfd = socket(AF_INET, SOCK_STREAM  ,0); 

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);  


    ret = bind(sockfd,(struct sockaddr *)&addr,sizeof(addr));
    if(ret==-1){
        perror("bind");
        exit(-1);
    }

    listen(sockfd,32);  

    return sockfd;
}
int main(void)
{
    int sockfd,connfd,ret;
    sockfd = tcp_init("0",5555); 
    
    char buf[256];


    /* 创建一张表 添加文件描述符 sockfd */
    fd_set rdfs,tmpfs;

    FD_ZERO(&tmpfs);        //清空表
    FD_SET(sockfd,&tmpfs);  //添加sockfd 

    int maxfd = sockfd;

    while(1){
        rdfs = tmpfs; //修正rdfs    

        ret = select(maxfd+1,&rdfs, NULL,NULL,NULL);
        if(ret==-1){
            perror("select");
            exit(-1);
        }
        
        // sockfd 或者 connfd 准备好了 
        
        if( FD_ISSET(sockfd,&rdfs) ){
            //sockfd准备好了，可以建立连接
            int connfd = accept(sockfd,NULL,NULL);
            printf("连接上了一个客户:%d\n",connfd);
               
            //将connfd 添加到表中 tmpfs 修正maxfd 
            FD_SET(connfd,&tmpfs);
			if(maxfd < connfd)
				maxfd = connfd;

		}
		else{
			//connfd准备好了，可以收发数据

			int i=4;
			for(i=4;i<=maxfd;i++){

				if( FD_ISSET(i,&rdfs) ){

					printf("connfd:%d 准备好了\n",i);
					bzero(buf,sizeof(buf)); 
					ret = recv(i,buf,sizeof(buf),0);
					if(ret<=0){
						printf("quit\n");
						FD_CLR(i,&tmpfs);
						close(i);
					}
					printf("buf:%s\n",buf);
				}
			}
		}
	return 0;
}
