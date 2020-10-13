#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"



pNode * linklist::createlinklist()
{
	pNode *pHead = (pNode *)malloc(sizeof(pNode));

	pHead->data = -1;
	pHead->next = NULL;

	return pHead;
}

bool linklist::is_empty(pNode *head)
{
	if(head->next == NULL)
		return true;
	else 
		return false;
}

void linklist::Traverse(pNode *head)
{
	int count = 0;
	if(NULL == head)
	{
		puts("list is not exist!\n");
		return ;
	}
	pNode *p = head->next;
	if(is_empty(head))
	{
		puts("list is empty!\n");
		return ;
	}
	
	while(p)
	{
		count++;
		printf("the %d data = %d\n", count, p->data);
		p = p->next;
	}
}

int linklist::Countlist(pNode *head)
{
	pNode *p = head->next;
	int count = 0;
	if(is_empty(head))
	{
		std::cout << "The list has no node!\n";
		return 0;
	}
	while(p)
	{
		count++;
		p = p->next;
	}
	std::cout << "list has "<< count << " nodes in total" << std::endl;
	return count;

}

pNode * linklist::InsertPos(pNode *head, int Pos, data_t num)
{
	int count;
	pNode *p = head;
	pNode *q = head;
	if(NULL == head || Pos > (Countlist(head)+1) || Pos <= 0)
		return NULL;

	pNode *pNew = (pNode *)malloc(sizeof(pNode));
	
	for(count=0; count < Pos; count++)
	{
		q = p;
		p = p -> next;
	}

	q->next = pNew;
	pNew->next = p;
	pNew->data = num;

	return head;
}

//按位置删除
pNode * linklist::DeleteNodePos(pNode *head, int Pos)
{
	int i;
	pNode *p = head;
	pNode *q = head;
	if(is_empty(head) || Pos > Countlist(head) || Pos <= 0)
		return NULL;
	for(i=0; i<Pos; i++)
	{
		q = p;
		p = p->next;
	}

	q->next = p->next;
	free(p);
	
	return head;
}

pNode *linklist::DeleteNodevalue(pNode *head, int val)
{
	pNode *p = head;
	pNode *q = head;

	if(is_empty(head))
		return NULL;
	
	while(p)
	{
		if(p->data == val)
		{
			q->next = p->next;
			free(p);
			p = q;
		}
		q = p;
		p = p->next;
		
	}
	return NULL;
}

pNode * linklist::Clearlist(pNode *head)
{
	pNode *p = head->next;
	pNode *q;
	while(p)
	{
		q = p;
		free(q);
		p = p->next;
	}
	head->next = NULL;
	return head;
}

void linklist::destroylist(pNode **head)
{
	Clearlist(*head);
	free(*head);
	*head = NULL;
}
