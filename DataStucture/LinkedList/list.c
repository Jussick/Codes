#include<stdio.h>                                                                                                        
#include<stdlib.h>                                                                                                
#include<string.h>
#include<stdbool.h>
#include"list.h"

void InitailizeList(List *plist)
{
	*plist = NULL;
}

bool ListIsEmpty(const List *plist)
{
	if(*plist == NULL)
		return true;
	else
		return false;
}

unsigned int ListItemCount(List *plist)
{	
	unsigned int count = 0;
	Node *node = *plist;
	while (node != NULL)
	{
		++count;
		node = node->next;
	}
	return count;
}

bool AddItem(Item item, List *plist)
{
	Node *scan = *plist;
	Node *pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false; // 内存申请失败后返回
	pnew->item = item;
	pnew->next = NULL;

	if(scan == NULL)
	{
		*plist = pnew;
	}
	else
	{	
		while(scan->next != NULL)
		{
			scan = scan->next;
		}
		scan->next = pnew;
	}

	return true;
}

void EmptyTheList(List *plist)
{
	Node *pnode = *plist; // 定义新指针的作用是，原则上当plist释放后会不可用。
	while (*plist != NULL)
	{
		pnode = pnode->next;
		free(*plist);
		*plist = pnode;
	}
}

void Traverse(const List *plist, void(*pfun)(Item item))
{
	Node *pnode = *plist;	
	while(pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}
