#include <iostream>
#include <string>
using namespace std;

template <class T> T Max (T a, T b)
{
	return a > b?a:b;
}

int main()
{
	int a,b;
	a = 1; b = 2;
	cout << Max(a,b) << endl;

	double c,d;
	c = 3.2; d = 4.6;
	cout << Max(c,d) << endl;

	string str1,str2;
	str1 = "hello1";
	str2 = "hello2";
	cout << Max(str1,str2) << endl;


	return 0;
}
