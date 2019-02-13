//C++ file
/***********************************************
#
#      Filename: test.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-06-29 09:41:09
#**********************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<exception>
#include<new>
#include<fstream>
#include<cstring>
#include<cctype>
#include<unistd.h>
#include<iomanip>
#include<bitset>

using namespace std;

struct CandyBar{
	string name;
	double weight;
	int heat;
};

void setMember(CandyBar &bar, const char *str = "Millennium", double wei = 2.85, int caloris = 350)
{
	bar.name = str;
	bar.weight = wei;
	bar.heat = caloris;
}

void showMembers(const CandyBar &bar)
{
	cout << "bar.name:" << bar.name << endl;
	cout << "bar.weight:" << bar.weight << endl;;
	cout << "bar.heat:" << bar.heat << endl;;
}
int cube(int &num)
{
	num *= num * num;
	return num;
}

void printStr(const string &str, int n = 0)
{
	cout << "This is " << n << "times" << endl;
	if (n > 0)
		printStr(str, n-1);
	cout << str << endl;
}
void toUpper()
{
	string str;
	while (1)
	{
		cout << "Enter a string (q to quit)" << endl;	
		cin >> str; 
		if (str == "q")
		{
			cout << "Bye!" << endl;
			break;
		}
		else
		{
			transform(str.begin(), str.end(), str.begin(), ::toupper);
			cout << "after transform:" << str << endl;
		}
	}
}
template <class T>
T Max(vector<T> arr)
{
	T max = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

bool newcustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);	
}

void coutTest()
{
	cout << "one";
	cout.put(32);  // 相当于输出一个空格，因为空格的ASCII码为32
	cout << "two" << endl;
	const char *s1 = "abcde";
	const char *s2 = "edward";
	cout.write(s1, 5) << endl;
	cout.write(s1, 11) << endl;
}

int main1()
{
	vector<int> arr; 
	vector<double> arr1; 
	for (int i = 0; i < 5; i++) arr.push_back(i);
	for (int i = 0; i < 5; i++) arr1.push_back(i+0.5);
	cout << "max in arr<int> is:" << Max(arr) << endl;
	cout << "max in arr1<double> is:" << Max(arr) << endl;
	//int i = 0;
	//while (i < 100) {
	//	cout << rand() << endl;
	//	if (newcustomer(6))
	//		cout << "new one come!" << endl;
	//	else
	//		cout << "no one!" << endl;
	//	i++;
	//}
}

typedef struct {
	char name[10];
	int sex;
}ttt;

bool canDivBy3(int num) {
	return num % 3 == 0?true:false;
}

template <class T>
void printVec(vector<T> &vec) {
	for (T item : vec)
		cout << item << " ";
	cout << endl;
}

int main()
{
	vector<int> vec(7);
	int arr[10] = {1,2,3,4,5,6,7};
	copy(arr, arr + 7, vec.begin());
	printVec(vec);
	//auto iter = find(vec.begin(), vec.end(), 2);
	//cout << "*iter:" << *iter << endl;
	vector<int>::reverse_iterator iter1 = find_if(vec.rbegin(), vec.rend(), canDivBy3);
	cout << "*iter1:" << *iter1 << endl;
	vector<int>::iterator iter2 = iter1.base();
	cout << "*iter2:" << *iter2 << endl;
	vec.erase(iter1.base(), vec.end());
	printVec(vec);

	return 0;
}
