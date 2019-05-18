//C++ file
/***********************************************
#
#      Filename: 09-listTest.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-17 14:57:08
#**********************************************/
#include<iostream>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;

template <class T>
void output(T n) { cout << n << " "; }

template <class T>
void showlist(const list<T> &ls) {
	for_each(ls.begin(), ls.end(), output<T>);
	cout << endl << endl;
}

int main()
{
	list<int> one(5,2);  // init list one contain five 2 number
	int array[5] = {1,2,3,4,5};
	list<int> two;
	two.insert(two.begin(), array, array+5);  // insert into head of list two with array
	int more[6] = {4,5,6,7,8,9};
	list<int> three(two);
	three.insert(three.end(), more, more + 6);  // insert into end of list three with more


	list<int> four;
	four.insert(four.begin(), one.begin(), one.end());  // 插入操作不会清空list one中的内容
	//showlist(four);

	cout << "List one:" << endl;
	showlist(one);
	cout << "List two:" << endl;
	showlist(two);
	cout << "List three:" << endl;
	showlist(three);

	cout << "Remove all element 2 from list three:" << endl;
	three.remove(2);
	showlist(three);

	cout << "list one: before splice" << endl;
	showlist(one);

	cout << "After splice one into three:" << endl;
	three.splice(three.begin(), one);  // 把list one转移到list three的开头, splice操作会清空list one中的内容。
	showlist(three);

	cout << "list one: after splice" << endl;
	showlist(one);

	cout << "After unique three:" << endl;
	three.unique();
	showlist(three);

	cout << "After sort three:" << endl;
	three.sort();
	showlist(three);

	cout << "Three merge with two:" << endl;
	three.merge(two);  // 在已经进行排序后的list，在与其他list进行merge时也会是排好序的
	showlist(three);

	for (auto pd = three.rbegin(); pd != three.rend(); pd++)
		cout << *pd << " ";
	cout << endl;

	return 0;
}
