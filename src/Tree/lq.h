#ifndef __LQ_H
#define __LQ_H

typedef struct tree{

	int data;
	struct tree *lchild, *rchild;
}tree;

typedef tree QElemtype;

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


#endif
