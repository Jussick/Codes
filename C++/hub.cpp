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
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <memory>
#include <set>
#include <map>
#include <valarray>
#include <cstdlib>  // for exit()
#include <cstdio>   // for tmpnam()
#include <cstring>
#include <vector>
#include <sstream>
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
	auto pd = sss.begin();
	for (auto x: sss) cout << x << " ";
	cout << endl;
	for (int i = 0; pd != sss.end(); pd++, i++)
	{
		ar[i] = *pd;	
	}
	return sss.size();
}

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

/* 输出文件内容 */
void showContentOfFile(const char *filename)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		fin.clear();
		cout << "open file " << filename << " failed!" << endl;
		exit(-1);
	}
	cout << "The content of file " << filename << ':' << endl;
	char ch;
	while (fin.get(ch))
		cout << ch;
	fin.close();
}

/* 往文件里写内容 */
void wirteContentIntoFile(const char *filename)
{
	ofstream fout;
	fout.open(filename, ios::app | ios::out);   // 追加方式打开
	string content;
	cout << "Input the content that you want to write into:" << endl;
	while (getline(cin ,content) && content.size() > 0)
	{
		fout << content << endl;
		cout << "Input the content that you want to write into:" << endl;
	}
	fout.close();
}

/* 生成随机文件名 */
void generateRandomFilenames()
{
	cout <<	"This system can generate up to " << TMP_MAX
		 << " temporary names of up to " << L_tmpnam
		 << " charectors." << endl;
	cout << "Here are 10 random temp filenames: " << endl;
	//char tmpname[L_tmpnam] = {'\0'};
	char tmpname[L_tmpnam] = "testXXXXXX";  // 传入参数template至少留后6位X, 用于文件名的唯一性
	for (int i = 0; i < 10; i++)
	{
		//tmpnam(tmpname);	
		int fd = mkstemp(tmpname);
		cout << i << ": " << setw(L_tmpnam) << tmpname << endl; 
		strcpy(tmpname, "testXXXXXX"); 
	}
}

/* 获取文件的md5校验值 */
#define MD5LEN  32
#define MD5_FILE "md5.txt"
string GetMD5(string filePath)
{
    char cmd[128] = {0};
    sprintf(cmd, "%s%s%s%s", "md5sum ", filePath.c_str(), " > ", MD5_FILE);  // mac上默认无此命令
    system(cmd);

    ifstream fin;
    fin.open("md5.txt");
    char md5_value[256] = {0};
    fin.getline(md5_value, MD5LEN + 1);
    fin.close();
    remove(MD5_FILE);

    return string(md5_value);
}

//从文件读入到string里
string readFileIntoString(const char * filename)
{
    ifstream ifile(filename);
    //将文件读入到ostringstream对象buf中
    ostringstream buf;
    char ch;
    while(buf&&ifile.get(ch))
    buf.put(ch);
    //返回与流对象buf关联的字符串
    return buf.str();
}

string ReadPicture2String(const char* filename)
{
    ifstream fin(filename, ios_base::binary);
    // 读取文件大小
    fin.seekg(0, ios::end);
    int length = fin.tellg();
    fin.seekg(0, ios::beg);
    // 开辟内存空间
    char *buffer = new char[length];
    fin.read(buffer, length);

    return std::move(string(buffer, length));
}

/**
 * 功能：格式化字符串
 * 参数：
 *  @pszFmt，格式描述
 *  @...，不定参数
 * 返回值：格式化的结果字符串
 */
std::string format(const char *fmt, ...)
{
	int old_size = strlen(fmt);
	std::unique_ptr<char[]> buf(new char[old_size]);  // 相当于char *buf = new char[oldsize];
	va_list ap;
     
	va_start(ap, fmt);
	int new_size = vsnprintf(buf.get(), old_size, fmt, ap);  // 返回了ap中所有字符或数字按照format中的格式化加一起的长度，即要格式化输出的总长度
	va_end(ap);
	if (new_size < 0)
		return "";
 
	buf.reset(new char[new_size + 1]);
	va_start(ap, fmt);
	new_size = vsnprintf(buf.get(), new_size + 1, fmt, ap);
	va_end(ap);
	if (new_size < 0)
		return "";
 
	return std::string(buf.get());
}

/* ----------------------------------------------------------------------- */

// 给double保留n位小数 (方法一，stringstream转换法，返回string)
string ReserverPercisionTo(double num, int reserve/*要保留的位数*/)  // 保留n位小数
{
    stringstream ss;
    ss.setf(ios::fixed);
    ss.precision(reserve);
    ss << num;
    return ss.str();
}
// 给double保留n位小数 (方法二，数学计算法, 返回double)
double ReserverPercisionTo_2(double num, int reserve)
{
    return floor(num * pow(10,reserve)) / pow(10,reserve);
}

/* ----------------------------------------------------------------------- */

/***********************************************
#      函数名称: GetDateAndTime
#
#   Description: 获取当前的年月日时分秒  yyyy-mm-dd hh:mm:ss
#     parameter: void
#   returnValue: string
#        Author: luhg
#        Create: 2021-03-19 11:23:44
#**********************************************/
std::string GetDateAndTime()
{
    time_t nowtime;
    struct tm nowtm;
    
    time(&nowtime);
    localtime_r(&nowtime, &nowtm);

    char date[256];
    memset(date, 0, sizeof(date));
    sprintf(date, "%d-%d-%d %d:%d:%d", nowtm.tm_year+1900, nowtm.tm_mon+1, nowtm.tm_mday, nowtm.tm_hour, nowtm.tm_min, nowtm.tm_sec);

    return std::move(std::string(date));
}

/**
 * @name: GetLocalTimeWithMs
 * @msg: 获取本地时间，精确到毫秒
 * @param {type} 
 * @return: string字符串，格式为YYYYMMDDHHMMSSsss，如：20190710130510368
 */
static string GetLocalTimeWithMs(void)
{
    string defaultTime = "19700101000000000";
    try
    {
        struct timeval curTime;
        gettimeofday(&curTime, NULL);
        int milli = curTime.tv_usec / 1000;

        char buffer[80] = {0};
        struct tm nowTime;
        localtime_r(&curTime.tv_sec, &nowTime);//把得到的值存入临时分配的内存中，线程安全
        strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", &nowTime);

        char currentTime[84] = {0};
        snprintf(currentTime, sizeof(currentTime), "%s%03d", buffer, milli);

        return currentTime;
    }
    catch(const std::exception& e)
    {
        return defaultTime;
    }
    catch (...)
    {
        return defaultTime;
    }
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
	/* 7 */
	//input_and_output();
	
	/* 8 */
	//const char *file = "./things/testfile";
	//wirteContentIntoFile(file);
	//showContentOfFile(file);
	
	/* 9 */
	// generateRandomFilenames();
    
    /* 10 */
    // string res = GetMD5("./06-stringTest.cpp");
    // cout << res << endl;

    /* 11 */
    // string content = readFileIntoString("./README.txt");
    // cout << content << endl;
    
    string picdata = ReadPicture2String("./me.jpg");
    ofstream fout("./output.jpg");
    fout << picdata;

    string str = format("%d-%d-%d", 2021, 1, 2);
    cout << str << endl;

	return 0;
}
