#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


typedef int data_t;

typedef struct list{
	data_t data;
	struct list*prior;
	struct list *next;
}pNode;

pNode *Insertvalue(pNode *head, int Pos, int val);//指定位置插入值
pNode *Creatdlist();	//创建链表
bool is_exist(pNode *head);  //判断链表是否存在
bool is_empty(pNode *head);		//判断链表是否为空
pNode *Traverse(pNode *head);	//遍历输出链表内容
int Getlengthlist(pNode *head);	//得到链表的长度（结点总数）
pNode *DeleteNodeValue(pNode *head, int val); //删除指定数据结点
pNode *DeleteList(pNode *head);		//清空链表
void Destroy(pNode **head);			//删除链表

int main(int argc, char **argv)
{
	srand(time(NULL));
	int i, num;

	pNode *head = Creatdlist();
	for(i=1; i<=10; i++)
	{
		num = rand()%10;
		Insertvalue(head, i, num);
	}
	Traverse(head);
	DeleteNodeValue(head, num);
	Traverse(head);
	DeleteList(head);
	Traverse(head);
	Destroy(&head);
	Traverse(head);

	return 0;
}

pNode *Creatdlist()
{
	pNode *head = (pNode *)malloc(sizeof(pNode));
	if(NULL == head)
	{
		fprintf(stderr, "Create failed!\n");
		return NULL;
	}
	head->prior = NULL;
	head->next = NULL;
	head->data = -1;
	
	return head;

}

bool is_exist(pNode *head)
{
	if(NULL != head)
		return true;
	else
	{
		fprintf(stderr, "list is not exist!\n");
	}
	 
}

bool is_empty(pNode *head)
{
	if(is_exist(head))
	{
		if(head->next == NULL)
		{
			fprintf(stderr, "list is empty!\n");
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;

}

pNode *Traverse(pNode *head)
{
	if(!is_exist(head))
	{
		return NULL;
	}
	if(is_empty(head))
	{
		return NULL;
	}
	
	int i=0;
	pNode *p = head->next;
	while(p)
	{
		i++;
		printf("the %d data is  %d\n", i, p->data);
		p = p->next;
	}
	return head;
}

int Getlengthlist(pNode *head)
{
	if(!is_exist(head))
	{
		return 0;
	}
	int count=0;
	pNode *p = head->next;
	while(p)
	{
		count++;
		p = p->next;
	}
	return count;
}

pNode *Insertvalue(pNode *head, int Pos, int val)
{
	int len = Getlengthlist(head);

	if(!is_exist(head))
	{
		return NULL;
	}
	if(Pos > (len+1))
	{
		fprintf(stderr, "Position is wrong!\n");
		return NULL;
	}
	int i=0;
	pNode *p = head;
	pNode *q;
	pNode *pNew = (pNode *)malloc(sizeof(pNode));
	if(NULL == pNew)
	{
		fprintf(stderr, "create failed!\n");
		return NULL;
	}

	while(i < Pos)
	{
		q = p;
		p = p->next;
		i++;
	}
	pNew->data = val;
	pNew->prior = q;
	pNew->next = p;
	q->next = pNew;
	if(p != NULL)
		p->prior = pNew;

	return head;
}

pNode *DeleteNodeValue(pNode *head, int val)
{
	if(!is_exist(head))
		return NULL;

	pNode *p = head->next;
	pNode *q = head;
	while(p)
	{
		if(p->data == val)
		{
			q->next = p->next;
			if(p->next != NULL)
				p->next->prior = q;
			free(p);
			p = q;    
		}
		q = p;
		p = p->next;
	}
	return NULL;
		
}

pNode *DeleteList(pNode *head)
{
	if(!is_exist(head))
		return NULL;
		
	pNode *p = head->next;
	pNode *q;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->next = NULL;
	return head;
}

void Destroy(pNode **head)
{
	free(DeleteList(*head));
	*head = NULL;
}
