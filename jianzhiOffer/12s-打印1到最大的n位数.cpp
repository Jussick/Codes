//C++ file
/***********************************************
#
#      Filename: 12-打印1到最大的n位数.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 这是一个大数问题，要用字符串解决
#        Create: 2018-09-20 18:53:08
#**********************************************/
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<cstdio>

using namespace std;

bool increment(char *number)
{
	bool isOverFlow = false;
	bool nTakeOver = 0;
	int length = strlen(number);
	for (int i = length - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;	
		if (i == length - 1)
			nSum ++;
		if (nSum >= 10)
		{
			if (i == 0)
				isOverFlow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverFlow;
}

void printNum(char *number)
{
	int length = strlen(number);		
	int pos = 0;
	for (int i = 0; i < length; ++i)
	{
		if (number[i] != '0')
		{
			pos = i;	
			break;
		}
	}
	char *temp = new char(length + 1);
	memset(temp, '\0', length + 1);
	sprintf(temp, "%s", number + pos);
	cout << temp << endl;
	delete temp;
}

void PrintToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!increment(number))
	{
		printNum(number);
	}
	delete []number;
}

int main()
{
	PrintToMaxOfNDigits(3);
	return 0;	
}
