//C++ file
/***********************************************
#
#      Filename: 06-柠檬水找零.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 860. 柠檬水找零
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。

顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

示例 1：

输入：[5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
示例 2：

输入：[5,5,10]
输出：true
示例 3：

输入：[10,10]
输出：false
示例 4：

输入：[5,5,10,10,20]
输出：false
解释：
前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
由于不是每位顾客都得到了正确的找零，所以答案是 false。
 

提示：

0 <= bills.length <= 10000
bills[i] 不是 5 就是 10 或是 20 

链接：https://leetcode-cn.com/problems/lemonade-change
#        Create: 2020-12-10 15:45:01
#**********************************************/
#include <iostream>
#include <vector>

using namespace std;


class Solution2 {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5)
        {
            return false;
        }

        vector<int> change(2, 0);  // 分别代表剩余5、10、20元的张数
        for (int i = 0; i < bills.size(); ++i)
        {
            switch (bills[i])
            {
                case 5:
                    change[0]++;
                    continue;
                case 10:
                    change[1]++;
                    if (change[0] == 0)
                    {
                        return false;
                    }
                    else 
                    {
                        change[0]--;
                    }
                    continue;
                case 20:
                    if (change[0] == 0 || change[1] == 0)
                    {
                        return false;
                    }
                    else 
                    {
                        change[0]--;
                        change[1]--;
                    }
                    continue;
            }
            return true;
        }
    }
};

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool res = true;
        if (bills[0] != 5)
        {
            res = false;
        }

        int five = 0, ten = 0;
        for (int i = 0; i < bills.size(); ++i)
        {
            switch (bills[i])
            {
                case 5:
                    five++;
                    continue;
                case 10:
                    ten++;
                    if (five == 0)
                    {
                        res = false;
                        break;
                    }
                    else
                    {
                        five--;
                    }
                    continue;
                case 20:
                    if (five == 0)
                    {
                        res = false;
                        break;
                    }
                    else if (ten == 0)
                    {
                        if (five < 3)
                        {
                            res = false;
                            break;
                        }
                        else
                        {
                            five-=3;
                        }
                    }
                    else
                    {
                        five--;
                        ten--;
                    }

                    continue;
            }
        }
        return res;
    }
};

int main()
{
    Solution ss;
    vector<int> vec{5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    bool res = ss.lemonadeChange(vec);
    cout << res << endl;
}
