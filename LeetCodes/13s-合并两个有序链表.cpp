//C++ file
/***********************************************
#
#      Filename: 13-合并两个有序链表.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

				示例：

				输入：1->2->4, 1->3->4
				输出：1->1->2->3->4->4
#        Create: 2018-11-07 14:55:02
#**********************************************/
#include<iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/* 在链表结尾添加一个节点 */
bool addOneNodeToTail(int item, ListNode **head)  // **是为了要改变head指向的地址
{
	ListNode *cur = *head;
	ListNode *pnew = new ListNode(item);
	if (pnew == NULL)  // 内存申请失败
		return false;

	if (cur == NULL)  // 链表为空时
		*head = pnew;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = pnew;
	}
	return true;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *one = l1;
		ListNode *two = l2;
		ListNode *merged = NULL;
		// 鲁棒性处理
		if (one == NULL && two != NULL)
			return two;
		if (two == NULL && one != NULL)
			return one;
		if (one == NULL && two == NULL)
			return NULL;

		while (one != NULL || two != NULL)
		{
			if (one == NULL)
			{
				for (; two != NULL; two = two->next)
					addOneNodeToTail(two->val, &merged);
				return merged;
			}
			else if (two == NULL)
			{
				for (; one != NULL; one = one->next)
					addOneNodeToTail(one->val, &merged);
				return merged;
			}
			if (one->val <= two->val)
			{
				cout << "add one: " << one->val << endl;
				addOneNodeToTail(one->val, &merged);
				one = one->next;
			}
			else
			{
				cout << "add two: " << two->val << endl;
				addOneNodeToTail(two->val, &merged);
				two = two->next;
			}
			
		}

		return merged;
    }
};
