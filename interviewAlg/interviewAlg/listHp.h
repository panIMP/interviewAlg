#ifndef _LISTHP_H
#define _LISTHP_H

typedef struct _LIST_NODE
{
	int value;
	_LIST_NODE* next;
} listNode, *pListNode;


pListNode
creatList(int memberNum);

int
getListLen(pListNode list);

void 
RemoveNode(pListNode* pHead, int value);

pListNode
findKth2Tail(pListNode list, int k);

#endif
