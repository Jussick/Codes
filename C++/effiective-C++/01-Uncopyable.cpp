//C++ file
/***********************************************
#
#      Filename: 01-Uncopyable.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 条款6：防止类被拷贝的两种做法
#        Create: 2020-11-09 14:45:50
#**********************************************/
#include <iostream>

using namespace std;

// 做法1：把拷贝构造函数和=放在private中
class Object1 {
public:
    Object1() {  }  // 允许对象构造和析构
    ~Object1() {  }
private:
    Object1(const Object1&);  // 但阻止copy
    Object1& operator=(const Object1 &);
};


// 做法2：继承一个阻止copy的基类
class Uncopyable {
protected:
    Uncopyable() {  }
    ~Uncopyable() {  }
private:
    Uncopyable(const Uncopyable&);  // 不予实现就没必要写形参
    Uncopyable& operator=(const Uncopyable&); 
};

class Object2 : public Uncopyable {

};

/* 以上两种方法都能有效防止对象被拷贝，第二钟实现能把当成员函数或友元函数调用对象拷贝时，报错阶段从链接阶段提前到编译阶段，这是件好事 */

int main()
{
    Object2 obj1;
    Object2 obj2;
    obj1 = obj2;  // 错误!!!
}
