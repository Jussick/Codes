//C++ file
/***********************************************
#
#      Filename: 48-最后一个单词的长度.cpp
#
#        Author: luhg - luhengguang@joyy.com
#   Description: leetcode-58
#        Create: 2021-11-21 17:47:26
#**********************************************/
#include <iostream>
#include <string>

class Solution {
    public:
        int lengthOfLastWord(std::string s) {

            int lastWordLength = 0; 
            int startPos = s.length();
            int len = startPos;

            // start from end of input string, find the pos which is not "space"
            for (int pos = len; pos >= 0; --pos) 
            {
                if (pos-1 < 0) break;

                if (s[pos-1] == ' ')
                {
                    startPos--;
                    continue;
                }
                else
                    break;
            }

            std::cout << "startPos: " << startPos << std::endl;

            // count from startPos to fisrt "space"
            for (int pos = startPos; pos >= 0; --pos)
            {
                std::cout << "lastWordLength: " << lastWordLength  << ", pos: " << pos << std::endl;
                if (pos-1 < 0) break;

                if (s[pos-1] != ' ')
                {
                    lastWordLength++;
                }
                else
                    break;
            }
            return lastWordLength;
        }
};

int main()
{
    Solution ss;
    std::cout << ss.lengthOfLastWord("a") << std::endl;
    return 0;
}
