#include <stdio.h>
#include <stdbool.h>



typedef int SElemType; 

typedef struct 
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

bool Push(SqStack *S, SElemType e);
bool Pop(SqStack *S, SElemType *e);

int main()
{
	Sqstack s;
	pop()

	return 0;
}

//压栈操作：插入元素e为新的栈顶元素
bool Push(SqStack *S, SElemType e)
{
	if(S->top ==  MAXSIZE - 1) //栈满
	{
		return false;
	}


	S->top++;     //栈指针+1
	S->data[S->top] = e;  //将新插入的元素置于栈顶空间
	
	return true;
}

//出栈操作：若栈非空，则删除S的栈顶元素，用e返回其值，并返回TRUE;否则返回FALSE
bool Pop(SqStack *S, SElemType *e)
{
	if(S -> top == -1)
	{
		return false;
	}
	*e = S->data[S->top];   //将要删除的元素赋值给e
	S->top--;

	return true;
}
