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

Link *mergeTwoLists(Link *one, Link *two)
{
	// 鲁棒性处理
	if (one == NULL && two != NULL)
		return two;
	if (two == NULL && one != NULL)
		return one;
	if (one == NULL && two == NULL)
		return NULL;

	Link *merged;

}
