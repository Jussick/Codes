//C++ file
/***********************************************
#
#      Filename: cinNcoutTest.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-29 09:56:11
#**********************************************/
#include <iostream>
using namespace std;

/* 一个简单的输入一行数据，并输出的例子(运用cin.get()方法) */
void input_and_output()
{
	int ct = 0;
	char ch;
	cout << "Input something: " << endl;
	cin.get(ch);
	while (ch != '\n')
	{
		cout << ch;
		++ct;
		cin.get(ch);
	}
	cout << endl << ct << " charectors in total." << endl;
}
/* 两种cin方法的区别 */
void diffBetweenTwoCinWays()
{
	char c1, c2, c3;
	cout << "cin>>c1, c2, c3" << endl;
	cin >> c1 >> c2 >> c3;
	cout << "c1:" << c1 << endl;
	cout << "c2:" << c2 << endl;
	cout << "c3:" << c3 << endl;

	cin.ignore(255, '\n');  // 读取并丢弃接下来输入的255个字符或直到达到第一个换行符
							// 这里如果不加，会把上面的换行符或多余字符捕捉作为c4-6的值，可尝试去掉后的效果
	char c4, c5, c6;
	cout << "cin.get(c1, c2, c3)" << endl;
	cin.get(c4).get(c5).get(c6);
	cout << "c4:" << c4 << endl;
	cout << "c5:" << c5 << endl;
	cout << "c6:" << c6 << endl;
}

/* get和getline读取字符串时自定义分界符 */
const int limit = 255;
void customizeDelimeter()
{
	char line[limit];
	cout << "Input for getline test<# to end>" << endl;
	cin.getline(line, limit, '#');  // 把结束符自定义为#，此时输入换行符不会导致输入结束
	cout << "here is what you input:" << endl;
	cout << line << endl;
}

/* 输出输入的内容，直到读取到symbol(输出symbol前的内容) */
#define method1 0  // 1为方法一，0为方法二
void outputUntilMet(char symbol)
{
#if method1
	cout << "get then putback" << endl;
	char ch;
	while(cin.get(ch))
	{
		if (ch != symbol)
			cout << ch;
		else
		{
			cin.putback(ch);
			break;
		}
	}
	cout << endl;
#else  // method2
	cout << "use peek" << endl;
	char ch;
	while (cin.peek() != symbol)
	{
		ch = cin.get();	
		cout << ch;
	}
	cout << endl;
#endif
}

void eatline()
{
	while (cin.get() != '\n') continue;
}

int main()
{
	diffBetweenTwoCinWays();
	//customizeDelimeter();
	//outputUntilMet('.');
	//cout << "test for eatline<enter to end>" << endl;
	//eatline();
	return 0;
}
