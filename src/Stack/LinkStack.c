#include <stdio.h>

typedef int SElemType;

//用链表来存储栈协议
typedef struct StackNode{

	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackptr;

//链栈结构体存储的是栈的信息（栈顶及栈结点数）
typedef struct LinkStack
{
	LinkStackptr top;
	int count;
}LinkStack;


int main(int argc, char **argv)
{



	return 0;
}

bool Push(LinkStack *S, SElemType e)
{
	LinkStackptr pNew = (LinkStackptr)malloc(sizeof(StackNode));//创建一个新的结点
	pNew->next = S->top; //将当前的栈顶作为新结点的后继
	pNew->data = e;  //
	S->top = pNew;   //将新创建的栈结点作为栈顶
	S->count++;      //记录push后栈的结点数

	return true;
}

//*e 用来接收要从栈中（POP）的数
bool Pop(LinkStack *S, SElemType *e)
{

	//先要执行判空操作


	LinkStackptr ptop = S->top->next; //找到栈顶的后继地址记录下来
	*e = S->top->data;				//将栈顶数据pop给 e
	free(S->top);					//释放栈顶空间
	S->top = ptop;					//将当前栈顶的后继作为新的栈顶
	S->count--;						//栈容量-1

	return true;
}
