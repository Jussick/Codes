//C++ file
/***********************************************
#
#      Filename: 22-栈的压入和弹出序列.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: jianzhioffer第22题，根据一个栈元素的压栈序列，判断一个序列是否能成为该栈的弹出序列 
				思路：如果下一个弹出的元素刚好是栈顶元素，就直接弹出；
					  如果不是，就向辅助栈中压入压栈序列中的元素，直到把下一个需要弹出的数字压入栈中为止；
					  如果所有压栈序列的元素都压入了辅助栈，仍没有找到下一个弹出的数字，那么该序列就不可能是一个弹出序列。
#        Create: 2018-12-07 10:51:39
#**********************************************/
#include<iostream>
#include<stack>

using namespace std;

bool IsPopOrder(const int *pPush, const int *pPop, int length)
{
	bool isPossible = false;

	if (pPush != NULL && pPop != NULL && length > 0)
	{
		const int *pPushNext = pPush, *pPopNext = pPop;
		stack<int> stackData;

		while (pPopNext - pPop < length)  // 以出栈队列为是否空作为循环终止条件
		{
			while (stackData.empty() || stackData.top() != *pPopNext)  // 找到入栈元素个出栈元素相等的地方
			{
				if (pPushNext - pPush == length)
					break;
				stackData.push(*pPushNext);
				pPushNext ++;
			}
			if (stackData.top() != *pPopNext)  // 排除所有压栈完成，却没有遇到出入栈元素相等的情况
				break;
			stackData.pop();
			pPopNext ++;
		}

	if (pPopNext - pPop == length && stackData.empty())
		isPossible = true;
	}

	return isPossible;
}


int main()
{
	int pushOrder[5] = {1,2,3,4,5};
	int popOrder[5] = {4,5,3,1,2};
	if (IsPopOrder(pushOrder, popOrder, 5))
		cout << "Yes, It's a possible pop order." << endl;
	else
		cout << "No, It cannot be a possible pop order." << endl;

	return 0;
}
