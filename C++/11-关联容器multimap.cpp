//C++ file
/***********************************************
#
#      Filename: 11-关联容器multimap.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-20 14:22:50
#**********************************************/

#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	// 创建一个multimap对象mmap
	multimap<int, string> mmap;
	// 创建一个键值对item
	pair<const int, string> item(10, "Beijing");
	// 通过这种方式访问item的键和值
	cout << item.first << " " << item.second << endl << endl;
	// 把键值对item插入mmap
	mmap.insert(item);

	// 或者用匿名的方法插入
	mmap.insert(pair<const int, string> (431, "ChangChun"));
	mmap.insert(pair<const int, string> (431, "Shenyang"));

	// 找到键值为431的value并输出
	cout << "键值为431的城市:" << endl;
	auto range = mmap.equal_range(431);  // equal_range方法返回两个迭代器，将其包含在一个pair中，通过此方法找到指定键值的内容
	for (auto it = range.first; it != range.second; it++)
		cout << (*it).second << " ";
	cout << endl << endl;

	// 遍历输出mmap中的所有内容
	cout << "遍历mmap" << endl;
	multimap<int, string>::iterator pd = mmap.begin();
	for (; pd != mmap.end();) {
		cout << (*pd).first << " " << (*pd).second;
		cout << endl;
		pd = mmap.erase(pd);  // erase方法会把当前迭代器指向的内容删除，并把迭代器指向next
	}
	cout << endl;


	cout << "第二次遍历mmap" << endl;
	auto ppd = mmap.begin();
	for (int n = 0; ppd != mmap.end(); ++ppd, ++n) {
		cout << (*ppd).first << " " << (*ppd).second << endl;
		cout << "n = " << n << endl;
	}
	cout << endl;

	// count 方法
	cout << "所有键值为431的城市数目：" << endl;
	cout << mmap.count(431) << endl << endl;
	return 0;
}
