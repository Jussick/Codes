#ifndef _LIST_H
#define _LIST_H
#include <iostream>
using namespace std;

#ifndef leetcode
typedef struct ListNode {
	int m_value;
	ListNode *p_next;
	ListNode(int x): m_value(x), p_next(NULL) { }
}Link;
#endif

//typedef struct ListNode Link;

/* 打印以head为头的链表节点信息 */
void traverseList(Link *head)
{
	if (head == NULL)
	{
		cout << "List is NULL!" << endl;
		return;
	}
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

/* 在链表结尾添加一个节点 */
bool addOneNodeToTail(int item, Link **head)  // **是为了要改变head指向的地址
{
	Link *cur = *head;
	Link *pnew = new Link(item);
	if (pnew == NULL)  // 内存申请失败
		return false;

	if (cur == NULL)  // 链表为空时
		*head = pnew;
	else
	{
		while (cur->p_next != NULL)
			cur = cur->p_next;
		cur->p_next = pnew;
	}
	return true;

}

/* 《链表拆分》
 * 把一个有偶数个节点的链表拆分出来以偶数节点组成的链表，原链表变为以奇数节点组成的链表 
 * 如,原链表为1-2-3-4-5-6
 * 那么拆分过后的原链表变为1-3-5
 * 返回的链表为2-4-6
 */
Link *departList(Link *head)
{
	if (head == NULL)
		return NULL;

	Link *cur_node = head;
	Link *clone_head = head->p_next;
	Link *clone_cur = clone_head;

	while (cur_node)
	{
		cur_node->p_next = clone_cur->p_next;
		if (cur_node->p_next == NULL)
		{
			clone_cur->p_next = NULL;
			break;
		}
		clone_cur->p_next = cur_node->p_next->p_next;
		cur_node = cur_node->p_next;
		clone_cur = clone_cur->p_next;
	}
	return clone_head;
}


#endif
