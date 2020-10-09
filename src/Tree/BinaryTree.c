#include <stdio.h>
#include <stdlib.h>

typedef char data_t;

typedef struct BiTNode{
	data_t data;
	struct BiTNode *lchild, *rchild;
}BiTNode;


int main()
{
	return 0;
}
/*按前序递归输入二叉树中结点的值
 * #表示空树，构造二叉树链表表示二叉树T
 *
*/
void CreateBinTree(BiTNode *T)
{
	data_t ch;
	scanf("%c", &ch);
	if(ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTNode *)malloc(sizoef(BiTNode));
		if(!*T)
		{
			exit(0);
		}
		(*T)->data = ch;
		CreateBinTree(&(*T) -> lchild);  //构造左子树
		CreateBinTree(&(*T) -> rchild);  //构造右子树
	}
}
