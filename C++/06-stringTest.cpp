//C++ file
/***********************************************
#
#      Filename: 06-stringTest.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-15 13:45:26
#**********************************************/
#include<iostream>
#include<string>
using namespace std;

void stringInitWays()
{
	char str[] = "Edward lucas is the God.";  // C风格字符串
	string temp("I am temp string.");		// string类字符串

	
	string one(str+7, str+13);  // 从str的第七个赋值到第13个

	string two(&temp[7], &temp[13]);

	string three(20, '$');  // 20个$

	string four(temp, 7, 13);  // 从temp的第8个字符开始，复制13和字符, 注意：temp需要是string类型

	string five(temp);

	string six = five + "Oops!";

	string seven(str, 6);  // 复制str的前多少个字符
	string seven2(str, 100);  // 超出原本长度会在后面追加无意义的字符

	cout << "one:" << one << endl;
	cout << "two:" << two << endl;
	cout << "three:" << three << endl;
	cout << "four:" << four << endl;
	cout << "five:" << five << endl;
	cout << "six:" << six << endl;
	cout << "seven:" << seven << endl;
	cout << "seven2:" << seven2 << endl;
}

int main()
{
	string name;
	string profession;
	string hobby;

	cout << "use defualt getline input name: ";
	getline(cin, name);

	cout << name.find("Edward", 0) << endl;  // 从0位置开始查找Edward出现的位置, 找不到返回string::npos, 即string对象能存储的最大字符数
	cout << "string::npos = " << string::npos << endl;

	//cout << "use cin input profession: ";
	//cin >> profession;

	//cout << "use special getline input hobby: ";
	//getline(cin, hobby, ':');

	//cout << "name:" << name << endl;
	//cout << "profession:" << profession << endl;
	//cout << "hobby:" << hobby << endl;

	return 0;
}
