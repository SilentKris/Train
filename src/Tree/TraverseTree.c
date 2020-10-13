#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lq.h"


tree *CreateTree(int n, int i);
void PreorderTraverse(tree *root);
void MidorderTraverse(tree *root);
void PostorderTraverse(tree *root);
void LevelOrder(tree *root);

int main(int argc, char **argv)
{
	tree *mytree = CreateTree(10, 1);

	PreorderTraverse(mytree);
	putchar('\n');
	MidorderTraverse(mytree);
	putchar('\n');
	PostorderTraverse(mytree);
	putchar('\n');
	LevelOrder(mytree);
	putchar('\n');

	return 0;
}

tree *CreateTree(int n, int i)
{
	tree *root = (tree *)malloc(sizeof(tree));
	root -> data = i;

	if(2*i <= n)
		root->lchild = CreateTree(n, 2*i);
	else
		root->lchild = NULL;
	if(2*i+1 <= n)
		root->rchild = CreateTree(n, 2*i+1);
	else
		root->rchild = NULL;
	
	return root;
}

//先序，中序，后序遍历就是遍历操作在递归中的位置不同所导致的
void PreorderTraverse(tree *root)
{
	if(NULL == root)
		return;
	printf("%-3d", root->data);
	PreorderTraverse(root->lchild);
	PreorderTraverse(root->rchild);
}
void MidorderTraverse(tree *root)
{
	if(NULL == root)
		return;
	MidorderTraverse(root->lchild);
	printf("%-3d", root->data);
	MidorderTraverse(root->rchild);
}
void PostorderTraverse(tree *root)
{
	if(NULL == root)
		return;
	PostorderTraverse(root->lchild);
	PostorderTraverse(root->rchild);
	printf("%-3d", root->data);
}

//层序遍历
//实现这一功能需要三个文件 lq.h  LinkQueue.c  TraverseTree.c
//分三步
//1、将根节点入队
//2、将根节点出栈
//3、判断根节点的lchild和rchild是否存在，若存在则出队
//4、反复执行2、3步骤，直至队列为空
//该代码使用链式队列实现
void LevelOrder(tree *root)
{
	LinkQueue LQ;

	LinkQueueInit(&LQ);
	if(root)
		EnQueue(&LQ, *root);
	while(LQ.front != LQ.rear)
	{
		DeQueue(&LQ, root);
		printf("%-3d", root->data);
		if(root->lchild)
			EnQueue(&LQ, *root->lchild);
		if(root->rchild)
			EnQueue(&LQ, *root->rchild);
	}
}
