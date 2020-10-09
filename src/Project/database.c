#include <stdio.h>
#include <string.h>
#include "database.h"

#define N 256


static int serchcli(void *arg, int count, char **data, char **columns)
{
	
	LNode *head = (LNode *)arg;
	
	Insert_LinkList(head, ctoi(data[0]), data[1]);

	return 0;
}

static int serchmeg(void *arg, int count, char **data, char **columns)
{
	return 0;
}


int db_init(sqlite3 **ppdb)
{
	Createdb(ppdb); //创建数据库
	Createusr(*ppdb); //创建usr表，包含type, name, passwd
	Createmsg(*ppdb); //创建msg表，包含type，msg	
}

//创建一数据库
int Createdb(sqlite3 **ppdb)
{
	char sql[N];
	char *errmsg = NULL;

	int ret = sqlite3_open("chat.db", ppdb);
	if(ret != SQLITE_OK)
	{
		fprintf(stderr, "chat.db open failed %s",  sqlite3_errmsg(*ppdb));
		return -1;
	}

	return 0;
}

int Createusr(sqlite3 *ppdb)
{
	char *errmsg = NULL;
	char sql[N];
	
	sprintf(sql, "create table if not exists usr(type INTEGER primary key , name TEXT , passwd TEXT);");
	
	sqlite3_exec(ppdb, sql, NULL, NULL, &errmsg);
	if(NULL != errmsg){
		fprintf(stderr, "sql exec failed: %s\n", errmsg);
		sqlite3_free(errmsg);
		return -1;
	}
	
}

int Createmsg(sqlite3 *ppdb)
{
	char *errmsg = NULL;
	char sql[N];
	
	sprintf(sql, "create table if not exists msg(type int , msg  TEXT);");
	
	sqlite3_exec(ppdb, sql, NULL, NULL, &errmsg);
	if(NULL != errmsg){
		fprintf(stderr, "sql exec failed: %s\n", errmsg);
		sqlite3_free(errmsg);
		return -1;
	}
	
}

//像数据库 usr 表里插入字段数据
int Insertdb(sqlite3 *ppdb, int connfd, int type, char *name, char *passwd)
{
	char sql[N];
	char buf[256];

	if(Searchusr(ppdb, connfd, -1, name)->next != NULL);
	{
		send(connfd, "The user already exists\n", 20, 0);
		return 0;
	}
	sprintf(sql,"insert into  usr values ('%d', '%s','%s');", type, name, passwd);

	char *errmsg;

	int ret = sqlite3_exec(ppdb, sql, NULL, NULL, &errmsg);
	if(ret!=SQLITE_OK){
		sprintf(buf, "sqlite3_exec failed :%s\n",errmsg);
		send(connfd, buf, sizeof(buf), 0);
		sqlite3_free(errmsg);
		return -1;
	}
	return 0;
}
//像数据库 msg 表里插入字段数据
int Insertmsg(sqlite3 *ppdb, int connfd, int type, char *msg)
{
	char sql[N];
	char buf[256];

	sprintf(sql,"insert into  msg values ('%d', '%s');", type, msg);

	char *errmsg;

	int ret = sqlite3_exec(ppdb, sql, NULL, NULL, &errmsg);
	if(ret!=SQLITE_OK){
		sprintf(buf, "sqlite3_exec failed :%s\n",errmsg);
		send(connfd, buf, sizeof(buf), 0);
		sqlite3_free(errmsg);
		return -1;
	}
	return 0;
}

//删除表内指定内容
int Delmsg(sqlite3 *ppdb, int type )
{
	char sql[N];
	char *errmsg = NULL;
	sprintf(sql,"delete from msg where type = \"%d\";", type);

	int ret = sqlite3_exec(ppdb, sql, NULL, NULL, &errmsg);
	if(ret!=SQLITE_OK){
		printf("sqlite3_exec failed :%s\n",errmsg);
		sqlite3_free(errmsg);
		return -1;
	}
	return 0;
}
//核对客户详细信息：输出一个包含客户信息的链表头
LNode *Checkdb(sqlite3 *ppdb, int connfd, char *name, char *passwd)
{
	char sql[N];
	char *errmsg = NULL;
	

	LNode *head = CreatLinkList();
	sprintf(sql,"SELECT * FROM usr where name='%s' and passwd=%s", name, passwd);

	int ret = sqlite3_exec(ppdb, sql, serchcli, head, &errmsg);
	if(ret!=SQLITE_OK){
		printf("ret = %d\n",ret);
		fprintf(stderr, "sqlite3_exec failed :%s\n",errmsg);
		sqlite3_free(errmsg);
	}

	return head;	
}
//查询客户详细信息：输出一个包含客户信息的链表头
LNode *Searchusr(sqlite3 *ppdb, int connfd, int type, char *name)
{
	char sql[N];
	char *errmsg = NULL;
	

	LNode *head = CreatLinkList();
	sprintf(sql,"SELECT * FROM usr where name='%s'or type = %d", name, type);

	int ret = sqlite3_exec(ppdb, sql, serchcli, head, &errmsg);
	if(ret!=SQLITE_OK){
		printf("ret = %d\n",ret);
		fprintf(stderr, "sqlite3_exec failed :%s\n",errmsg);
		sqlite3_free(errmsg);
	}
	return head;	
}
//查询客户对应离线消息
int Searchmsg(sqlite3 *ppdb, int type)
{
	char sql[N];
	char *errmsg = NULL;
	int count = 0;
	sprintf(sql,"SELECT * FROM  msg where type = %d", type);

	int ret = sqlite3_exec(ppdb, sql, serchmeg, &count, &errmsg);
	if(ret!=SQLITE_OK){
		printf("sqlite3_exec failed :%s\n",errmsg);
		sqlite3_free(errmsg);
		return -1;
	}

	return count;	
}



