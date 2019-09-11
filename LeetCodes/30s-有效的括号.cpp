#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// leetcode:20
class Solution
{
public:
    stack<int> m_ss;
    bool isValid(string s)
    {
        bool ret;
        int len = s.length();
        if (len % 2 != 0)  // 空串也是，单数长度的不是
        {
            return false;
        }

        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                m_ss.push(s[i]);  // 左括号入栈
            }
            else
            {
                if (!m_ss.empty())
                {
                    if ((s[i] == ')' && m_ss.top() == '(') ||
                            (s[i] == ']' && m_ss.top() == '[') ||
                            (s[i] == '}' && m_ss.top() == '{') )
                    {
                        m_ss.pop();
                    }
                    else // 存在无法匹配的右括号
                        return false;
                }
                else  // 单独的右括号
                    return false;
            }
        }

        if (m_ss.empty())  // 所有左括号都匹配上了
            ret = true;
        else
            ret = false;
        return ret;
    }
};
int main()
{
    Solution s;
    string str = "}}";
    cout << (s.isValid(str)?"true":"false") << endl;
}