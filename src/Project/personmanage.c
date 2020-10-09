#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "database.h"
#include "datastruct.h"
#include "personmanage.h"





//登录函数
int  Login(sqlite3 *ppdb, int connfd, LNode *head)
{
	char name[11], passwd[11], buf[N];
	char *ptr = NULL; //辅助用户输入密码
	int count;
	LNode *id = NULL; //用来查看用户的id信息

	Emptywithzero(3,  name, 11, passwd, 11, buf, N);


	send(connfd, "Please input your acount:", N, 0);
	recv(connfd, buf, sizeof(buf), 0);
	if(0 == strspn("#", buf))
	{
		send(connfd, "WRONG FORMAT. PLEASE REPEAT!!!\n", 50, 0);
		return 1;
	}

	ptr = strstr(buf, "#");
	*ptr = '\0';
	strncpy(name, buf, 10);
	strncpy(passwd, ptr+1, 10);
	
	id = Checkdb(ppdb, connfd, name, passwd);
	if(id->next != NULL)
	{
#if 0
		if(Search_LinkList(head, id->next->type, NULL) != NULL)
		{
			
			send(connfd, "This account is already logged in, please do not log in repeatedly\n", 100, 0);
			close(connfd);
		}
#endif
		send(connfd, "Welcome!\n", 15, 0);
		
		Insert_LinkList(head, id->next->type, id->next->buf);
		
		Delet_AllList(id);

		return 0;
	}
	else
	{
		send(connfd, "Your identity information does not exist, Please Regist!\n", N, 0);
		return 2;
	}

}
//注册函数
int Regist(sqlite3 *ppdb, int connfd)
{
	char name[11], passwd[11], buf[N];
	char *ptr = NULL;
	int count, type;
	srand(time(NULL));
	type = rand()%1000;

	Emptywithzero(3, name, 11, passwd, 11, buf, N);

 send(connfd, "Please input your name and password within ten words in this form: name#password!\n", N, 0);	
	recv(connfd, buf, sizeof(buf), 0);

	ptr = strstr(buf, "#");
	*ptr = '\0';
	strncpy(name, buf, 10);
	send(connfd, name, strlen(name), 0);
	strncpy(passwd, ptr+1, 10);
	send(connfd, passwd, strlen(passwd), 0);
	
	if( Insertdb(ppdb, connfd, type, name, passwd) == -1)
	{	
		send(connfd, "Create failed\n", 20, 0);
	}

	sprintf(buf, "Regist comlete!Your ID is %d\n, Please remember!!!", type );
	send(connfd, buf, strlen(buf), 0);
}



//将传入的数组全部清零
void Emptywithzero(int n_values, ...)
{
	va_list ap;
	char *ptr = NULL;
	size_t size;
	va_start(ap, n_values);

	int i;
	for(i=0; i<n_values; i++)
	{
		ptr = va_arg(ap, char *);
		size = va_arg(ap, int);
		bzero(ptr, size);
	}
	va_end(ap);

}





