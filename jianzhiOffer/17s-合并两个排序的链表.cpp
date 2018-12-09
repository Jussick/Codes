//C++ file
/***********************************************
#
#      Filename: 17-合并两个排序的链表.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-11-02 14:48:06
#**********************************************/
#include<iostream>
#include"include/list.h"
using namespace std;

Link *mergeTwoLists(Link *first, Link *second)
{
	Link *one = first;
	Link *two = second;
	Link *merged = NULL;
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
			for (; two != NULL; two = two->p_next)
				addOneNodeToTail(two->m_value, &merged);
			return merged;
		}
		else if (two == NULL)
		{
			for (; one != NULL; one = one->p_next)
				addOneNodeToTail(one->m_value, &merged);
			return merged;
		}
		if (one->m_value <= two->m_value)
		{
			cout << "add one: " << one->m_value << endl;
			addOneNodeToTail(one->m_value, &merged);
			one = one->p_next;
		}
		else
		{
			cout << "add two: " << two->m_value << endl;
			addOneNodeToTail(two->m_value, &merged);
			two = two->p_next;
		}
		
	}

	return merged;

}

int main()
{
	int arr1[] = {1,2,4};
	int arr2[] = {1,3,4};

	Link *list1 = createALinklist(arr1, 3);
	Link *list2 = createALinklist(arr2, 3);
	cout << "list1: ";
	traverseList(list1);
	cout << "list2: ";
	traverseList(list2);

	Link *head1 = list1;
	Link *head2 = list2;

	Link *merged = mergeTwoLists(list1, list2);;

	cout << "merged: ";
	traverseList(merged);	
	
	return 0;

}

