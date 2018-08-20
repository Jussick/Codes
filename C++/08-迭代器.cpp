//C++ file
/***********************************************
#
#      Filename: 08-迭代器.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-16 11:14:42
#**********************************************/
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include <iterator>
using namespace std;

// 输出流迭代器
void out_iterTest()
{
    int a[10] = {1,2,3,4,5,6,7};
    vector<int> intvec(7);
    copy(a, a+7, intvec.begin());  // 把数组a复制到vector中
    // 创建一个输出流迭代器
    ostream_iterator<int, char> out_iter(cout, " ");
    // 把intvec拷贝到输出流迭代器， 相当于输出！
    copy(intvec.begin(), intvec.end(), out_iter);
    cout << endl;
}

int test()
{
	// 定义一个vector对象intvec
	vector<long int> intvec(10);
	cout << "size: " << intvec.size() << endl;
	// 给vector对象赋值
	for (size_t i = 0; i < intvec.size(); i++) intvec[i] = i;

	// 定义一个vector类型的迭代器指针，指向incvec
	vector<long int>::iterator pd = intvec.begin();
	// C11支持自动识别迭代器类型, 编译时要加上-std=c++11
	auto pd2 = intvec.begin();

	for (; pd != intvec.end(); pd++)
		cout << *pd << " ";
	cout << endl;

	for (; pd2 != intvec.end(); pd2++)
		cout << *pd2 << " ";
	cout << endl;

	return 0;
}

void show(int n)
{
	cout << n << " ";
}

bool lessthan(int a, int b)
{
	if (a < b) return false;
	else return true;
}

int main1()
{
	vector<int> intset;
	//for (int i = 0; i < 5; i++)
	//	intset.push_back(i);
	intset.push_back(4);
	intset.push_back(3);
	intset.push_back(2);
	intset.push_back(1);
	cout << "size of intset: " << intset.size() << endl;
	auto iter = intset.begin();

	// 循环迭代器遍历输出intset
	for (; iter != intset.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 用for_each方法循环输出intset，可以因避免显式使用迭代器变量
	for_each(intset.begin(), intset.end(), show);
	cout << endl;

	// 第三种循环遍历方法：声明一个容器同类型的变量，冒号后指出容器名(c++11)
	for (auto x: intset) show(x);
	cout << endl;

	// 把intset中元素的顺序打乱
	random_shuffle(intset.begin(), intset.end());
	for (iter = intset.begin(); iter != intset.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 把intset升序排序
	sort(intset.begin(), intset.end());
	for (iter = intset.begin(); iter != intset.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 把instset降序排序, 需要自定义一个比较函数
	sort(intset.begin(), intset.end(), lessthan);
	for (iter = intset.begin(); iter != intset.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	return 0;
}

int main()
{
	out_iterTest();
	return 0;
}
