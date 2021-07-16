//C++ file
/***********************************************
#
#      Filename: 24-weakPtr.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 使用weak_ptr打破shared_ptr的环形引用问题
                 参考：https://www.cnblogs.com/DswCnblog/p/5628314.html
#        Create: 2021-07-13 23:32:10
#**********************************************/
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class ClassB;

class ClassA
{
public:
    ClassA() { cout << "ClassA Constructor..." << endl; }
    ~ClassA() { cout << "ClassA Destructor..." << endl; }
    shared_ptr<ClassB> pb;  // 在A中引用B
};

class ClassB
{
public:
    ClassB() { cout << "ClassB Constructor..." << endl; }
    ~ClassB() { cout << "ClassB Destructor..." << endl; }
    shared_ptr<ClassA> pa;  // 在B中引用A
};

int main() 
{
    shared_ptr<ClassA> spa = make_shared<ClassA>();
    shared_ptr<ClassB> spb = make_shared<ClassB>();
    spa->pb = spb;
    spb->pa = spa;

    spb.reset();
    cout << spa->pb.expired() << endl;
    std::cout << "spa use_cout:" << spa.use_count() << " spb use_cout:" << spb.use_count() << std::endl;    //spa: 2 spb:2
	// 函数结束，思考一下：spa和spb会释放资源么？ 超过作用于时引用计数减一，此时为2，减一后不为0，所以内存不释放
    
    // 解决方法是把classA和classB中的shared_ptr改为weak_ptr即可，因为weak_ptr不会增加引用计数
    // weak_ptr的两个方法：lock和expired：
    //  lock用来把weak_ptr升级成shared_ptr，此操作会增加对象的引用计数
    //  expired方法是判断引用计数是否为0的方法，use_count若为0则返回1，否则为0
}
