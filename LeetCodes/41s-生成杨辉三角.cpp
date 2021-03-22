//C++ file
/***********************************************
#
#      Filename: 04-生成杨辉三角.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
#        Create: 2020-09-08 11:15:43
#**********************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret_vec;
        for (int i = 1; i <= numRows; ++i)        
        {
            vector<int> row_vec;
            for (int j = 0; j < i; ++j)
            {
                if (j == 0 || j == i-1)
                {
                    row_vec.push_back(1);
                }
                else if (i > 2)
                {
                    row_vec.push_back(ret_vec[i-2][j-1] + ret_vec[i-2][j]);
                }
            }
            ret_vec.push_back(row_vec);
        }
        return ret_vec;
    }

    void PrintAYanghuiTriangle(const vector<vector<int> > &vec)
    {
        int rowsum = vec.size();
        for (auto row : vec)
        {
            int rownum = row.size();
            if (rownum != rowsum)
            {
                for (int i = 1; i <= rowsum-rownum+1; ++i)
                    cout << " ";
            }

            for (auto num : row)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }

};


int main()
{
    Solution s;
    int rowsum;
    cout << "输入要生成杨辉三角的行数: ";
    cin >> rowsum;
    vector<vector<int> > vec = s.generate(rowsum);
    s.PrintAYanghuiTriangle(vec);    
}


