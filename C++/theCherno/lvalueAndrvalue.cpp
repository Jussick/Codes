//C++ file
/***********************************************
#
#      Filename: lvalueAndrvalue.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 左值和右值，当能够自己判断输入的参数是左值还是右值的时候，就可以对其进行一些特殊的处理，如：可以对右值move操作，因为知道它是个暂时的变量，不会存在很久。这样能优化程序的效率。
#        Create: 2020-04-06 17:04:48
#**********************************************/
#include <iostream>

void printSth(const std::string &str)   // accept both lvalue and rvalue
{
    std::cout << "[lvalue]" << str << std::endl;
}

void printSth(std::string &&str)    // accept rvalue only
{
    std::cout << "[rvalue]" << str << std::endl;
}

int main()
{
    std::string firstname = "Edward";
    std::string lastname  = "Lucas";

    printSth(firstname);  // lvalue version
    printSth(lastname);  // lvalue version
    printSth(firstname + lastname);  // rvalue version
}
