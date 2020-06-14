//C++ file
/***********************************************
#
#      Filename: arguEvalOrder.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 探讨函数参数处理的顺序，truned out 是为定义的
#        Create: 2020-05-17 10:03:19
#**********************************************/
#include <iostream>


void printSth(int a, int b)
{
    std::cout << a << " + " << b << " = " << a + b << std::endl;
}

int main()
{
    int value = 0;
    printSth(value++, value++);

    return 0;
}
