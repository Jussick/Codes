//C++ file
/***********************************************
#
#      Filename: 28-字符串的排列.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 输入一个字符串，输出它所有的排列结果
#        Create: 2018-12-17 11:02:45
#**********************************************/
#include<iostream>
#include<cstring>


using namespace std;


/* 交换一个字符串中两个字符的位置 */
void swap(char *pchar1, char *pchar2)
{
	char temp = *pchar1;
	*pchar1 = *pchar2;
	*pchar2 = temp;
}

void permutation(char *pStr, char *pBegin)
{
	if (*pBegin == '\0')
	{
		cout << pStr << endl;
	}
	else
	{
		for (char *pCh = pBegin; *pCh != '\0'; pCh++)
		{
			swap(pCh, pBegin);

			cout << "当前pCh：" << *pCh << "\t" << "当前pBegin：" << *pBegin << endl;

			permutation(pStr, pBegin + 1);

			swap(pCh, pBegin);
		}
	}
}

void Permutation(char *pStr)
{
	if (pStr == NULL)
		return;
	permutation(pStr, pStr);
}



int main()
{
	char *str = new char[20];
	strcpy(str, "abc");
	Permutation(str);
	delete [] str;

	return 0;
}
