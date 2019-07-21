//C++ file
/***********************************************
#
#      Filename: functionTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-06-22 14:36:26
#**********************************************/
#include <iostream>
#include <functional>
 

typedef std::function<void (int, int)> myFunc;
std::function< int(int) > Functional;
 
// 普通函数
int TestFunc(int i){
    return i;
}
 
// Lambda表达式
auto lambda = [](int i)-> int { return i; };
 
// 仿函数
class Functor{
public:
    int operator()(int i){
        return i;
    }
};
 
// 1. 类成员函数
// 2. 类静态函数
class Test{
public:
    int foo(int i){ return i; }
    static int staticFunc(int i){ return i; }
};
 
int main(){
 
    Functional = TestFunc;
    std::cout << "普通函数： " << Functional(1) << std::endl;
 
    Functional = lambda;
    std::cout << "Lambda函数： " << Functional(2) << std::endl;
 
    Functor functor;
    Functional = functor;
    std::cout << "仿函数： " << Functional(3) << std::endl;
 
	Test testObj;
    Functional = std::bind(&Test::foo, testObj, std::placeholders::_1);
    std::cout << "类成员函数： " << Functional(4) << std::endl;
 
    Functional = Test::staticFunc;
    std::cout << "类静态函数： " << Functional(5) << std::endl;
 
    std::cin.get();
}

void print(int a, int b) {
    std::cout << "a:" << a << "b:" << b << std::endl;
}

int main1() {
    myFunc mm = print;
    int a = 1, b = 2;
    mm(a, b);
    return 0;
}
