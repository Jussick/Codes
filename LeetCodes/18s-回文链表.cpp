//C++ file
/***********************************************
#
#      Filename: 18-回文链表.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-11-16 14:51:38
#**********************************************/
#include<iostream>
#include "../jianzhiOffer/include/list.h"
#include <string>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(Link* head) {
		if (head == NULL)
			return true;

		std::vector<int> vec;
		Link *cur = head;
		while (cur)
		{
			vec.push_back(cur->m_value);
			cur = cur->p_next;
		}
			
		int len = vec.size();
		bool equal = true;

		int mid = len / 2;
		for (int i = 0; i <= mid; ++i)
		{
			if (vec[i] != vec[len - i - 1])
				equal = false;
		}
		return equal;
    }
};

int main()
{
	int arr[5] = {1,2,3,2,2};
	Link *link1 = createALinklist(arr, 5);
	traverseList(link1);
	Solution s;
	if (s.isPalindrome(link1))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
