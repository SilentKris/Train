#ifndef __DATASTRUCT_H
#define __DATASTRUCT_H

#define SIZE 256

typedef struct node
{
	int type;
	char buf[SIZE];
	struct node *next;
}LNode;

LNode *CreatLinkList();//创建链表
void Trave_LinkList(LNode *head);//遍历整个链表（待用）
LNode *Loc_LinkList(LNode *head); //查找链表尾部

LNode *Search_LinkList(LNode *head, int target, char *name);
void Insert_LinkList(LNode *head, int type, char *name);//在尾部插入新的数据
int Delet_LinkList(LNode *head, int );//删除指定节点
int Lenth_LinkList(LNode *head);//计算链表节点数量
LNode *Get_LinkList(LNode *head, char *name);//查找信息返回目标结构体指针
int Delet_AllList(LNode *head);
int ctoi(char *buf);


#endif
