//C++ file
/***********************************************
#
#      Filename: 13-在O(1)时间删除链表节点.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 删除节点指针指向的链表节点。
				 分三种情况：
				 	1. 要删除的节点是中间节点：把后面节点值赋给要删除节点，删除后面节点；
					2. 要删除的节点是尾节点：由于没有后面节点，故要从头遍历到删除节点进行删除；
					3. 只有一个节点：把头指针赋为NULL.
				 注意：
				 	O(1)时间的前提条件是，要删除的节点在链表中，假设这个成立才能在O(1)时间内完成.
#        Create: 2018-10-30 14:09:05
#**********************************************/
#include<iostream>

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

/* 删除指针指向的链表节点 */
bool deleteOneNode(Link *head, Link *toBeDeleted)
{
	if (!head || !toBeDeleted)
		return false;
	// 链表只有一个节点
	if (head->p_next == NULL)
	{
		delete toBeDeleted;
		toBeDeleted = NULL;
		head = NULL;
	}
	// 要删除的节点是尾节点
	else if (toBeDeleted->p_next == NULL)
	{
		Link *cur_node = head;
		while (cur_node != NULL)
		{
			if (cur_node->p_next != toBeDeleted)
				cur_node = cur_node->p_next;
			else
			{
				cur_node ->p_next = NULL;
				delete toBeDeleted;
				toBeDeleted = NULL;
			}
		}
	}
	else
	{
		// 删除中间的节点
		toBeDeleted->m_value = toBeDeleted->p_next->m_value;
		toBeDeleted->p_next = toBeDeleted->p_next->p_next;
		delete toBeDeleted->p_next;
	}
	return true;
}

int main()
{
	int arr[] = {1,2,3,4,5};
	Link *head = createALinklist(arr, 5);
	Link *del_node = head;
	traverseList(head);
	for (int i = 0; i < 3; ++i)
	{
		del_node = del_node->p_next;	
	}
	deleteOneNode(head, del_node);
	traverseList(head);
	destoryALinklist(head);

	return 0;
}
