#include <stdio.h>


typedef struct Node{
	int data;
	struct Node *next;
}linklist;

int main(int argc, char **argv)
{
	int a[] = {1, 23, 12, 224, 453, 345, 34, 45, 45};
	int len = sizeof(a) / sizeof(int);


	return 0;
}
int HashConvert(int key)
{
	int size = 20;
	return (key % 20);
}
int HashSearch(linklist **Hp, int pos)
{
	if()
	

}
//将key中的所有值添加到Hash表中
//用保留除数法构建哈希函数
int InsertHash(int *p, linklist **HashList, int size)
{
	if(NULL == p || NULL == HashList)
		return -1;
	if(len < 0 || size <= 0)
		return -1;
	int i = 0;
	for(i=0; i<len; i++)
	{
		//准备结点
		linklist *pNew = (linklist *)malloc(sizeof(linklist));
		if(NULL == pNew)
		{
			printf("Create failed!\n");
			return -1;
		}
		pNew->data  = p[i];
		//根据H(key) = key % size，找到pNew结点的位置
		int pos = p[i] % size;

		//将p[i]添加到pos位置
		if(HashList[pos] == NULL) //
			HashList[pos] = pNew;
		else //如果pos位置有结点，用链地址法解决冲突
		{
			pNew -> next = HashList[pos];
			HashList[pos] = pNew;
		}
	}
	return 0;
}
