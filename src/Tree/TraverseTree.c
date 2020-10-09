#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	
	int data;
	struct tree *lchild, *rchild;
}tree;

tree *CreateTree(int n, int i);
void PreorderTraverse(tree *root);
void MidorderTraverse(tree *root);
void PostorderTraverse(tree *root);


int main(int argc, char **argv)
{
	tree *mytree = CreateTree(10, 1);

	PreorderTraverse(mytree);
	putchar('\n');
	MidorderTraverse(mytree);
	putchar('\n');
	PostorderTraverse(mytree);
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


