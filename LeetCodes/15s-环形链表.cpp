//C++ file
/***********************************************
#
#      Filename: 15-环形链表.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 给定一个链表，判断链表中是否有环, 并找到环的入口节点。
				进阶：
				你能否不使用额外空间解决此题？ 
				
				判断是否是环形链表这里用到了map这个STL，类似哈希值的用法，即把map的key设置成链表节点指针，value设置成int，默认初值是0，这很重要，否则要先循环赋初值；
				然后循环遍历链表，把每个节点指针对应的int值赋成1，如果是循环链表，就会有重复，实在是妙啊！
				正常的思路是用快慢指针(fast/slow)，都指向链表头，慢的一次移动一步，快的一次移动两步，如果两者能相遇，说明是环形链表。

				找到入口处稍微麻烦一点，要先找到fast和slow指针相遇节点meetnode，之后meetnode和头节点一起走再相遇的节点即是环的入口。
#        Create: 2018-11-07 16:36:07
#**********************************************/
#include<iostream>
#include<map>
#include"../jianzhiOffer/include/list.h"

using namespace std;

class Solution {
public:
    bool hasCycle(Link *head) {
		if (head == NULL)
			return false;

		Link *cur = head;

		map<Link *, int> mm;
		while (cur)
		{
			if (mm[cur] == 0)  // default value of map's int type value is 0
				mm[cur] = 1;
			else
				return true;
			cur = cur->p_next;
		}
		return false;
    }

    // 找到快慢指针的相遇节点
	Link *findSlowAndFastMeetNode(Link *head) {
		Link *slow = head;
		Link *fast = head;

		while (fast != NULL)
		{
			slow = slow->p_next;
			fast = fast->p_next->p_next;

			if (slow == fast)
				return slow;
		}
		return NULL;
	}

	// 找到环的入口节点
	Link *findCycleEntryNode(Link *head, Link *meetNode) {
		if (meetNode == head)
			return meetNode;
		Link *cur = head;
		while (1)
		{
			cur = cur->p_next;
			meetNode = meetNode->p_next;
			if (cur == meetNode)
				return cur;
		}
	}

};




int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	Link *list1= createALinklist(arr, 7);

	Link *cur = list1;  // make list1 a cycle linklist.
	while (cur->p_next)
		cur = cur->p_next;	
	cur->p_next = list1->p_next;

	Solution s;
	bool isCycleLinkList = s.hasCycle(list1);

	if (isCycleLinkList)
	{
		cout << "It's a cycle linklist." << endl;
		Link *meetNode = s.findSlowAndFastMeetNode(list1);
		Link *enrtyNode = s.findCycleEntryNode(list1, meetNode);
		cout << "entry node is " << enrtyNode->m_value << endl;
	}
	else
		cout << "It's not a cycle linklist." << endl;
		


	return 0;
}
