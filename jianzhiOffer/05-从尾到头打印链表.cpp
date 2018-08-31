//C++ file
/***********************************************
#
#      Filename: 05-从尾到头打印链表.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 从头到尾打印链表很简单，从尾到头只需要把链表中元素从头到尾插入栈中，在分别pop出来即可。
#        Create: 2018-08-28 14:16:31
#**********************************************/
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
#include <iterator>


using namespace std;


int main()
{
	int arr[5] = {1,2,3,4,5};
	list<int> ls1;
	stack<int> st1;
	ls1.insert(ls1.begin(), arr, arr + 5);
	for (auto pd = ls1.begin(); pd != ls1.end(); pd++)
		st1.push(*pd);
	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
}

