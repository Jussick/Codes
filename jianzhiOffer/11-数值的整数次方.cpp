//C++ file
/***********************************************
#
#      Filename: 11-数值的整数次方.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 要考虑到幂指数是非正数的情况, 以及基数为0的情况
				 当比较double类型值时，不能直接比较
#        Create: 2018-09-18 09:33:08
#**********************************************/
#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

bool equal(double num1, double num2)  // 判断两小数是否相等要看两数绝对值只差是否小于某数
{
	if (num1 - num2 < 0.0000001 
			&& num1 - num2 > -0.0000001)
		return true;
	else
		return false;
}

double power(double base, int exp)
{
	double result = 1.0;
	if (equal(base, 0))  // 当基数为0时，返回0或1均可
		return 0;
	if (exp == 0)		 // 幂指数为0时，特殊处理
		result = 1.0;
	else 
	{
		for (int i = 1; i <= abs(exp); ++i)  // 注意指数为负数时要取绝对值
		{
			result *= base;
			if (exp < 0 && i == abs(exp))
			{
				result = 1 / result;
			}
		}
	}
	return result;
}

int main()
{
	//cout.setf(ios::fixed);
	cout << power(-10, 3) << endl;
	cout << power(10, 0) << endl;
	cout << power(10, -1) << endl;
	cout << power(23, -4) << endl;
	cout << power(0, 100) << endl;
	cout << power(3, 100) << endl;
	return 0;
}
