//C++ file
/***********************************************
#
#      Filename: 16反转链表.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-11-02 10:50:59
#**********************************************/
#include<iostream>
#include "include/list.h"

using namespace std;

ListNode *reverseList(ListNode *head)
{
	// first input check
	if (head == NULL)
		return NULL;

	ListNode *cur = head;  // 当前节点指针
	ListNode *next;		   // 下一个节点指针
	ListNode *pre = NULL;  // 前一个节点指针

	while (cur != NULL)
	{
		if (cur->next == NULL)  // 到了尾节点
		{
			cur->next = pre;
			break;
		}
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return cur;
}

int main()
{
	int arr[5] = {1,2,3,4,5};
	Link *head = createALinklist(arr, 5);
	cout << "before reverse:" << endl;
	traverseList(head);
	Link *rhead = reverseList(head);
	cout << "after reverse:" << endl;
	traverseList(rhead);

	return 0;
}
