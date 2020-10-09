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
#include <sys/un.h>
//本地流式套接字 服务器

int main(void)
{
    int sockfd,ret,connfd;
    sockfd = socket(AF_LOCAL, SOCK_STREAM  ,0); //创建本地套接字

    /* 地址信息 (关联一个文件) */

    struct sockaddr_un myaddr;
    bzero(&myaddr,  sizeof(myaddr));
    myaddr.sun_family = AF_LOCAL; 
    strcpy(myaddr.sun_path, "mysocket");

    
    remove("mysocket"); //删除文件
    ret = bind(sockfd,(struct sockaddr *)& myaddr,sizeof(myaddr));//绑定地址信息
    if(ret==-1){
        perror("bind");
        exit(-1);
    }

    listen(sockfd,32);  //设置监听队列



    while(1){
        printf("wait...\n");
        connfd = accept(sockfd,NULL,NULL);  //建立连接
        printf("connect a client\n");
        char buf[256];
        while(1){

            bzero(buf,sizeof(buf));         //通过bzero函数清空buf
            //memset(buf,0,sizeof(buf));    //通过memset清空
            ret = read(connfd,buf,sizeof(buf));  //接收
            if(ret<=0){
                printf("client quit\n");
                break;

            }
            printf("recv:%s\n",buf);
            //解析客户端请求 根据请求给响应数据

            if(0==strcmp(buf,"time")){
                time_t val = time(NULL);
                char *ptr = ctime(&val);
                char tbuf[32];
                //strcpy(tbuf,ptr); 
                snprintf(tbuf,sizeof(tbuf),"TIME:%s",ptr);
                write(connfd,tbuf,sizeof(tbuf));
            }

        }

        close(connfd);  //关闭连接通道 connfd
    }
    close(sockfd); //关闭套接字

    return 0;
}
