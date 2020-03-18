#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#define LINE_SIZE 256
#define myprint(fmt, ...) printf("[%s]--%d: " fmt ,  __func__, __LINE__, ##__VA_ARGS__)

using namespace std;

// 递归方法从1加到n
int add1Ton_recursive(int n)  // recursive way
{
	return n <= 0?0:n + add1Ton_recursive(n - 1);
}

template <typename NumType> 
void printArr(NumType *arr, int len)
{
   	int i;
    if (len == 0) return;
    for (i = 0; i < len; i++)
    {
		cout << arr[i] << " ";
        if (i == len-1) cout << endl;
    }
}
template <class T> 
T swap(T *a, T *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void backward(int *arr, int pos, int len)  // 从pos位置整体后移
{
    printf("enter backward\n");
    int i;
    for (i = len; i > pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = 0;
}
// 幂运算
int power(int num, int powNum)
{
    int n = 1;
    int result = 1;
    while(n<=powNum){
        result *= num;
        n++;
    }
    return result;
}
bool equal(double num1, double num2)  // 判断两小数是否相等要看两数绝对值只差是否小于某数
{
	if (num1 - num2 < 0.0000001 
			&& num1 - num2 > -0.0000001)
		return true;
	else
		return false;
}
int GenerateRandomNum()
{
    int randomNum = 0;
    int tem = 0;
    int n;
    srand(time(0));
    for(n=0; n<4; n++){
        tem = rand() % 10;
        randomNum += tem * power(10, n);
    }
    return randomNum;
}
// 函数功能：把字符串通过token分割，保存到数组里
void str2array(char *str, int *arr, char *token)
{
	int i = 0;
	char *save = NULL;
	char *p = strtok_r(str, token, &save);
	while (p != NULL)
	{
		arr[i++] = atoi(p);
		p = strtok_r(save, token, &save);
	}
}
void redirection() /* 把输出重定向，再恢复重定向 */
{
	int fd = open("./hahaha", O_RDWR | O_CREAT, 0600);
    int copy_out = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);
    system("pwd");
    lseek(fd, 0, SEEK_SET);

    char buf[1000] = {0};
    read(fd, buf, sizeof(buf));
    printf("buf=%s\n", buf);
    close(fd);

    dup2(copy_out, STDOUT_FILENO);		
}
/***********************************************
#
#      函数功能: 插入排序
#
#   Description: arr--数组首地址, len--数组长度
				假定左边已经排好序，从右边选数字，插入在左边合适的位置。
#        Create: 2018-06-27 10:53:13
#**********************************************/
int *insertSort(int *arr, int len)
{
    int i,j;
    int *returnArr = (int *)malloc(len*sizeof(int));
    int returnLen = 0;
    for (i = 0; i < len; i++)
    {
        printf("i=%d\treturnLen=%d\n", i, returnLen);
        printArr(returnArr, returnLen);
        if (i == 0)
        {
            returnArr[i] = arr[i];
            returnLen++;
            continue;
        }
        for (j = 0; j < returnLen; j++)
        {
            if (arr[i] < returnArr[j])  // find appropriate position and insert, then backwards others.
            {
                backward(returnArr, j, returnLen);
                returnArr[j] = arr[i];
                returnLen++;
                break;
            }
            if (j == returnLen-1)
            {
                returnArr[j+1] = arr[i];
                returnLen++;
                break;
            }

        }
    }
    return returnArr;
}

/***********************************************
#
#      函数功能: 选择排序
#
#   Description: 自左至右选择最小的值，依次放到后面。
#        Create: 2018-06-27 14:18:33
#**********************************************/
void selectSort(int *arr, int len) /* 选择排序 */
{
    int i,j;

    for (j = 0; j < len; j++)
    {
        int min = arr[j];
        for(i = j; i < len; i++)
        {
            if (min > arr[i])  // find minimum and exchange
            {
                min = arr[i];
                swap(&arr[i], &arr[j]);
            }

        }
        arr[j] = min;
    }

}


template <typename NumType>
void BubbleSort(NumType *arr, int arrSize) /* 冒泡 */
{
	int i, j;	
	for (i = 0; i < arrSize-1; i++)
	{
		for (j = 0; j < arrSize-i-1; j++)
		{
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);

		}
	}
}


/***********************************************
#      函数名称: quickSort
#
#   Description: 快速排序
				快速排序的每一轮处理其实就是将这一轮的基准数归位，直到所有的数都归位为止，排序就结束了。
#     parameter: left: 左哨兵，right: 右哨兵
#   returnValue: null
#   	 Author: luhg
#        Create: 2019-01-03 17:10:31
#**********************************************/
int a[101],n;//定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left,int right)
{
	int i,j;
	int base;
	if(left > right)
		return;

	base = a[left];  // base中存的就是基准数
	// i和j是两边的哨兵
	i = left;
	j = right;
	while(i != j)
	{
		//顺序很重要，要先从右边开始找，找比基准数小的
		while(a[j]>=base && i<j)
			j--;
		//再找左边的，找比基准数大的
		while(a[i]<=base && i<j)
			i++;
		//交换两个数在数组中的位置
		if(i<j)
		{
			swap(a[i], a[j]);
		}
	}
	//最终将基准数归位
	swap(a[i], a[left]);

	quicksort(left,i-1);//继续处理左边的，这里是一个递归的过程
	quicksort(i+1,right);//继续处理右边的 ，这里是一个递归的过程
}
void quicksortTest()
{
	int i;
	//读入数据
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	quicksort(1,n); //快速排序调用

	//输出排序后的结果
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	getchar();getchar();
}


/***********************************************
#      函数名称: radixsort 
#
#   Description: 基数排序
#     parameter: 数组地址和长度
#   returnValue: 无，直接在函数内修改数组内容
#   	 Author: luhg
#        Create: 2018-11-23 14:43:34
#**********************************************/
int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0];		///< 最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        //p *= 10; // Maybe overflow
        maxData /= 10;
        ++d;
    }
    return d;
}
void radixsort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}




/***********************************************
#
#      函数功能: 读文件特定的一行
#
#   Description: 文件名要加const限制，否则会报warning
#        Create: 2018-06-27 14:20:12
#**********************************************/
char* ReadSpeacialLine(const char* filename, int whichLine)
{
    if (whichLine < 0 || NULL == filename)
    {
        return NULL;
    }
    FILE *fp = fopen(filename, "r");
    if (NULL == fp) {
        return NULL;
    }
    int reachWhichLine = 0;
    int curLine = 1;
    char *data = NULL;
    data = (char*) malloc(LINE_SIZE);
    while (!feof(fp))//文件未结束
    {
        memset(data, 0, LINE_SIZE);
        fgets(data, LINE_SIZE - 1, fp);
        curLine++;
        if (curLine > whichLine)
        {
            reachWhichLine = 1; //已经读取到whichLine行
            break;
        }
    }
    fclose(fp);

    return 0 == reachWhichLine ? NULL : data;
}

/***********************************************
#
#      函数功能: 查看本机IP
#
#   Description: 把本机IP保存到传入参数IP中
#        Create: 2018-06-27 11:08:03
#**********************************************/
void GetLocalIP(char *IP)
{
    char *ip = (char *)calloc(1, 50);
    char *cmd = (char *)calloc(1,128);
    strcpy(cmd, "ip addr | grep inet | awk '{ print $2; }' | sed 's/\\/.*$//' >> /home/spv/log/IP.txt");
    system(cmd);
    strcpy(ip, ReadSpeacialLine("/home/spv/log/IP.txt", 3));
    snprintf(IP, strlen(ip), "%s", ip); // 去掉ip结尾的换行符
    system("rm -f /home/spv/log/IP.txt");
    free(cmd);
    free(ip);
}

//find string in string, return the first start location or -1 if can not find
int StringFind(const char *pSrc, const char *pDst)
{
	int i, j;
	for (i=0; pSrc[i]!='\0'; i++)
	{
		if(pSrc[i]!=pDst[0])
			continue;		
		j = 0;
		while(pDst[j]!='\0' && pSrc[i+j]!='\0')
		{
			j++;
			if(pDst[j]!=pSrc[i+j])
			break;
		}
		if(pDst[j]=='\0')
			return i;
	}
	return -1;
}

// 十进制转十六进制
char buffer[64] = {0};
char *inttohex(int aa)
{
    static int i = 0;
    if (aa < 16)            //递归结束条件 
    {
        if (aa < 10)        //当前数转换成字符放入字符串 
            buffer[i] = aa + '0';
        else
            buffer[i] = aa - 10 + 'A';
        buffer[i+1] = '\0'; //字符串结束标志 
    }
    else
    {
        inttohex(aa / 16);  //递归调用 
        i++;                //字符串索引+1 
        aa %= 16;           //计算当前值
        if (aa < 10)        //当前数转换成字符放入字符串 
            buffer[i] = aa + '0';
        else
            buffer[i] = aa - 10 + 'A';
    }
	return buffer;
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
	//intsrand((unsigned int)(time(NULL)));
	//intint offset = rand() % difference;
	//intcout << "offset: " << offset << endl;
	//intreturn abs(randomNum - offset) + 1;
	
	return randomNum;
	
}

int Partition(int data[], int length, int start, int end)
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)
	{
		cout << "Invalid Input" << endl;
		return -1;
	}
	int index = RandomInRange(start, end);	
	swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; ++ index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				swap(&data[index], &data[small]);
		}
	}
	++ small;
	swap(&data[small], &data[end]);
	return small;
}


#if 0
#define Power(times) power(10, times);
unsigned long long decTobinary(int dec)
{
	int remain;		// 余数
	int dv_result;  // 商
	stack<int> temp_res;
	while ((dec / 2) != 0 )	
	{
		remain = dec % 2;
		temp_res.push(remain);
		dec /= 2;
	}
	remain = dec % 2;
	temp_res.push(remain);

	int digitnum = temp_res.size();
	int cur = -1;
	long long result = 0;
	for (int i = digitnum - 1; i >= 0; --i)
	{
		cur	= temp_res.top();
		result += cur * Power(i);
		temp_res.pop();
	}
	return result; 
}
#endif

/* 十进制转二进制 (超过18446744073709551615后会出错) */
string DecToBinary(unsigned long long int dec)
{
	int remain;		// 余数
	stack<int> temp_res;
	while ((dec / 2) != 0 )	
	{
		remain = dec % 2;
		temp_res.push(remain);
		dec /= 2;
	}
	remain = dec % 2;
	temp_res.push(remain);

	string result;
	while (!temp_res.empty())
	{
		result += to_string(temp_res.top());	
		temp_res.pop();
	}
	return result;

}
void DecToBinaryTest()
{
	unsigned long long int dec;
	cout << "input one num you want to transfer into binary(0 ~ 18446744073709551615): ";
	while (cin >> dec)
	{
		cout << DecToBinary(dec) << endl;;
		cout << "input one num you want to transfer into binary(0 ~ 18446744073709551615): ";
	}
}
// 得到当前时间(time.h)
void GetCurTime(char **cur_time)
{
    const time_t t = time(NULL);
    const time_t *pt = &t;
    *cur_time = strdup(ctime(pt));
}

/* 判断系统是大端还是小端 */
void BigOrSmallEndianJudge()
{
	union
	{
		short i;
		char c[sizeof(short)];
	}uni;
	uni.i = 0x0102;  // 写成16进制为了方便直接打印内存中的值对比
	
	if (sizeof(short) == 2)
	{
		if (uni.c[0] == 1 && uni.c[1] == 2)
			printf("Big-Endian\n");
		else if (uni.c[0] == 2 && uni.c[1] == 1)
			printf("Small-Endian\n");
		else
			printf("uniknown.\n");
	}
	else
		printf("sizeof(short) is %d\n", sizeof(short));
}


int main()
{
	//DecToBinaryTest();
	//BigOrSmallEndianJudge();
	quicksortTest();
	//int arr[5] = {2,6,5,9,3};
	//radixsort(arr, 5);
	//printArr(arr, 5);
	//cout << RandomInRange(0,7) << endl;
	return 0;
}

