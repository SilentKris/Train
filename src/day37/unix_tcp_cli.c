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
#include <sys/un.h>
//本地流式套接字客户端
int main(void)
{
    int sockfd,ret;
    sockfd = socket(AF_LOCAL, SOCK_STREAM  ,0); //创建本地套接字


    /* 地址信息 (关联一个文件) */

    struct sockaddr_un myaddr;
    bzero(&myaddr,  sizeof(myaddr));
    myaddr.sun_family = AF_LOCAL; 
    strcpy(myaddr.sun_path, "mysocket");

    ret = connect(sockfd, (struct sockaddr *)&myaddr,sizeof(myaddr)); //连接服务器
    if(ret==-1){
        perror("connect");
        exit(-1);
    }
    printf("connect success\n");
    char buf[256];
    while(1){
        
        gets(buf);
        if(0==strcmp(buf,"quit")){
            break;
        }
        write(sockfd,buf,sizeof(buf));  //发送
    }
    close(sockfd);  //关闭

    return 0;
}
