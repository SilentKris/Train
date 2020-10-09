#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastruct.h"


//创建链表
LNode *CreatLinkList()
{
	LNode *head=(LNode *)malloc(sizeof(LNode));
	head->next=NULL;

	return head;
}
//遍历链表
void Trave_LinkList(LNode *head)
{
	LNode *p=head->next;
	while (p!=NULL) {
		printf("%d %s\n",p->type, p->buf);
		p=p->next;        //你要往循环终止的方向走 
	}	
	printf("\n");
}


//查找尾部位置
LNode *Loc_LinkList(LNode *head)
{
	LNode *ptail = head;

	while(ptail->next != NULL) 
	{
		ptail = ptail->next;
	}

	return ptail; 
}
//插入尾部数据
void Insert_LinkList(LNode *head, int type, char *name)
{
	LNode *ptail = Loc_LinkList(head);
	LNode *pNew;

	pNew = (LNode *)malloc(sizeof(LNode));//一定要为新节点分配空间 
	pNew->type = type;
	strcpy(pNew->buf, name);
	ptail->next = pNew;
	ptail = pNew;
	ptail->next = NULL;

}

//查找链表中type = target 或 buf == name的结点
LNode *Search_LinkList(LNode *head, int target, char *name)
{
	LNode *p = head->next;
	LNode *q = head;

	while(p)
	{	
		if(p->type == target || (strcmp(p->buf, name) == 0))
		{
			return p;
		}
		else if(p->next)
		{
			q = p;
			p = p->next;
		}
		else
		{
			break;
		}
	}

	return NULL;
}
//删除链表中type = target的结点
int Delet_LinkList(LNode *head, int target)
{
	LNode *p = head->next;
	LNode *q = head;
	while(p)
	{	
		if(p->type == target)
		{
			q->next = p->next;
			free(p);
			return 0;
		}
		if(p->next)
		{
			q = p;
			p = p->next;
		}
		else 
			break;
	}
	return -1;
}
//删除整个链表
int Delet_AllList(LNode *head)
{
	LNode *ptail = head;
	LNode *ptr;
	while(ptail != head)
	{
		while(ptail->next != NULL)
		{
			ptr = ptail;
			ptail = ptail->next;

		}
		ptr -> next = NULL;
		free(ptail);
		free(head);
	}
	free(ptail);
}

//计算链表节点数量
int Lenth_LinkList(LNode *head)
{
	int len=0;
	LNode *p=head->next;
	while (p!=NULL) {
		len++;
		p=p->next;
	}

	return len;
}

//查找值返回目标指针
LNode *Get_LinkList(LNode *head, char *name)
{
	LNode *p=head;
	LNode *q;

	while(p->next !=NULL) 
	{
		if (strcmp(p->buf, name) == 0)

			return p;
		else 
			p=p->next;
	}

	return NULL;
}

int ctoi(char *buf)
{
	int len, i,  sum;
	len = strlen(buf);
	sum = buf[0]-'0';
	for(i=1; i<len; i++)
	{
		sum = sum * 10 + (buf[i] - '0');
	}
	return sum;
}
