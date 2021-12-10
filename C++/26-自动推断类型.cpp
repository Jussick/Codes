//C++ file
/***********************************************
#
#      Filename: 26-自动推断类型.cpp
#
#        Author: luhg - luhengguang@joyy.com
#   Description: decltype的使用
#        Create: 2021-12-07 16:06:47
#**********************************************/
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/* 有时，我们想定义一个变量，这个变量类型和一个已存在的变量类型一样，但又不想重新定义的时候，就可以利用自动推断类型 */
int main()
{
    std::vector<std::string> vec; 
    decltype(vec) vec2 = {"haha", "hoho"};  // 把vec2定义成和vec一样的类型
    cout << "here is element in vec2:\n";
    for (auto item : vec2)
    {
        cout << item << endl;
    }

    return 0;
}
