//C++ file
/***********************************************
#
#      Filename: 47-两句话中不常见的单词.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: leetcode-884 simple
#        Create: 2021-10-10 17:17:23
#**********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <unistd.h>

using namespace std;


class Solution {
    public:
        /* 把字符串按空格分割，放入map中：key -- 单词、value -- 0/1, 0代表该单词出现多次，1代表出现一次 */
        map<string, int> splitIntoWords(const string &str)
        {
            int length = str.length();
            map<string, int> mm;
            unsigned long cur_pos = 0;
            unsigned long find_pos = str.find(" ", cur_pos);

            while (find_pos != string::npos && cur_pos < length) 
            {
                cout << "cur_pos: " << cur_pos << ", find_pos: " << find_pos << endl;
                // sleep(1);
                if (mm.find(str.substr(cur_pos, find_pos-cur_pos)) != mm.end())                
                {
                    mm[str.substr(cur_pos, find_pos-cur_pos)] = 0;
                }
                else
                {
                    mm.insert(make_pair<string, int>(str.substr(cur_pos, find_pos-cur_pos), 1));
                }
                cur_pos = (find_pos+1);
                find_pos = str.find(" ", cur_pos);
            }
            if (mm.find(str.substr(cur_pos, str.length()-cur_pos)) != mm.end())
            {
                mm[str.substr(cur_pos, str.length()-cur_pos)] = 0;
            }
            else
            {
                mm.insert(make_pair<string, int>(str.substr(cur_pos, str.length()-cur_pos), 1));
            }
            return mm;
        }

        vector<string> uncommonFromSentences(string s1, string s2)
        {
            map<string, int> tmp_map1 = splitIntoWords(s1);
            map<string, int> tmp_map2 = splitIntoWords(s2);
            map<string, int> sum_map;
            vector<string> ret_vec;
            ret_vec.reserve(200);

            printMap(tmp_map1);
            printMap(tmp_map2);

            sum_map.swap(tmp_map1);
            for (auto pair_ : tmp_map2)
            {
                if (pair_.second == 1)  // 只出现一次
                {
                    if (sum_map.find(pair_.first) == sum_map.end())
                    {
                        sum_map.insert(pair_);
                    }
                    else
                    {
                        sum_map[pair_.first] = 0;
                    }
                }
                if (pair_.second == 0)  // 判断在s2中出现多次，但在s1中出现一次的情况
                {
                    if (sum_map.find(pair_.first) != sum_map.end())
                    {
                        sum_map[pair_.first] = 0;
                    }
                }
            }

            printMap(sum_map);
            for (auto pair_ : sum_map)
            {
                if (pair_.second == 1)
                    ret_vec.push_back(pair_.first);
            }

            return ret_vec;
        }

        void printVec(const vector<string> vec)
        {
            for (auto str : vec)
            {
                cout << str << " ";
            }
            cout << endl;
        }

        void printMap(const map<string, int> &mm)
        {
            cout << "printMap\n";
            for (auto pair : mm)
            {
                cout << pair.first << "\t" << pair.second << endl;
            }
        }
};

int main()
{
    Solution ss;
    string s1 = "fo ly ly";
    string s2 = "fo fo etx";
    vector<string> vec = ss.uncommonFromSentences(s1, s2);
    ss.printVec(vec);
    return 0;
}

