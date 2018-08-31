//C++ file
/***********************************************
#
#      Filename: 07-两个队列实现栈.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-28 14:55:50
#**********************************************/
#include <iostream>
#include <string>
#include <stack>
#include <iterator>
using namespace std;
/*
 *   整体思路：
 *       把入队的元素压入stack1中，再分别从stack1栈顶出栈，依次压入stack2中，
 *       再从stack2中出栈的顺序即是先进先出
 */

template <class T>
class cQueue {
private:
    stack<T> stack1;
    stack<T> stack2;
public:
    cQueue() {}
    ~cQueue() {}
    cQueue<T> &enqueue(T elem); // 返回引用以连续入队
    T dequeue();  // 出队返回元素
    bool empty();

};

template <class T>
cQueue<T> &cQueue<T>::enqueue(T elem)
{
    stack1.push(elem);
    return *this;
}

template <class T>
T cQueue<T>::dequeue()
{
    if (!stack2.empty())
    {
        T deVlaue = stack2.top();
        stack2.pop();
        return deVlaue;
    }
    if (!stack1.empty())
    {
        while(!stack1.empty())
        {
            T temp = stack1.top();
            stack2.push(temp);
            stack1.pop();
        }
        T deValue = stack2.top();
        stack2.pop();
        return deValue;
    }
    else
    {
        cout << "queue is empty." << endl;
        return -1;
    }
}

template <class T>
bool cQueue<T>::empty()
{
    if (stack1.empty() && stack2.empty())
        return true;
    else
        return false;
}

int main()
{
    cQueue<int> qq;
    qq.enqueue(1).enqueue(5);
    qq.enqueue(2);
    qq.enqueue(3);
    qq.enqueue(4);
    while(!qq.empty())
    {
        int value;
        value = qq.dequeue();
        cout << value << endl;
    }
    qq.dequeue();
    return 0;
}
