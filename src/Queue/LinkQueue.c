#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef int QElemtype;

typedef struct QueueNode{
	QElemtype data;
	struct QueueNode *next;
}QNode;


//front指向链式队列的头指针，所以队首应该是头指针指向的结点
typedef struct {
	QNode *front, *rear;
	int count;
}LinkQueue;

void Traverse(LinkQueue *Q);
bool EnQueue(LinkQueue *Q, QElemtype e);
bool DeQueue(LinkQueue *Q, QElemtype *e);
void LinkQueueInit(LinkQueue *Q);

int main(int argc, char **argv)
{
	int i = 0;
	int num, denum;
	srand((int)time(NULL));
	LinkQueue LQ;
	
	LinkQueueInit(&LQ);
	for(; i < MAXSIZE; i++)
	{
		num = rand()%100;
		EnQueue(&LQ, num);
	}

	Traverse(&LQ);
	DeQueue(&LQ, &denum);
	Traverse(&LQ);
	return 0;
}

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
		printf("The num %dst is %d\n", num, q->data);
		q = q->next;
	}
	printf("It has %d num in all\n", Q->count);
}
