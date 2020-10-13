#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lq.h"


void LinkQueueInit(LinkQueue *Q)
{
	QNode *head = (QNode *)malloc(sizeof(QNode));
	Q->front = Q->rear = head;
	Q->count = 0;
}
//队列插入操作（针对队尾）
bool EnQueue(LinkQueue *Q, QElemtype e)
{
	QNode *pNew = (QNode *)malloc(sizeof(QNode));
	if(NULL == pNew)
	{
		return false;
	}
	pNew -> data = e;
	Q->rear->next = pNew;
	pNew->next = NULL;
	Q->rear = pNew;
	Q->count++;

	return true;
}

//从队首删除元素
bool DeQueue(LinkQueue *Q, QElemtype *e)
{
	if(Q->front == Q->rear)  //判满
	{
		return false;
	}
	QNode *p = Q->front->next; //删除头指针指向的队首
	*e = p->data;				//将队首的元素取出
	Q->front->next = p->next;  //将front指针指向新的队首

	//一般以为到这里就结束了，其实还有个判断，就是判断free掉的是不是队尾指针，如果是将队尾指向头结点
	if(Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	Q->count--;
	
	return true;
}

void Traverse(LinkQueue *Q)
{
	QNode *q = Q->front->next;
	int num = 0;
	while(q)
	{
		num++;
		printf("The num %dst is %d\n", num, q->data.data);
		q = q->next;
	}
	printf("It has %d num in all\n", Q->count);
}
