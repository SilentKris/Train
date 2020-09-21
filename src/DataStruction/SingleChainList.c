#include <stdio.h>

#define ERROR 0
#define TURE 1


typedef int ElemType;
typedef int Status;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList;

int main()
{
	
	return 0;
}


/*【单链表的读取】操作结果：用e返回L中第i哥数据元素的值*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList P;
	p  = L -> next;
	j = 1;
	while(p && j<i)
	{
		p = p -> next;
		++j;
	}
	if( !p || j>i)
		return ERROR;
	*e = p -> data
}
