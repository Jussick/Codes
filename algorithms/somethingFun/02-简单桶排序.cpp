//C++ file
/***********************************************
#
#      Filename: 02-桶排序.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-01-03 15:07:32
#**********************************************/
#include<iostream>

using namespace std;


int main()
{
	int book[1001], i, j, t;

	// 初始化桶中每个值为0
	for (i = 0; i < 1001; ++i)
		book[i] = 0;

	// 循环读入5个数字, 并在桶的相应位置记录, 记录的内容是数组下标表示的数字出现的次数
	for (i = 0; i < 5; ++i)
	{
		scanf("%d", &t);
		book[t]++;	
	}

	// 输出桶中的内容
	for (i = 0; i < 1001; ++i)
	{
		for (j = 1; j <= book[i]; ++j)
			cout << i << " ";
	}
	cout << endl;

	return 0;
}
