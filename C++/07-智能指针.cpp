//C++ file
/***********************************************
#
#      Filename: 07-smartPtr.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-15 15:36:24
#**********************************************/

#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Report {
	string str;
public:
	Report(const string s):str(s) { cout << "Object " << str << " created." << endl; }
	~Report() { cout << "Object " << str << " deleted..." << endl; }
	void show() const { cout << "I am " << str << '.' << endl; }
};

int main()
{
#if 0
	{
		// 智能指针无需手动delete
		auto_ptr<Report> pt(new Report("aaa"));  // 智能指针对象初始化，要注意格式
		auto_ptr<Report> pt2 = pt;  // 这样会使aaa对象的ownership从pt转让给pt2，故下面一句会报错, 解决办法是用shared_ptr
		pt2->show();
	}
#endif
#if 1
	{
		shared_ptr<Report> spt(new Report("test"));  // 共享智能指针初始化
		shared_ptr<Report> spt2 = spt;  // 这样不会转让spt的ownership，而是把test对象引用计数+1，只有计数为0时，才调用析构函数，这样就能有效防止重复析构同一个对象的问题
		spt->show();
		spt2->show();
	}
#endif

	// 普通指针不手动delete不会释放空间
	Report *pr = new Report("bbb");
	pr->show();

	return 0;
}
