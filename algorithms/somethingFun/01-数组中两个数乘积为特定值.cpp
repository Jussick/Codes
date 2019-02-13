//C++ file
/***********************************************
#
#      Filename: 01-数组中两个数乘积为特定值.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-12-19 10:08:41
#**********************************************/
#include<iostream>
#include<vector>
#define fixNum 100
using namespace std;


void initAnArray(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
		arr[i] = -1;
}

/***********************************************
#      函数名称: findPairMulToValue
#
#   Description: 找到items数组中乘积等于value的一对数字，并以数组指针形式返回
#     parameter:
			items: 传入数组
			length: 数组长度
			value: 寻找的乘积
#   returnValue:
			pair: 保存一对乘数的数组
#   	 Author: luhg
#        Create: 2018-12-19 10:23:45
#**********************************************/
int *findPairMulToValue(int *items, int length, int value)
{
	int *pair = new int[2];	 // 返回的数值对
	initAnArray(pair, 2);
	vector<int> notReady(100);  // 储存已经没有相乘结果等于value的值
	
	for (int i = 0; i < length; ++i)
	{
		if (value % items[i] != 0)  // 若不能被value整除，将其放入notready中，继续下一循环
		{
			notReady.push_back(items[i]);
			continue;
		}
		int lookfor = value / items[i];	
		for (auto iter = notReady.begin(); iter != notReady.end(); ++iter)
		{
			if (*iter == lookfor)
			{
				pair[0] = lookfor;
				pair[1] = items[i];
				break;
			}
		}
		notReady.push_back(items[i]);
	}
	return pair;
		
}

int main()
{
	int arr[10] = {3,6,4,7,5,2,1,1,1,1};
	int value = 20;
	int *res = findPairMulToValue(arr, 10, value);
	if (res[0] > 0)
		cout << res[0] << "\t" << res[1] << endl;
	else
		cout << "Not find a result pair multiple to " << value << endl;

	return 0;
}
