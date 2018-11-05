#ifndef _LIST_H
#define _LIST_H
#include <iostream>
using namespace std;

typedef struct ListNode {
	int m_value;
	ListNode *p_next;
	ListNode(int x): m_value(x), p_next(NULL) { }
}Link;

//typedef struct ListNode Link;

/* 打印以head为头的链表节点信息 */
void traverseList(Link *head)
{
	if (head == NULL)
		return;
	else
	{
		Link *cur_node = head;
		for (; cur_node != NULL; cur_node = cur_node->p_next)
			cout << cur_node->m_value << " ";
		cout << endl;
	}
}

/* 根据n个元素的数组arr创建一个链表，并返回链表头 */
Link *createALinklist(int arr[], int n)
{
	if (n <= 0)
		return NULL;
	Link *head = new Link(arr[0]);
	Link *cur_node = head;
	for (int i = 1; i < n; ++i)
	{
		cur_node->p_next = new Link(arr[i]);
		cur_node = cur_node->p_next;
	}
	return head;
}

/* 销毁以head为头的链表空间 */
void destoryALinklist(Link *head)
{
	if (head == NULL)
		return;
	Link *cur_node = head;
	while (cur_node != NULL)
	{
		Link *delNode = cur_node;
		cur_node = cur_node->p_next;  // 要注意删除前要先将当前节点指针指向下一个位置
		delete delNode;
	}
	return;
}

#endif
