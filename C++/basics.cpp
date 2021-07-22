//C++ file
/***********************************************
#
#      Filename: basics.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 记录一些容易遗漏的c++基础知识, 一些小demo
#        Create: 2021-07-14 11:13:48
#**********************************************/
#include <iostream>
#include <map>

using namespace std;

// map.insert的返回值是pair类型的，保存一个指向被插入元素的迭代器和一个描述是否插入的bool值。
void MapInsert() 
{
    map<int, string> mm;
    pair<map<int, string>::iterator, bool> ret = mm.insert(pair<int, string>(3, "three"));
    if (ret.second)
    {
        cout << "three insert success!\n";
        cout << "mm[3]: " << mm.at(3) << endl;;
    }
    else
    {
        cout << "three insert failed!\n";
    }
}

int MapAt()
{

    map<int, string> mm;
    mm[0] = "zero";
    mm[1] = "one";

    try
    {
        cout << "mm.at(1): " << mm.at(1) << endl;
        cout << "mm.at(2): " << mm.at(2) << endl;  // 不存在会抛异常
    }
    catch (const std::exception &e)
    {
        cout << "catch exception: "  << e.what() << endl;
    }

    cout << "mm[2]: " << mm[2] << endl;   // 不存在会新建一个元素(不会报错), key:2  value: ""   很坑！！！需注意若只是访问map中的元素，应使用at而非中括号索引访问
}

int main()
{
    // MapInsert();
    MapAt();
}
