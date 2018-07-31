#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define LINE_SIZE 256

using namespace std;

template <typename NumType> 
int printArr(NumType *arr, int len)
{
   	int i;
    if (len == 0) return -1;
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

int main()
{
	char *str = "dsada443dsada";
	printf("result:%d\n", StringFind(str, "8888"));
	return 0;
}

