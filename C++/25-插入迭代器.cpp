//C++ file
/***********************************************
#
#      Filename: 25-插入迭代器.cpp
#
#        Author: luhg - luhengguang@joyy.sg
#   Description: template <class Container, class Iterator> insert_iterator<Container> inserter (Container& x, Iterator it);
                 x为容器，it为插入位置
#        Create: 2021-10-22 10:31:32
#**********************************************/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void print(const vector<int> &vv)
{
    for (int num : vv)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> vec{1,2,3,4};
    fill_n(vec.begin(), 2, 100);
    print(vec);  // 100 100 3 4

    vector<int> vec2{1,2,3,4};
    fill_n(inserter(vec2, vec2.end()), 2, 100);
    print(vec2);  // 1 2 3 4 100 100
}
