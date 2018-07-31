#ifndef MYSTACK_H
#define MYSTACK_H

#include<iostream>
#include<string>
#include<iomanip>
#define MAX 10
using namespace std;

template <class T>  // 类模板（把类声明成模板），代表一类类.
class my_Stack {
private:
	int top;
	T items[MAX];
public:
	my_Stack(void);
	~my_Stack(void);

	bool isEmpty(void);
	bool isFull(void);
	my_Stack<T> &push(const T item);  // 返回类模板的引用，为了能够连续push()
	const T pop(void);  // 返回pop值
	my_Stack<T> &pop_con(void);  // 返回对象引用，连续pop
	void showStackInfo(void);
	int getTop(void);
};

#endif
