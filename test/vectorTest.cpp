//C++ file
/***********************************************
#
#      Filename: vectorTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: vector的resize和reserve的区别
#        Create: 2021-03-30 16:29:53
#**********************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 二维vector初始化的简便方法
    int row = 5, col = 5;
    vector<vector<int> > vec(row, vector<int>(col, 0) );

    vector<int> a(3, 1);
    cout << "init vec size: " << a.size() << " , capacity: " << a.capacity() << endl;
    a.reserve(2);
    cout << "after reserve 2, size: " << a.size() << ", capacity: " << a.capacity() << endl;

    a.resize(2);
    cout << "after resize 2, size: " << a.size() << ", capacity: " << a.capacity() << endl;

    a.reserve(10);
    cout << "after reserve 10, size: " << a.size() << ", capacity: " << a.capacity() << endl;

    a.resize(20);
    cout << "after resize 20, size: " << a.size() << ", capacity: " << a.capacity() << endl;

    for (auto n : a)
        cout << n << ", ";
    cout << endl;
}
