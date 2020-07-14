//C++ file
/***********************************************
#
#      Filename: 3-LongestSubstringWithoutRSameChars.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-07-11 09:53:42
#**********************************************/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string str);
};

int Solution::lengthOfLongestSubstring(string str)
{
    unordered_set<char> uset;
    int len = str.length();
    int rk = -1, cur = 0;
    int ans = 0;
    size_t prev_size;

    uset.insert(str[cur]);
    prev_size = uset.size();
    for (rk = cur+1; rk != len; ++rk)
    {
        cout << "rk: " << rk << endl;
        uset.insert(str[rk]);
        if (uset.size() > prev_size)
        {
            prev_size = uset.size();
            ans = uset.size();
        }
        else
        {
            cur++;
            uset.erase(uset.begin());
            --prev_size;
            --rk;
        }
    }

    return ans;
}

int main()
{
    string str = "abrkaabcdefghijjxxx";
    Solution ss;
    int len = ss.lengthOfLongestSubstring(str);
    cout << len << endl;
}
