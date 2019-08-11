//C++ file
/***********************************************
#
#      Filename: explicitTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 何时需要用到explicit的关键词及其作用探讨
#        Create: 2019-08-07 14:48:43
#**********************************************/
#include <iostream>


using namespace std;

/*
 * [> 一种出错的写法 <]
 * class A {
 *     public:
 *         A(int a = 5, int b = 10):m_a(a), m_b(b) {}
 *         void showNums() const { cout << m_a << "\t" << m_b << endl; }
 *     private:
 *         int m_a;
 *         int m_b;
 * };
 * 
 * int main() {
 *     A a;
 *     a = 10;
 *     a.showNums();  // 结果是10  10, 我没有重载运算符=却能直接给对象赋值的原因是: 编译器把10隐式转换成了对象temp_a(10), 再赋值给a。这样的结果并不是我们希望的
 * }
 */

class A {
    public:
        explicit A(int a = 5, int b = 10):m_a(a), m_b(b) {}  // 这里用explicit来修饰构造函数
        void showNums() const { cout << m_a << "\t" << m_b << endl; }
    private:
        int m_a;
        int m_b;
};

int main() {
    A a;
    /* a = 10;  // 这里会报错，因为explicit会抑制隐式转换的进行 */

    a = A(10);  // 显式转换还是可以的
    a.showNums();  
}
