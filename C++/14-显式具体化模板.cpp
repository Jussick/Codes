//C++ file
/***********************************************
#
#      Filename: 01-显式具体化模板.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: template<> 的用法，即显式具体化模板。何时需要用到呢？在对某些特定类型如自定义类型进行个性化处理时，默认的方法或运算符不能实现原有功能时，如下面的交换结构体中的一部分数据。
#        Create: 2019-08-06 15:59:37
#**********************************************/
#include <iostream>
using namespace std;

struct Job {
    string name;
    double salary;
    int level;
};

/*
 * 普通模板的定义
 */
template<typename T> 
void Swap(T &a, T &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

/*
 * 显式具体化模板的定义方法
 */
template <> void Swap<Job> (Job &A, Job &B) {
    double tem1 = A.salary;
    A.salary = B.salary;
    B.salary = tem1;

    int tem2 = A.level;
    A.level = B.level;
    B.level = tem2;
}

int main() {
    int inta = 1, intb = 2;
    Job zhangSan = {"zhangSan", 8000, 5};
    Job liSi = {"liSi", 10000, 7};

    cout << "inta: " << inta << ", intb: " << intb << endl;
    cout << "张三: " << zhangSan.salary << "\t" << zhangSan.level << endl;
    cout << "李四: " << liSi.salary << "\t" << liSi.level << endl;

    Swap(inta, intb);  // 编译器将(隐式)实例化普通模板的int类型函数
    // Swap<int>(inta, intb);  // 编译器将(显式)实例化普通模板的int类型函数（可以隐式为什么还要显式呢?）
    Swap(zhangSan, liSi);  // 编译器将(隐式)实例化显式具体化模板Job类型函数

    cout << endl <<  "交换后：" << endl << endl;
    cout << "inta: " << inta << ", intb: " << intb << endl;
    cout << "张三: " << zhangSan.salary << "\t" << zhangSan.level << endl;
    cout << "李四: " << liSi.salary << "\t" << liSi.level << endl;

    return 0;
}
