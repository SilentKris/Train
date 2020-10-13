#include <iostream>
#include "list.h"


int main()
{
	linklist L;

	pNode *head = L.createlinklist();
	L.Countlist(head);
	L.InsertPos(head, 1, 12);
	L.Countlist(head);
	L.Traverse(head);

	return 0;
}
