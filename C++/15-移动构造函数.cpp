//C++ file
/***********************************************
#
#      Filename: 02-移动构造函数.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 移动构造函数在什么情况下使用？在拷贝大型临时变量时，用它来直接转让数据的所有权，省去了多余的拷贝、构造和析构的操作。
#        Create: 2019-08-07 11:03:53
#**********************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str = "hello";
    vector<string> vec;

    vec.push_back(str);  // 调用常规的拷贝构造函数，新建字符数组，拷贝数据
    cout << "After copy, str is: " << str << endl;

    vec.push_back(move(str));  // 调用移动构造函数，把str"掏空"了, 实际上并非是真的把str掏空，内容所在的地址没变，而是把这块内容的多有权转让了。
    cout << "After move, str is: " << str << endl;

    cout << "Vec: " << vec[0] << "\t" << vec[1] << endl;

}
