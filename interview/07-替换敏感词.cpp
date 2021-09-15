//C++ file
/***********************************************
#
#      Filename: tt.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 小鹏二面
#        Create: 2021-08-04 20:37:37
#**********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::endl;
using std::cout;

/***********************************************
#      函数名称: ReplaceWords
#
#   Description: 替换敏感词为 *
            tips: 面试官提示的：可以从头到尾遍历一次inStr，比较每个字符和wordList中的字符是否相等，这样可以减少遍历inStr的次数？
#     parameter: [in] inStr: 输入字符串
                 [in] wordList: 敏感词列表
#   returnValue: 替换后的字符串
#   	 Author: luhg
#        Create: 2021-08-05 19:19:15
#**********************************************/
std::string ReplaceWords(std::string &inStr, std::vector<std::string> wordList)
{
    for (size_t i = 0; i < inStr.length(); ++i)
    {
        if (inStr[i] >= 'A' && inStr[i] <= 'Z')
        {
            inStr[i] += 'a' - 'A';
        }
    }
    
    for (size_t i = 0; i < wordList.size(); ++i)
    {
        size_t pos = 0;
        while (pos < inStr.length())
        {
            int loc = inStr.find(wordList[i], pos);
            if (loc == -1) break;

            for (size_t j = loc; j < loc+wordList[i].length(); ++j)
            {
                inStr[j] = '*';
            }
            pos = loc + wordList[i].length();
        }
    }

    return inStr;
}

int main()
{
    std::string inStr = "abcaaahhhlala";
    std::vector<std::string> wordList = {"lala", "abc"};
    std::string out = ReplaceWords(inStr, wordList);

    cout << out << endl;
}
