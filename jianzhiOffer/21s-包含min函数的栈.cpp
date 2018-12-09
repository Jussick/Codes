//C++ file
/***********************************************
#
#      Filename: 21-包含min函数的栈.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: jianzhioffer第21题, 实现一个有最小值min方法的栈
				解决思路：1、增加一个辅助栈，保存每次push进来新元素后的当前最小元素，如：当前最小是3，
					如果push进来4，那么当前最小还是3，则往辅助栈中push一个3，否则push更小的那个；
						  2、pop方法需要数据栈和辅助栈同时pop；
						  3、min方法即是辅助栈的栈顶元素
#        Create: 2018-12-05 15:51:36
#**********************************************/
#include<iostream>
#include<stack>

using namespace std;

template <class T>
class StackWithMin {
	private:
		stack<T> m_data;  // 数据栈
		stack<T> m_min;  // 辅助栈
	public:
		StackWithMin<T> &m_push(const T& value);
		StackWithMin<T> &m_pop();
		T min();
};



template <class T>
StackWithMin<T> &StackWithMin<T>::m_push(const T& value)
{
	m_data.push(value);
	
	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
	return *this;
}

template <class T>
StackWithMin<T> &StackWithMin<T>::m_pop()
{
	if (m_data.size() > 0 && m_min.size() > 0)
	{
		m_data.pop();
		m_min.pop();
	}
	return *this;
}


template <class T>
T StackWithMin<T>::min()
{
	if (m_data.size() > 0 && m_min.size() > 0)
		return m_min.top();
}

int main()
{
	StackWithMin<int> s1;

	s1.m_push(4).m_push(6).m_push(3).m_push(2).m_push(9); 

	cout << "min of stack s1 is: " << s1.min() << endl;
	s1.m_pop().m_pop();
	cout << "After pop two element, min is: " << s1.min() << endl;

	return 0;
}

