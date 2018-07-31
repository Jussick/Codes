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


int main1()
{
	vector<int> arr; 
	vector<double> arr1; 
	for (int i = 0; i < 5; i++) arr.push_back(i);
	for (int i = 0; i < 5; i++) arr1.push_back(i+0.5);
	cout << "max in arr<int> is:" << Max(arr) << endl;
	cout << "max in arr1<double> is:" << Max(arr) << endl;
}

int main()
{
}
