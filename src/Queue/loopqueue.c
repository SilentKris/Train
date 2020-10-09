#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 11

typedef int QElemType;

typedef struct {
	QElemType data[MAXSIZE]; //队列本身
	int front;		//头指针
	int rear;		//尾指针
}SqQueue;


bool Queueinit(SqQueue *Q);
int QueueLength(SqQueue *Q);
bool EnQueue(SqQueue *Q, QElemType e);
bool DeQueue(SqQueue *Q, QElemType *e);
void Traverse(SqQueue *Q);

int main(int argc, char **argv)
{
	int i = 0;
	int denum;
	QElemType num;
	srand((int)time(NULL));
	SqQueue Que;
	
	Queueinit(&Que);

	//此处有问题：循环队列应该有一个front前一个位置不能存储元素，是判满的标志位，所以满队列应该是（MAXSIZE-1）
	for(; i < MAXSIZE; i++)
	{
		num = rand()%100;
		EnQueue(&Que, num);
	}
	
	num = QueueLength(&Que);

	printf("the length is %d\n", num);
	Traverse(&Que);
	DeQueue(&Que, &denum);
	Traverse(&Que);
	DeQueue(&Que, &denum);
	Traverse(&Que);

	return 0;
}


//初始化队列
bool Queueinit(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	
	return true;
}

//求队列长度
int QueueLength(SqQueue *Q)
{
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

//入队
bool EnQueue(SqQueue *Q, QElemType e)
{
	if((Q->rear+1) %MAXSIZE == Q->front)
		return false;
	Q->data[Q->rear] = e;  //将待插入的元素
	Q->rear = (Q->rear+1) % MAXSIZE; //将尾指针后移一个单位 

	return true;
}

bool DeQueue(SqQueue *Q, QElemType *e)
{
	if(Q->rear == Q->front)
		return false;
	*e = Q->data[Q->front];
	Q->front = (Q->front+1) % MAXSIZE;
	
	printf("The delete num is %d\n", *e);
	return true;
}	

void Traverse(SqQueue *Q)
{
	int i = Q->front;
	int num = 1;
	while(i != Q->rear)
	{
		
		printf("The num %dst is %d\n", num, Q->data[i]);
		num++;
		i = (i+1)%MAXSIZE;
	}
}
