//C++ file
/***********************************************
#
#      Filename: 01-sizeof一些东西.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-04-08 22:32:15
#**********************************************/
#include <iostream>

using namespace std;

char str1[] = "hello";
char str2[10] = "hello";
char *p1 = "hello";
char *p2[] = {"hello", "world"};

class c1 {
public:
	short x_;
	short y_;
	short z_;

};

class c2 {
public:
	char x_;
	int y_;
	bool z_;
};


int main() {
	cout << "sizeof(str1): " << sizeof(str1) << endl;	// 6
	cout << "sizeof(str2): " << sizeof(str2) << endl;	// 10
	cout << "sizeof(p1): " << sizeof(p1) << endl;	// 8
	cout << "sizeof(p2): " << sizeof(p2) << endl;	// 16
	cout << "sizeof(\"hello\"): " << sizeof("hello") << endl;  // 6
	cout << "sizeof(c1): " << sizeof(c1) << endl;	// 6
	cout << "sizeof(c2): " << sizeof(c2) << endl;	// 12
	cout << "sizeof(int): " << sizeof(int) << endl;  // 4
	cout << "sizeof(char): " << sizeof(char) << endl;  // 1
	cout << "sizeof(short): " << sizeof(short) << endl;  // 2
	cout << "sizeof(bool): " << sizeof(bool) << endl;  // 1

	return 0;
}
