#include <cstdio>
#include <cstdlib>
#include "listHp.h"



pListNode
creatList(int memberNum)
{
	static pListNode list = nullptr;
	pListNode listNode1;
	pListNode listNode2;

	if (list != nullptr)
	{
		return list;
	}

	list = new listNode;
	list->next = nullptr;
	list->value = 0;

	listNode1 = listNode2 = list;

	for (int i = 1; i < memberNum; ++i)
	{
		listNode1 = new listNode;
		listNode1->value = i;
		listNode1->next = nullptr;

		listNode2->next = listNode1;
		listNode2 = listNode1;
	}

	return list;
}


int 
getListLen(pListNode list)
{
	int len = 0;
	while (list != nullptr)
	{
		list = list->next;
		len++;
	}

	return len;
}


void
RemoveNode(pListNode* pHead, int value)
{
	if (*pHead == nullptr || pHead == nullptr)
		return;

	pListNode pToBeDeleted = nullptr;

	if ((*pHead)->value == value)
	{
		pToBeDeleted = *pHead;
		*pHead = pToBeDeleted->next;
	}
	else
	{
		pListNode pCurNode = *pHead;
		
		while (pCurNode->next != nullptr && pCurNode->next->value != value)
			pCurNode = pCurNode->next;

		if (pCurNode->next != nullptr && pCurNode->next->value == value)
		{
			pToBeDeleted = pCurNode->next;
			pCurNode->next = pToBeDeleted->next;
			pToBeDeleted->next = nullptr;
		}
	}

	delete(pToBeDeleted);
	pToBeDeleted = nullptr;
}


pListNode 
findKth2Tail(pListNode list, int k) 
{
	if (k < 0 || k > getListLen(list))
	{
		printf("K value is not right!");
	}

	if (list == nullptr)
	{
		printf("List is null\n");
		getchar();
		return nullptr;
	}

	pListNode pAhead = list;
	pListNode pBehind = list;

	for (int i = 0; i < k - 1; ++i)
	{
		pAhead = pAhead->next;
	}

	while (pAhead->next != NULL)
	{
		pBehind = pBehind->next;
		pAhead = pAhead->next;
	}

	return pBehind;
}