//C++ file
/***********************************************
#
#      Filename: 01-变长参数模板.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 变长参数模板使用的例子，用到了递归的思想
#        Create: 2020-09-02 11:46:13
#**********************************************/
#include <iostream>

using namespace std;

// 使用可变模版参数求和
template <typename T>
T sum(T t)
{
    return t;
}
template <typename T, typename ...Types>
T sum(T first, Types ... rest)
{
    return first + sum<T>(rest...);
}

int main()
{
    cout << "1 + 2.5 = " << sum<double>(1, 2.5) << endl;;
    cout << "1 + 2 + 3 = " << sum<int>(1,2,3) << endl;

    return 0;
}
