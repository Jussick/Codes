//C++ file
/***********************************************
#
#      Filename: 13-CastTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: c++中的各种类型转换的使用
#        Create: 2020-10-27 00:20:23
#**********************************************/
#include <iostream>
#include <string>

class obj {
    int a;
    int b;
};  

class son : public obj {
public:
    void foo() { std::cout << "yeee" << std::endl; }
};

void foo(son *ooo)
{
    ooo->foo();
}

int main()
{
    /* 1. const_cast */
    const son *ps = new son();
    foo(const_cast<son*>(ps));  // const_cast用于去掉const的限制
    foo((son *)ps);  // 当然可以这样写（C风格），不过就不是很明显了，搜索的话也基本没可能搜到

    /* 2. static_cast */
    double a = 1.2;
    int b = static_cast<int>(a);
    std::cout << b << std::endl;

    // 还有reinterpret_cast, 不过用的较少且不可移植，就不予理睬了
}
