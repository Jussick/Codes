//C++ file
/***********************************************
#
#      Filename: sharedPtr.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: shared_ptr的使用和其引用计数的变化
#        Create: 2021-06-03 16:12:12
#**********************************************/
#include <iostream>
#include <memory>

using namespace std;


class foo{
public:
    foo(int val):value(val) { cout << "foo " << value << " created..." << endl; }
    ~foo() { cout << "foo " << value << " destroyed..." << endl; }
    void fun() { cout << "this is func" << endl; }
private:
    int value;
};


int main()
{
    // shared_ptr<foo> p1(new foo(1));  // foo(1)的引用计数为1
    // shared_ptr<foo> p2 = p1;         // foo(1)的引用计数为2

    // cout << "-----1" << endl;  
    // p1.reset(new foo(2));            // foo(2)的引用计数为1，foo(1)的引用计数为1
    // cout << "-----2" << endl;
    // p2.reset();                      // foo(1)的 引用计数为0
    // cout << "-----3" << endl;

    foo *foo1 = new foo(1);
    shared_ptr<foo> p1;
    p1.reset(foo1);
    shared_ptr<foo> p2;
    p2.reset(foo1);
    cout << "-----1" << endl;  
}
