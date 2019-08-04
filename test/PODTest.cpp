//C++ file
/***********************************************
#
#      Filename: PODTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: POD是Plain Old Data的缩写，指一种通过二进制拷贝后还能保持其数据不变的类或结构体。
#        Create: 2019-07-30 19:33:17
#**********************************************/
#include <iostream>

using namespace std;

class A { A(){} };  
class B { B(B&){} };  
class C { C(C&&){} };  
class D { D operator=(D&){} };  
class E { E operator=(E&&){} };  
class F { ~F(){} };  
class G { virtual void foo() = 0; };  
class H : G {};  
class I {};  

class Student{
public:
    Student() {}  // 显式声明了默认构造函数，使得这个类不再是POD
    Student(int a, int b):m_a(a), m_b(b) {}

private:
    int m_a;
    int m_b;
};

class Student_default{
public:
    Student_default() = default;  // 把显式声明的类声明为default类型，编译器优化使得其还是一个POD，起到加速的作用
    Student_default(int a, int b):m_a(a), m_b(b) {}

private:
    int m_a;
    int m_b;
};
int main() 
{  
    // is_pod()模板类可以查看某类型是否为POD类型，若是返回1，不是返回0
    cout << is_pod<A>::value << endl;  // 有不平凡的构造函数  
    cout << is_pod<B>::value << endl;  // 有不平凡的拷贝构造函数  
    cout << is_pod<C>::value << endl;  // 有不平凡的拷贝赋值运算符  
    cout << is_pod<D>::value << endl;  // 有不平凡的拷贝赋值运算符  
    cout << is_pod<E>::value << endl;  // 有不平凡的移动赋值运算符  
    cout << is_pod<F>::value << endl;  // 有不平凡的析构函数  
    cout << is_pod<G>::value << endl;  // 有虚函数  
    cout << is_pod<H>::value << endl;  // 有虚基类  
  
    cout << is_pod<I>::value << endl;  // 平凡的类  
    cout << "Student: " << is_pod<Student>::value << endl;  // 0
    cout << "Student_default: " << is_pod<Student_default>::value << endl;  // 1


  
    return 0;  
}  

