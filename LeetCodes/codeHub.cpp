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

template <class T> T swap(T *a, T *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
//void swap(int *a, int *b)
//{
//    *a = *a ^ *b;
//    *b = *a ^ *b;
//    *a = *a ^ *b;
//}
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
// 函数功能：把字符串通过“逗号”分割，保存到数组里
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

void BubbleSort(int *arr, int arrSize) /* 冒泡 */
{
	int i, j;	
	for (i = 0; i < arrSize-1; i++)
	{
		for (j = 0; j < arrSize-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
			}

		}
	}
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

char* ReadSpeacialLine(char* filename, int whichLine)
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
void GetLocalIP(char *IP)  // added by luhg
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

int main()
{
	int arr[10] = {1,3,2,5,6,9,7,8,4,0};
	selectSort(arr, 10);
	for (int i = 0; i < 10; i++)
		cout << "arr[" << dec << i << "]=" << arr[i]<<endl;
	return 0;
}

