//C++ file
/***********************************************
#
#      Filename: 04-emplace_backTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-10-14 16:47:50
#**********************************************/
#include <iostream>
#include <vector>

using namespace std;

struct haha {
    int num;
    string name;
};

int main()
{
    vector<haha> vv;    
    vv.emplace_back();  // 此时已经在列表末尾申请了一个元素的空间
    auto &num = vv.back();
    num = {1, "Edward"};

    vv.emplace_back(haha{2, "Lucas"});  // 原地构造后转移主权，使用右值引用，减少拷贝的过程

    cout << "size: " << vv.size() << endl;

    for (auto item : vv)
    {
        cout << item.name << " ";
    }
    cout << endl;
}
