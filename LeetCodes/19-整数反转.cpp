//C++ file
/***********************************************
#
#      Filename: 19-整数反转.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 
	给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

		示例 1:
		
		输入: 123
		输出: 321
		 示例 2:
		
		输入: -123
		输出: -321
		示例 3:
		
		输入: 120
		输出: 21

		注意:
		假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
#        Create: 2019-01-09 15:11:08
#**********************************************/
#include<iostream>
#define INTMAX 2147483647
#define INTMIN -2147483648

using namespace std;

class Solution {
public:
	bool isOverFlow(int x, int pop) {
		if (x >= INTMAX / 10)
		{
			if (x == INTMAX / 10)	
			{
				if (pop > 7)
					return true;
				else
					return false;
			}
			return true;
		}
		else if (x <= INTMIN / 10)
		{
			if (x == INTMIN / 10)
			{
				if (pop > 8)
					return true;
				else
					return false;
			}
		}
		return false;
	}


    int reverse(int x) {
		int x_pos = x;  // 取x的绝对值
		int posNum;  // 每一位上的数字
		int reverseNum = 0;  // 返回值
		int times = 10;  // 乘上的倍数
		if (x < 0)
		{
			if (x <= -2147483648)
				return 0;
			else
				x_pos = -x;
		}
		if (x == 0)
			return 0;
		for(;;x_pos /= 10)
		{
			if (x_pos >= 10)
			{
				posNum = x_pos % 10;	
				if (isOverFlow(reverseNum, posNum))
				{
					cout << "over reverseNum: " << reverseNum << endl;
					return 0;
				}
				reverseNum *= times;
				reverseNum += posNum;
				cout << "reverseNum: " << reverseNum << endl;
			}
			else
			{
				posNum = x_pos;
				if (isOverFlow(reverseNum, posNum))
				{
					cout << "over reverseNum: " << reverseNum << endl;
					return 0;
				}
				reverseNum *= times;
				reverseNum += posNum;
				cout << "reverseNum: " << reverseNum << endl;
				break;
			}
		}
		if (x < 0)
			reverseNum = -reverseNum;
		return reverseNum;
    }
};


int main()
{
	int a = -1463847412;
	Solution s = Solution();
	cout << s.reverse(a) << endl;
	return 0;
}
