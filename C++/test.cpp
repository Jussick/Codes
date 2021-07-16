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
#include<map>
#include <memory>

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
    return 0;
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

int RandomInRange(int min, int max)
{
	cout << "min: " << min << " max: " << max << endl;
    srand((unsigned int)(time(NULL)));
    int randomNum = rand();
    cout << "randomNum: " << randomNum << endl;
    randomNum %= max;
    cout << "randomNum %= max: " << randomNum << endl;
    //int difference = max - min;
    //srand((unsigned int)(time(NULL)));
    //int offset = rand() % difference;
    //return abs(randomNum - offset) + 1;
	return randomNum;

}

template <class T>
T swap(T *a, T *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int Partition(int *arr, int length, int start, int end) {
	if (arr == NULL || length <= 0 || start < 0 || end >= length)
		return -1;

	int index = RandomInRange(start, end);
	cout << "random index is " << index << endl;
	swap(arr[index], arr[end]);

	int small = start - 1;
	for (index = start; index < end; ++index) {
		if (arr[index] < arr[end]) {
			++ small;
			if (small != index)
				swap(arr[index], arr[small]);
		}
	}
	++small;
	swap(arr[small], arr[end]);

	return small;
}

void TwoDimensionalVectorTest() {
    vector< vector<long> > temp(5);
    for (size_t s = 0; s < temp.size(); ++s) {
        temp[s].resize(5);
    }

    for (size_t i = 0; i < temp.size(); ++i) {
        for (size_t j = 0; j < temp[0].size(); ++j) {
            temp[i][j] = j;
        }
    }

    for (vector<long> v : temp) {
        for (long x : v)
            cout << x << " ";
        cout << endl;
    }
}

class Foo {
public:
    Foo(int val, initializer_list<string> il):value(val),sp(make_shared<vector<string> >(il)) { cout << "Foo " << value << " constructed !" << endl; }
    ~Foo() { cout << "Foo " << value << " destroyed..." << endl; }
    void show() { 
        cout << "This is foo " << value << endl; 
        for (size_t i = 0; i < sp->size(); ++i)
        {
            // cout << sp[i] << " "; 
        }
    }
private:
    int value;
    shared_ptr<vector<string> > sp;
};

struct foo {
    char c;
    int x;
    short cc;
};

int main()
{
	//TwoDimensionalVectorTest();
	
	// map<int, string> m_map;
	// m_map.insert(make_pair(1, "haha"));
#if 0
    Foo *pf = new Foo(1, { "123", "456", "789" });
    // shared_ptr<Foo> p1 = make_shared<Foo>(Foo(1));    
    shared_ptr<Foo> p1;
    p1.reset(pf);
    p1->show();
    shared_ptr<Foo> p2;
    cout << "p1: " << p1.use_count() << endl;
    cout << "p2: " << p2.use_count() << endl;
    p2 = p1;
    cout << "after \"p2=p1\"" << endl;
    cout << "p1: " << p1.use_count() << endl;
    cout << "p2: " << p2.use_count() << endl;

    cout << "p1.unique(): " << p1.unique() << endl;  // 判断当前shared_ptr的引用计数是否为1
    cout << "p2.unique(): " << p2.unique() << endl;  // 判断当前shared_ptr的引用计数是否为1
    p1.reset(new Foo(*p1));
    cout << "after p2.reset(), p1.unique(): " << p1.unique() << endl;
    cout << "after p2.reset(), p2.unique(): " << p1.unique() << endl;
#endif
    uint32_t x = 1;
    decltype(x++) y = 2;
    cout << x << " " << y << endl;
	return 0;
}
