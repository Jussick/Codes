//C++ file
/***********************************************
#
#      Filename: 03-对象内存布局查看.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 用offsetof宏查看对象成员距离对象开始的偏移量
#        Create: 2020-10-12 14:22:35
#**********************************************/
#include <iostream>
#include <stddef.h>

using namespace std;

class test {
public:
    int base1;
    int base2;

    virtual void show();
};

int main()
{
    cout << "size: " << sizeof(test) << endl;
    cout << offsetof(test, base1) << endl;
    cout << offsetof(test, base2) << endl;
}
