//C++ file
/***********************************************
#
#      Filename: 16-相交链表.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 
				编写一个程序，找到两个单链表相交的起始节点。

				例如，下面的两个链表：

				A:          a1 → a2
								   ↘
									 c1 → c2 → c3
								   ↗            
				B:     b1 → b2 → b3
				在节点 c1 开始相交。

				 

				注意：

				如果两个链表没有交点，返回 null.
				在返回结果后，两个链表仍须保持原有的结构。
				可假定整个链表结构中没有循环。
				程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

				测试用例：
					* 两个链表都只有一个节点
					* 两个链表有多个节点
					* 两个链表中有为空的或都为空

#        Create: 2018-11-09 14:45:44
#**********************************************/
#include<iostream>
#include<stack>
#include"../jianzhiOffer/include/list.h"

using namespace std;

class Solution {
	private:
		void showStack(stack<Link *> ss) {
			stack<Link *> ss_tmp = ss;
			while (!ss_tmp.empty())
			{
				cout << ss_tmp.top() << " ";
				ss_tmp.pop();
			}
			cout << endl;
		}
public:
    Link *getIntersectionNode(Link *headA, Link *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;

		Link *curA = headA;
		Link *curB = headB;
		int alen = 0, blen = 0;
		
		// 分别找到A和B的尾节点
		while (curA->p_next != NULL)
		{
			curA = curA->p_next;
			alen++;
		}
		Link *tailA = curA;
		while (curB->p_next != NULL)
		{
			curB = curB->p_next;
			blen++;
		}
		Link *tailB = curB;

		// 判断是否相交
		if (tailA != tailB)
			return NULL;
		else
		{
			cout << "They are intersected!" << endl;
			// 寻找相交节点, 把节点全部压栈，然后弹出至第一个不同的节点，该节点的next就是相交节点。
			stack<Link *> ssA;
			stack<Link *> ssB;
			curA = headA;
			curB = headB;
			while (curA->p_next)
			{
				ssA.push(curA);
				curA = curA->p_next;
			}
			ssA.push(curA);
			while (curB->p_next)
			{
				ssB.push(curB);
				curB = curB->p_next;
			}
			ssB.push(curB);
			showStack(ssA);
			showStack(ssB);
			int len = alen>=blen ? blen:alen;  // 长度短的那一个

			Link *aval, *bval;
			for (int i = len; i >= 0; --i)
			{
				aval = ssA.top();
				bval = ssB.top();

				if (aval != bval)
					return aval->p_next;
				else
				{
					ssA.pop();
					ssB.pop();
					if (ssA.empty())
					{
						cout << "ssA is empty." << endl;
						return aval;
					}
					if (ssB.empty())
					{
						cout << "ssB is empty." << endl;
						return bval;
					}
				}
			}
		}
	}
			
};


int main()
{
	int arr1[] = {1,2,3};
	int arr2[] = {4,5};
	int arr3[] = {6,7};

	Link *one = createALinklist(arr1, 3);	
	Link *two = createALinklist(arr2, 2);	
	Link *intersector = createALinklist(arr3, 2);	

	Link *curOne = one;
	Link *curTwo = two;
	while (curOne->p_next || curTwo->p_next)
	{
		if (curOne->p_next)
			curOne = curOne->p_next;
		if (curTwo->p_next)
			curTwo = curTwo->p_next;
	}

	curOne->p_next = intersector;
	curTwo->p_next = intersector;

	Solution s;
	Link *interNode = s.getIntersectionNode(one, two);
	cout << "intersected node is " << interNode->m_value << endl;

	return 0;
}
