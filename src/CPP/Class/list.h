#ifndef __LIST_H
#define __LIST_H
#include <stdbool.h>
	typedef int data_t;
	typedef struct node{
		data_t data;
		struct node *next;
	}pNode;

class linklist{
	public:
	pNode *InsertPos(pNode *head, int Pos, data_t num);//向指定位置插入数据
	pNode *createlinklist();    //创建链表
	bool is_empty(pNode *head); //判断链表是否为空
	void Traverse(pNode *head); //遍历输出链表
	int Countlist(pNode *head); //计算链表的结点
	pNode *DeleteNodePos(pNode *head, int Pos);    //指定位置删除结点
	pNode *DeleteNodevalue(pNode *head, int val);   //指定数据删除结点
	pNode *Clearlist(pNode *head);  //清空链表
	void destroylist(pNode **head); //删除链表
};


#endif
