//C++ file
/***********************************************
#
#      Filename: randomShuffleTest.cpp
#
#        Author: luhg - luhengguang@joyy.sg
#   Description: test use of std::random_shuffle
                 测试结果：作用是打乱容器中元素的顺序
#        Create: 2021-09-07 15:07:38
#**********************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4,5};    
    std::random_shuffle(vec.begin(), vec.end());
    std::random_shuffle(vec.begin(), vec.end());
    std::random_shuffle(vec.begin(), vec.end());
    for (auto num : vec) cout << num << " ";
    cout << endl;
}
