#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>



typedef int data_t;
typedef struct node{
	data_t data;
	struct node *next;
}pNode;


pNode *InsertPos(pNode *head, int Pos, data_t num);//向指定位置插入数据
pNode *createlinklist();	//创建链表
bool is_empty(pNode *head);	//判断链表是否为空
void Traverse(pNode *head);	//遍历输出链表
int Countlist(pNode *head);	//计算链表的结点
pNode *DeleteNode(pNode *head, int Pos);	//指定位置删除结点
pNode *DeleteNodevalue(pNode *head, int val);	//指定数据删除结点
pNode *Clearlist(pNode *head);	//清空链表
void destroylist(pNode **head);	//删除链表



int main(int argc, char **argv)
{
	int i, num;
	srand((int)time(NULL));

	pNode *head = createlinklist();
	for(i=1; i<=10; i++)
	{
		num  = rand()%10;
		InsertPos(head, i, num);

	}
	Traverse(head);
	printf("%d\n", num);
	DeleteNodevalue(head, num);
	Traverse(head);
	Clearlist(head);
	Traverse(head);
	destroylist(&head);
	Traverse(head);
	return 0;
}

pNode *createlinklist()
{
	pNode *pHead = (pNode *)malloc(sizeof(pNode));

	pHead->data = -1;
	pHead->next = NULL;

	return pHead;
}

bool is_empty(pNode *head)
{
	if(head->next == NULL)
		return true;
	else 
		return false;
}

void Traverse(pNode *head)
{
	int count = 0;
	if(NULL == head)
	{
		puts("list is not exist!\n");
		return ;
	}
	pNode *p = head->next;
	if(is_empty(head))
	{
		puts("list is empty!\n");
		return ;
	}
	
	while(p)
	{
		count++;
		printf("the %d data = %d\n", count, p->data);
		p = p->next;
	}
}

int Countlist(pNode *head)
{
	pNode *p = head->next;
	int count = 0;
	if(is_empty(head))
		return 0;
	
	while(p)
	{
		count++;
		p = p->next;
	}
	return count;

}

pNode *InsertPos(pNode *head, int Pos, data_t num)
{
	int count;
	pNode *p = head;
	pNode *q = head;
	if(NULL == head || Pos > (Countlist(head)+1) || Pos <= 0)
		return NULL;

	pNode *pNew = (pNode *)malloc(sizeof(pNode));
	
	for(count=0; count < Pos; count++)
	{
		q = p;
		p = p -> next;
	}

	q->next = pNew;
	pNew->next = p;
	pNew->data = num;

	return head;
}

//按位置删除
pNode *DeleteNodePos(pNode *head, int Pos)
{
	int i;
	pNode *p = head;
	pNode *q = head;
	if(is_empty(head) || Pos > Countlist(head) || Pos <= 0)
		return NULL;
	for(i=0; i<Pos; i++)
	{
		q = p;
		p = p->next;
	}

	q->next = p->next;
	free(p);
	
	return head;
}
pNode *Getlistvalue(pNode *head, int val)
{
	
}

pNode *DeleteNodevalue(pNode *head, int val)
{
	pNode *p = head;
	pNode *q = head;

	if(is_empty(head))
		return NULL;
	
	while(p)
	{
		if(p->data == val)
		{
			q->next = p->next;
			free(p);
			p = q;
		}
		q = p;
		p = p->next;
		
	}
	return NULL;
}

pNode *Clearlist(pNode *head)
{
	pNode *p = head->next;
	pNode *q;
	while(p)
	{
		q = p;
		free(q);
		p = p->next;
	}
	head->next = NULL;
	return head;
}

void destroylist(pNode **head)
{
	Clearlist(*head);
	free(*head);
	*head = NULL;
}
