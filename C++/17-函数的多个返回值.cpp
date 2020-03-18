//C++ file
/***********************************************
#
#      Filename: 17-函数的多个返回值.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: c++11中函数返回多个返回值的方法
#        Create: 2020-01-07 23:48:24
#**********************************************/
#include <iostream>

using namespace std;

tuple<int, string> returnTuple()
{
    int a = 6;
    string str = "second";
    return std::make_tuple(a, str);  // 这里把make_tuple换成std::tie效果一样
}

int main()
{
    auto tp = returnTuple();
    int a = std::get<0>(tp);
    string str = std::get<1>(tp);
    cout << a << " " << str << endl;
}
