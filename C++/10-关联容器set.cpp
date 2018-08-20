//C++ file
/***********************************************
#
#      Filename: 10-关联容器set.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 集合的使用
#        Create: 2018-08-20 10:18:16
#**********************************************/
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

// 用输出流迭代器输出集合(从小到大)
template <class T>
void showset(set<T> &s)
{
	// 创建输出流迭代器
	ostream_iterator<int, char> out_iter(cout, " ");
	// 把set s的内容拷贝到输出流, 即输出
	copy(s.begin(), s.end(), out_iter);
	cout << endl;
}

// 正常遍历集合的方法(从小到大), 用哪个都可以
template <class T>
void showset2(set<T> &s)
{
	auto pd = s.begin();
	for(; pd != s.end(); pd++)	
		cout << *pd << " ";
	cout << endl;
}

// 用反向迭代器输出集合(从大到小)
template <class T>
void reverse_showset(set<T> &s)
{
	auto pd = s.rbegin();
	for(; pd != s.rend(); pd++)	
		cout << *pd << " ";
	cout << endl;
}



// 集合的使用
int main()
{
	int arr1[5] = {1,3,2,4,6};
	int arr2[5] = {3,3,4,4,5};

	set<int> A(arr1, arr1 + 5);  // 定义set时就会去重，并从小到大排序 
	set<int> B(arr2, arr2 + 5);
	set<int> C;

	// 输出A和B的信息
	cout << "Set A: ";
	showset2(A);
	cout << "Set B: ";
	showset2(B);

	// 求A和B的并集，并将结果放到集合C中
   	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<int> > (C, C.begin()) );
	cout << "A and B's union C: ";
	showset(C);
	cout << "reverse C: ";
	reverse_showset(C);
	
	// 求A和B的交集，并直接输出	
	cout << "A and B's intersection: ";
	ostream_iterator<int> out_iter(cout, " ");
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out_iter);
	cout << endl;

	// 输出集合中大于等于3的所有元素
	for(auto pd1 = A.lower_bound(3); pd1 != A.end(); pd1++) cout << *pd1 << " ";
	cout << endl;

	return 0;
}
