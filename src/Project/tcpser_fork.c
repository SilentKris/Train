#include <stdio.h>
#include <sys/types.h>    
#include <sys/ipc.h>
#include <sys/msg.h>
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
#include <pthread.h>
#include "database.h"
#include "personmanage.h"
#include "datastruct.h"
#include "msgque.h"


int tcp_init(char *ip,int port);
int do_client(int connfd);


int usrpid[1000]; //用来存储用户的id，用于进程结束时删除其在线状态
pid_t wpid;       //用来存储用户所在进程的pid值
LNode *clihead;		//存储用户在线状态
sqlite3 *ppdb;		//用于打开本项目所创建库的库指针
int my_id;
int msgid;
char recvbuf[256];

//信号捕捉函数
void signal_handler(int sig)
{
	wpid = wait(NULL);
	Delet_LinkList(clihead, usrpid[wpid%1000]);
	puts("进程结束");

}

//线程：主要功能为接收信息发送
void *recev(void *arg)
{
	int connfd = *(int *)arg;
	while(1)
	{
		revmesg(my_id, recvbuf);
		send(connfd, recvbuf, sizeof(recvbuf), 0);
	}
}


int main(void)
{
	

	db_init(&ppdb);  //初始化建立所用表项
	
	clihead = CreatLinkList();  //创建在线用户

	signal(SIGCHLD,signal_handler); //注册SIGCHLD信号  

	msgid = msgget(0x2000, 0666 | IPC_CREAT);

/***************************************************
 *
 *			初始化端口
 *
 * *************************************************/
	int sockfd,connfd,ret;
	struct sockaddr_in cliaddr;
	socklen_t cliaddr_len = sizeof(cliaddr);
	sockfd = tcp_init("0",5555); 


/********************************************************

					逻辑主体

*********************************************************/
	while(1)
	{
		int ret;
		printf("wait...\n");
		connfd = accept(sockfd,(struct sockaddr *)&cliaddr, &cliaddr_len);  
		if(connfd == -1){
			if(errno == EINTR ){ //防止信号干扰
				continue;
			}
			else{
				exit(0);
			}
		}

		printf("connect a client\n"); 


		while(ret = Login(ppdb, connfd, clihead)) //用户登录注册
		{
			if(ret == 1)
				continue;
			if(ret == 2)
			{
				Regist(ppdb, connfd);
			}
		}

		pid_t pid = fork();                 
		if(pid==0)//子进程
		{
			close(sockfd);
			pthread_t tid;
			Trave_LinkList(clihead);
			my_id= Loc_LinkList(clihead)->type;//得到客户自己的id（type）	

			pthread_create(&tid, NULL, recev, &connfd);
			pthread_detach(tid);

			do_client(connfd); //子进程负责：客户请求
		}

		else 	//父进程
		{
			close(connfd);
			usrpid[pid%1000] = Loc_LinkList(clihead)->type;//记录登录用户的pid
			continue;
		}

	}
	close(sockfd);

	return 0;
}

/*************************************************

  服务器初始化


 ******************************************************/
int tcp_init(char *ip,int port)
{

	int sockfd,ret;
	sockfd = socket(AF_INET, SOCK_STREAM  ,0); 

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);  

	int on = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
	ret = bind(sockfd,(struct sockaddr *)&addr,sizeof(addr));
	if(ret==-1){
		perror("bind");
		exit(-1);
	}

	listen(sockfd,32);  

	return sockfd;
}

/*********************************************

  客户端发送请求处理

 *********************************************/
int do_client(int connfd)
{
	int ret, type, len;
	char sendbuf[256];
	char  name[11], msg[256];
	char *ptr;
	LNode *mid;

	send(connfd, "The message format is name:message", 50, 0);
	while(1)
	{	
		bzero(sendbuf,sizeof(sendbuf));         
		ret = read(connfd,sendbuf,sizeof(sendbuf));
		if(ret<=0){
			printf("client quit\n"); 
			close(connfd);
			exit(0);           
		}
		if(strspn(":", sendbuf) == 0)
		{
			send(connfd, "WRONG FORMAT\n", 20, 0);
			continue;
		}

		ptr = strstr(sendbuf, ":");
//		puts(sendbuf);
		*ptr = '\0';
		strcpy(name, sendbuf);
		strcpy(msg, ptr+1);

		//转发消息逻辑
		if((mid = Search_LinkList(clihead, -1, name)) != NULL) //在线用户
		{
			puts(mid->buf);
			sendmesg(msg, mid->type);
		}
		else if((mid = Searchusr(ppdb, connfd, -1, name)) != NULL) //离线用户
		{
			Insertmsg(ppdb, connfd, mid->next->type, msg);
			Delet_AllList(mid);
		}
		else    //无此用户
			send(connfd, "NO SUCH USER!\n", 20, 0);
	}
}




