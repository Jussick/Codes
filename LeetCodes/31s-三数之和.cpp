//C++ file
/***********************************************
#
#      Filename: 3sum.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 寻找数组中加和为某数的三元组的集合
#        Create: 2019-12-19 10:25:27
#**********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/***********************************************
#      函数名称: find3SumEqualTarget
#
#   Description: 在输入的数组中寻找三元组，满足三数之和为指定的某个值
#     parameter: vec -- 输入的数组
                 findSum -- 要找的和
#   returnValue: 满足条件的三元组的集合
#        Author: luhg
#        Create: 2019-12-19 11:02:01
#**********************************************/

vector<vector<int> > find3SumEqualTarget(vector<int> &vec, int findSum)
{
    vector<vector<int> > ret_vecSet;
    if (vec.size() < 3)
    {
        return ret_vecSet;
    }
    sort(vec.begin(), vec.end());    

    auto last = vec.end();

    for (auto a = vec.begin(); a != prev(last, 2); a = upper_bound(vec.begin(), prev(last, 2), *a))
    {
        for (auto b = next(a); b != prev(last); b = upper_bound(next(a), prev(last), *b))
        {
            int target = findSum - *a - *b;
            if (binary_search(next(b), last, target))
            {
                ret_vecSet.push_back(vector<int> {*a, *b, target});
            }
        }
    }
    return ret_vecSet;
}


int main()
{
    vector<int> vec = {-4, -1, -1, 0, 1, 2};
    auto ret_vec = find3SumEqualTarget(vec, 0);

    for (auto item : ret_vec)
    {
        for (int i = 0; i < item.size(); ++i)
        {
            cout << item[i] << " ";
        }
        cout << endl;
    }
}
