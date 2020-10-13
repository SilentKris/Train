#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
typedef char data_t;

/*   Link 表示指向左右孩子指针
 * Thread 表示指向前驱或者后继的线索 
 * */
typedef enum {Link, Thread} PointTag;

typedef struct BiThrNode
{
	data_t data;
	struct BiThrNode *lchild, *rchild; //左右孩子指针
	PointTag LTag; //前驱线索
	PointTag RTag; //后继线索
}BiThrNode;

BiThrNode *pre; //始终指向刚刚访问过的结点

void InThreading(BiThrNode *p);
bool InOrderTraverse_thr(BiThrNode *T);
void CreateBinTree(BiThrNode **p);
BiThrNode *CreateBiThrTree(BiThrNode *p);
void Traverse(BiThrNode *p);

int main()
{
	BiThrNode  *root, *Head;

	CreateBinTree(&root);
	Head = CreateBiThrTree(root);
	InOrderTraverse_thr(Head);

	return 0;
}

void Traverse(BiThrNode *p)
{
	if(!p)
		return;
	printf("lchild=%p, LTag=%d, data=%d, RTag=%d, rchild=%p\n", p->lchild,p->LTag, p->data, p->RTag, p->rchild);
	Traverse(p->lchild);
	Traverse(p->rchild);
}
//先序创建二叉树
void CreateBinTree(BiThrNode **p)
{
	char ch;
	puts("Please input the data");
	scanf("%c", &ch);
	getchar();
	if('#' == ch)
		*p = NULL;
	else
	{
		*p = (BiThrNode *)malloc(sizeof(BiThrNode));
		if(!*p)
			exit(0);
		bzero(*p, sizeof(**p));
		(*p) -> data = ch;
		CreateBinTree(&(*p) -> lchild);
		CreateBinTree(&(*p) -> rchild);
	}

}
BiThrNode *CreateBiThrTree(BiThrNode *p)
{
	if(!p)
		return NULL;
	BiThrNode *head = (BiThrNode *)malloc(sizeof(BiThrNode));
	InThreading(p);
	head -> lchild = p;
	head -> LTag = Link;
	head -> rchild = pre;
	head ->RTag = Thread;
	if(pre->rchild == NULL)
	{
		pre->RTag = Thread;
		pre->rchild = head;
	}
	return head;
}
//利用中序遍历进行中序线索化
//该函数只能得到当前结点的前驱线索 和 前驱的后继线索,而当前结点的后继线索无法在当前访问中得出
void InThreading(BiThrNode *p)
{
	if(p) //如果结点为NULL，则该函数返回
	{
		/*******************************************************/
		InThreading(p->lchild); //递归左子树线索化

		if(!p->lchild);  //没有左孩子
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
		/********************************************************/
		InThreading(p->rchild); //递归右子树线索化
	}
}

//对二叉线索链表表示的二叉树进行中序遍历
//T指向头结点，头节点左链lchild指向根节点，头结点右链指向中序遍历的最后一个结点
//该函数整体上是从左往右中序遍历。
bool InOrderTraverse_thr(BiThrNode *T)
{
	BiThrNode *p;
	p = T->lchild;   //p指向根节点

	while(p != T)
	{

		while(p -> LTag == Link)  //找到一棵树的中序遍历的第一个结点
			p = p->lchild;
		
		printf("%c ", p->data);  //显示左子树结点数据，可以更改为其他对结点的操作

		//因为RTag是结点后继的标志位，该循环是寻找到非叶子结点的后继，期间遍历所有叶子结点，具体操作可以打印，也可以更换为其他的操作
		while(p->RTag == Thread && p->rchild != T)  
		{
			p = p->rchild;   
			printf("%c ", p->data);
		}
		p = p->rchild; // p进至右子树根
	}
	puts("");
	return true;
}

