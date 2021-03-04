#include "leetcode.h"

using namespace std;

// LeetCode 121
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
};

int main() 
{
	string str;
	getline(cin, str);
	vector<int> nums = stringToIntegerVector(str);
	
	Solution s;
	cout << "maxProfit: " << s.maxProfit(nums) << endl;

    testGenTags();
	
	return 0;
}


