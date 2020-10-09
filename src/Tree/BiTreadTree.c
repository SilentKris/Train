#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

/*   Link 表示指向左右孩子指针
 * Thread 表示指向前驱或者后继的线索 
 * */
typedef enum {Link, Thread} PointTag;

typedef struct BiThrNode
{
	data_T data;
	struct BiThrNode *lchild, *rchild; //左右孩子指针
	PointTag LTag, RTag;//左右标志
}BiThrNode;

BiThrNode *pre; //始终指向刚刚访问过的结点

int main()
{
	

	return 0;
}
//利用中序遍历进行中序线索化
void InThreading(BiThrNode *p)
{
	if(p)
	{
		InThreading(p->lchild); //递归左子树线索化
		if(!p -> lchild);  //没有左孩子
		{
			p->LTag = Thread; //前驱线索
			p->lchild = pre;  //左孩子指针指向前驱
		}
		
		if(pre!=NULL && !pre->rchild)      //前驱没有右孩子
		{
			pre->RTag = Thread; //后继线索
			pre->rchild = p;    //前驱右孩子指针指向后继
		}

		pre = p;				//保持pre指向p的前驱
		InThreading(p->rchild); //递归右子树线索化
	}
}

//对二叉线索链表表示的二叉树进行中序遍历
//T指向头结点，头节点左链lchild指向根节点，头结点右链指向中序遍历的最后一个结点
bool InOrderTraverse_Thr(BiThrNode *T)
{
	BiThrNode *p;
	p = T->lchild;   //p指向根节点
	while(p != T)
	{
		while(p -> LTag == Link)  //找到一棵树的中序遍历的第一个结点
			p = p->lchild;
		
		printf("%c", p->data);  //显示左子树结点数据，可以更改为其他对结点的操作

		while(p->RTag == Thread && p->rchild != T)  //输出父结点数据
		{
			p = p->rchild;   
			printf("%c", p->data);
		}
		p = p->rchild; // p进至右子树根
	}

	return true;
}

