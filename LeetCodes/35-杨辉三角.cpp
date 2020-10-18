//C++ file
/***********************************************
#
#      Filename: 35-杨辉三角.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-09-07 21:32:45
#**********************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret_vec;    

        for (int i = 0; i < numRows; ++i)
        {
            // cout << endl << "i: " << i << endl;
            vector<int> row_vec;
            for (int j = 0; j < i; ++j)
            {
                // cout << j << " ";
                if (j == 0 || j == i)
                {
                    row_vec.push_back(1);
                }
                else if (i >= 2)
                {
                    row_vec.push_back(ret_vec[i-1][j-1] + ret_vec[i-1][j]);
                }
            }
            ret_vec.push_back(row_vec);
        }
        return ret_vec;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > vec = s.generate(5);

    for (auto row : vec)
    {
        for (auto num : row) 
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
