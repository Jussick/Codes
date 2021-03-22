//C++ file
/***********************************************
#
#      Filename: 02-VirtualDestructor.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 条款7：应该给任何有多态性的类一个虚析构函数
#        Create: 2020-11-09 15:31:47
#**********************************************/
#include <iostream>

using namespace std;


class base {
public:
    base() {  }
    virtual ~base() { cout << "base destructor..." << endl; }
};

class deliver : public base {
public:
    deliver() {  }
    ~deliver() { cout << "deliver destructor..." << endl; }
};

int main()
{
    base *obd = new deliver();  // 若base的析构函数不是virtual，则下面的delete只会调用base的析构；而加上virtual之后，代表他是要被子类重写的，故delete时就会先调用子类的析构，再调用基类的析构
    delete obd;
}
