//C++ file
/***********************************************
#
#      Filename: 14-删除排序链表中的重复元素.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

			示例 1:

			输入: 1->1->2
			输出: 1->2
			示例 2:

			输入: 1->1->2->3->3
			输出: 1->2->3
#        Create: 2018-11-07 15:14:39
#**********************************************/
#include<iostream>
#include<set>
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
    ListNode* deleteDuplicates(ListNode* head) {
		set<int> ss;
		ListNode *cur = head;
		while (cur!= NULL)  // insert linklist into a set in order to remove duplicated element.
		{
			ss.insert(cur->val);
			cur = cur->next;	
		}
		ListNode *result = NULL;
		for (auto pd = ss.begin(); pd != ss.end(); ++pd)
			addOneNodeToTail(*pd, &result);			

		return result;
    }
};
