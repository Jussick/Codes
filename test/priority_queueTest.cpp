//C++ file
/***********************************************
#
#      Filename: priority_queueTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 优先级队列，会默认按照成员由大到小的顺序排列
#        Create: 2020-09-29 17:25:57
#**********************************************/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // priority_queue<int> q;
    // 相当于priority_queue<int, vector<int>, less<int> > q, 
    priority_queue<int, vector<int>, less<int> > q;

    q.push(1);
    q.push(2);
    q.push(3);

    int num = q.top();
    q.pop();
    cout << "num: " << num << endl;
    num = q.top();
    q.pop();
    cout << "num: " << num << endl;
    num = q.top();
    q.pop();
    cout << "num: " << num << endl;
}
