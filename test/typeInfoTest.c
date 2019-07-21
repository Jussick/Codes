//C++ file
/***********************************************
#
#      Filename: typeinfoTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: c++中的类型查看
#        Create: 2019-07-05 14:14:32
#**********************************************/
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int a;
    char ch;
    char name[20];
    string str;
    double b;
    long c;
    long long d;
    bool e;
    cout << "The show of int is " << typeid(a).name() <<  endl;
    cout << "The show of char is " << typeid(ch).name() <<  endl;
    cout << "The show of char array is " << typeid(name).name() <<  endl;
    cout << "The show of string is " << typeid(str).name() <<  endl;
    cout << "The show of double is " << typeid(b).name() <<  endl;
    cout << "The show of long is " << typeid(c).name() <<  endl;
    cout << "The show of long long is " << typeid(d).name() <<  endl;
    cout << "The show of bool is " << typeid(e).name() <<  endl;
    return 0;
}