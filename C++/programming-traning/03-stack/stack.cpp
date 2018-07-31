//C++ file
/***********************************************
#
#      Filename: stack.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 用类模板实现栈的简单操作
#        Create: 2018-07-05 13:50:10
#**********************************************/

#include "mystack.h"

template <class T>
my_Stack<T>::my_Stack()
{
	this-> top = 0;
}
template <class T>
my_Stack<T>::~my_Stack()
{
	cout << "I'm the cute destructor~" << endl;
}
template <class T>
bool my_Stack<T>::isEmpty()
{
	return top == 0;
}
template <class T>
bool my_Stack<T>::isFull()
{
	return top == MAX;
}
template <class T>
my_Stack<T> &my_Stack<T>::push(const T item)
{
	//cout << "This is push, going to push " << item << endl;
	if (this-> isFull())
		cout << "my_Stack is full" << endl;
	else
	{
		this-> items[top++] = item;
		//cout << "After push, items[" << top-1 << "] = " << items[top-1] << endl;
	}
	return *this;
}
template <class T>
const T my_Stack<T>::pop(void)
{
	if (this-> isEmpty())
		cout << "my_Stack is empty" << endl;
	else
	{
		return this-> items[--top];  // --操作一定要在前面！！！
	}

}
template <class T>
my_Stack<T> &my_Stack<T>::pop_con()
{
	if (this-> isEmpty())
		cout << "my_Stack is empty" << endl;
	else
	{
		cout << "pop:" << this->items[--top] << endl;
		return *this;
	}

}
template <class T>
void my_Stack<T>::showStackInfo()
{
	my_Stack<T> * ss = this;
	cout << "stack: ";
	while (!ss-> isEmpty())
	{
		cout << ss-> pop() << " ";
	}
	cout << endl;
}
template <class T>
int my_Stack<T>::getTop()
{
	return this-> top;
}

int main()
{
	my_Stack<int> stack1;
	stack1.push(12).push(11).push(10).push(9);
	stack1.pop_con().pop_con();

	stack1.showStackInfo(); 
	

	return 0;
}
