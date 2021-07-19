#include "leetcode.h"

using namespace std;

// LeetCode 121
// 需要注意最大收益不能是最大值减最小值，还有个顺序的问题，因为卖出日不能在买入日之前

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int maxProfit = 0;
        int length = prices.size();
        for (int buyDay = 0; buyDay <= length - 2; ++buyDay)
        {
            for (int sellDay = buyDay + 1; sellDay < length; ++sellDay)
            {
                if (prices[sellDay] > prices[buyDay])
                {
                    maxProfit = prices[sellDay] - prices[buyDay];
                }
            }
        }

        return maxProfit;
    }

    // 遍历一次就找出最大收益的方法
	int maxProfit_once(const vector<int> &prices)
    {
        if (prices.size() == 0) return 0;

        int maxProfit = 0;
        int minValue = prices[0];

        for (size_t i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < minValue) 
            {
                minValue = prices[i];
            }
            else
            {
                maxProfit = prices[i] - minValue;
            }
        }
        return maxProfit;
    }
};

int main() 
{
	string str;
	getline(cin, str);
	vector<int> nums = stringToIntegerVector(str);
    cout << "----------1\n";
	
	Solution s;
	cout << "maxProfit: " << s.maxProfit_once(nums) << endl;

	return 0;
}


