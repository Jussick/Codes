//C++ file
/***********************************************
#
#      Filename: hub.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: Some C++ function hub
#        Create: 2018-08-22 10:09:43
#**********************************************/
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <memory>
#include <set>
#include <map>
#include <valarray>
using namespace std;

void show(string  a)
{
	cout << a << " ";
}

template <class T>
void showarray(T *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

/* 求一个字符串的所有排列组合 */
void permutation_string()
{
	string letter;
	cout << "Input a string, exit to quit." << endl;
	while (cin >> letter && letter != "exit")
	{
		cout << "Permutation of letters " << letter << " is:" << endl;
		// 要先把字符串排序
		sort(letter.begin(), letter.end());
		while (next_permutation(letter.begin(), letter.end()))
			cout << letter << endl;
		cout << "Input a string, exit to quit." << endl;
	}
	cout << "done." << endl;
}

/* 利用set为vector中元素去重 */
void vector_to_set()
{
	string word;
    vector<string> words;
	cout << "Input strings to fill in vector:(exit to quit)" << endl;
    while(cin>>word && word!="exit")
	{
        words.push_back(word);
		cout << "Input strings to fill in vector:(exit to quit)" << endl;
	}
    cout << "original vector:" << endl;
    for_each(words.begin(), words.end(), show);
	cout << endl;

    cout << "after copy vector into a set" << endl;
    set<string> sss(words.begin(), words.end());  // 这样相当于把vector先做sort，再做unique操作，不过那样就会修改原本的vector
    //copy(words.begin(), words.end(), sss.begin());  // 这句话会报错，为什么？
	for_each(sss.begin(), sss.end(), show);
    cout << endl;	
}


/* 输入多个字符串，输出每个字符串出现的次数 */
void count_str_times()
{
	/* 需要用到三个容器，vector，set和map
	 * vector用来保存所有字符串
	 * set用来去重
	 * map用来保存每个字符串对应的计数
	 */
	string str;
	vector<string> wordvec;
	map<string, int> wordmap;
	cout << "Input strings:(exit to quit)" << endl;
	while(cin>>str && str!="exit")  // cin输入时是会被空格隔开的，所以在输入多个字符串时无需换行
		wordvec.push_back(str);
	set<string> wordset(wordvec.begin(), wordvec.end());
	// 计数
	for (auto pd = wordset.begin(); pd != wordset.end(); pd++)
		wordmap[*pd] = count(wordvec.begin(), wordvec.end(), *pd);
	// 遍历map
	for (auto pd = wordmap.begin(); pd != wordmap.end(); pd++)
		cout << "字符串" << (*pd).first << "出现的次数: " << (*pd).second << endl;
	/* 第二种遍历方法
	for (auto pd = wordset.begin(); pd != wordset.end(); pd++)
		cout << "字符串" << (*pd)<< "出现的次数: " << wordmap[*pd] << endl;
	 */

}

/* 矩阵格式输出数组
 * 第二个参数是以几列输出
 */
typedef valarray<int> vint;
void show_array_as_metrix(const vint &v, int cols)
{
	int lim = v.size();	
	for (int i = 0; i < lim; i++)
	{
		cout.width(3);	
		cout << v[i];
		if (i % cols == cols -1)
			cout << endl;
		else
			cout << ' ';
	}
	if (lim % cols != 0)
		cout << endl;
}

/* 把string全部大写 */
string & alltoupper(string &s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = toupper(s[i]);
	return s;
}

/* 去掉数组中重复元素，并返回元素个数 */
template <class T>
int reduce(T ar[], int n)
{
	set<T> sss(ar, ar+n);
	//cout << "set:";
	//auto pd = sss.begin();
	for (auto x: sss) cout << x << " ";
	cout << endl;
	for (int i = 0; pd != sss.end(); pd++, i++)
	{
		ar[i] = *pd;	
	}
	return sss.size();
}

int main()
{
	/* 1 */
	//permutation_string();
	
	/* 2 */
	//vector_to_set();
	
	/* 3 */
	//count_str_times();	
	
	/* 4 */
#if 0
	const int MSIZE = 12;
	valarray<int> val1(MSIZE);
	for (int i = 0; i < MSIZE; i++)
		val1[i] = rand()%10;
	show_array_as_metrix(val1, 3);
	// 取矩阵第二列元素
	vint val2(val1[slice(1,4,3)]);
	show_array_as_metrix(val2, 1);
#endif

	/* 5 */
	//string str = "hello, world";
	//cout << alltoupper(str) << endl;
	
	/* 6 */
#if 0
	string arr[5] = {"aaa", "aaa", "bbb", "ccc", "ddd"};
	cout << "原始数组内容：";
	showarray(arr, 5);
	int size = reduce(arr, 5);
	cout << "after reduce:";
	showarray(arr, size);
#endif

	return 0;
}
