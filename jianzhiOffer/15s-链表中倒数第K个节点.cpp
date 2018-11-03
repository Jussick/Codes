//C++ file
/***********************************************
#
#      Filename: 15-链表中倒数第K个节点.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 倒数从第一个开始数起
#        Create: 2018-11-01 14:21:25
#**********************************************/
#include<iostream>
#include "include/list.h"

using namespace std;

Link *findKthToTail(Link *pHead, unsigned int k)
{
	if (pHead == NULL || k < 1)
		return NULL;

	Link *first = pHead;
	Link *second = pHead;

	// 先把第一个指针指向第k-1个节点，再让两个指针一起后移直到第一个指针移动到结尾，此时的第二个指针指向的即使倒数第k个。
	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (first->p_next != NULL)  // 防止k大于链表长度
			first = first->p_next;
		else
			return NULL;
	}
	while (first->p_next != NULL)
	{
		second = second->p_next;
		first = first->p_next;
	}

	return second;
}

int main()
{
	int arr[5] = {1,2,3,4,5};
	Link *head = createALinklist(arr, 5);
	cout << "List is: ";
	traverseList(head);

	cout << "Input one number: ";
	int i;
	cin >> i; 
	Link *node = findKthToTail(head, i);
	cout << "Last " << i << " node is ";
	cout << node->m_value << endl;
	return 0;
}
