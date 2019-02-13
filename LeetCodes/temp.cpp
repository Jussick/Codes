//C++ file
#include<iostream>
#include "../jianzhiOffer/include/list.h"
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;


template <class T> 
T swap(T *a, T *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

class Solution {
public:
    Link* removeNthFromEnd(Link* head, int n) {
		
		// 链表只有一个节点的情况
		if (head->p_next == NULL) {
			delete head;
			return NULL;
		}
		Link *first = head;
		Link *second = head;

		/*  找到倒数第n个节点 */

			// 把first指向第n-1个节点
		for (int i = 0; i < n - 1; ++i) {
			first = first->p_next;	
		}
			// 把second指向倒数第n个节点
		while (first->p_next != NULL) {
			second = second->p_next;
			first = first->p_next;
		}
		// 如果删除的是尾节点，则按照常规方式删除
		if (second->p_next == NULL) {
			// 	把cur指向链表倒数第二个节点
			Link *cur;
			for ( cur = head; cur->p_next->p_next != NULL; cur = cur->p_next);
			Link *deleteNode = cur->p_next;
			cur->p_next = cur->p_next->p_next;
			delete deleteNode;
		}
		else {
			second->m_value = second->p_next->m_value;
			Link *deleteNode = second->p_next;
			second->p_next = second->p_next->p_next;
			delete deleteNode;
		}
			
		return head;
    }
};
int main()
{
	Solution ss = Solution();
	int arr[2] = {1,2};
	Link *head = createALinklist(arr, 2);
	traverseList(head);
	ss.removeNthFromEnd(head, 1);
	traverseList(head);
	return 0;
}
