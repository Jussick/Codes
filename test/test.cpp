#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

#define CMDTOKEN "#*SSOConFigure:"
typedef void (*func) (int);

typedef struct HappyForYCMsuccess
{
	char *YooHoo;
	char *emotion;
	int howHard;
}AHa;

struct Account{
	int id;
	char *name;
	int level;
};

typedef enum {
	one,
	two,
	three = 1
}testenum;

int main3()
{
	char str[50] = "dsadsa";
	char str2[50];
	sprintf(str2, "%s%s%s", "\"", str, "\"");
	printf("str2 is %s\n", str2);
	printf("str is %s\n", str);
	return 0;	
}



int main2()
{
	AHa haha;
	haha.YooHoo = (char *)calloc(1,128);
	strcpy(haha.YooHoo, "dsa");
	printf("%s\n", haha.YooHoo);
	free(haha.YooHoo);
	return 0;

}


int main1()
{
	Account *acc = (Account *)calloc(3, sizeof(Account));	
	int i;
	for (i=0; i<=2; i++)
	{
		acc[i].id = i;
		printf("acc[%d].id = %d\n", i, acc[i].id);
	}
	for (i=0; i<3; i++)
	{
		(acc+i)->id = i;
		printf("(acc+%d)->id = %d\n", i, (acc+i)->id);
	}

	return 0;
}

char result[32];
int main4()
{
	char line[100];
	strcpy(line, "#*SSOConFigure:En*");
	int i = 0;
	char *token = NULL;
	for (; line[i] != '\0'; ++i)
	{
		if (!strncmp(line+i, CMDTOKEN, strlen(CMDTOKEN)))
		{
			i += strlen(CMDTOKEN);
			token = strdup(line+i);	
			*strchr(token, '*') = 0;
		}
	}
	printf("token = %s\n", token);

	return 0;
}

int main5()
{
	pid_t pid;
	int status;
	if ((pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
	{
		sleep(2);
		printf("this is child, pid=%d\n", getpid());
		exit(22);
	}
	else
	{
		printf("this is parent, waitpid=%d\n", pid);
		if (waitpid(pid, &status, WNOHANG) == 0)
		{
			printf("no hang haha\n");	
			wait(&status);
		}

		printf("subproc exitStatus:%d\n", WEXITSTATUS(status));
	}
	return 0;
}


int sscanfTest()
{
	char a[256] , b[256], c[256];
	char *str = "aaa bbb ccc";
	sscanf(str, "%s %s %s", a, b, c);
	printf("%s %s %s\n", a, b, c);

	return 0;
}


enum encType { SM4 = 1, DES };

void enumTest()
{
	printf("input the enc type you want to select:\n");	
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
		case SM4:
			printf("you chose SM4\n");
			break;
		case DES:
			printf("you chose 3DES\n");
			break;
	}
}

int add1Ton_recursive(int n)  // recursive way
{
	return n <= 0?0:n + add1Ton_recursive(n - 1);
}
int add1Ton_normal(int n)  // loop way
{
	int i, result = 0;
	for (i = 1; i <= n; ++i)
	{
		result += i;	
	}
	return result;
}

int numOf1(int n)
{
	int count = 0;	
	while (n)
	{
		//cout << bitset<4>(n) << endl;
		if (n & 1)
			count ++;
		n = n >> 1;
	}
	return count;
}
bool increment(char *number)
{
	bool isOverFlow = false;
	bool nTakeOver = 0;
	int length = strlen(number);
	for (int i = length - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;	
		if (i == length - 1)
			nSum ++;
		if (nSum >= 10)
		{
			if (i == 0)
				isOverFlow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverFlow;
}

void changeAString(char *theOne)
{
	theOne[0] = 'a';
	theOne[1] = 'a';
}

int main6(int argc, char *argv[])
{
#if 0
	char *number = new char(5);
	memset(number, '0', 4);
	number[4] = '\0';
	for (int i = 0; i < 10; ++i)
	{
		increment(number);
		cout << number << endl;
	}
#endif
#if 0
	char *testString = new char(10);
	strcpy(testString, "Edawrd");
	cout << testString << endl;
	changeAString(testString);
	cout << testString << endl;
	delete []testString;
	return 0;
#endif
	int i;
	char *msg;
	pid_t pid = fork();

	if (pid < 0)
		printf("fork error\n");
	else if (pid == 0)
		msg = "child handle";
	else
	{
		msg = "parent handle";
		sleep(1);
	}

	for (i = 0; i < 5; ++i)
	{
		printf("%s\n", msg);
		sleep(1);
	}
	exit(0);
}

void alarmTest()
{
	int counter;
	alarm(1);

	for (counter = 0; 1; counter++)
		printf("%d\n", counter);
}

typedef struct haha{
	char hsmip[64];     // 加密机端口
	unsigned int port;  // 加密机IP
}HSMInfo;

void handle(int sig)
{
	char buf[1024] = {0};
	sprintf(buf, "ohohoh, recived a signal: %d\n", sig);
	(void)signal(SIGKILL, SIG_DFL);
	exit(0);
}

// 得到当前时间
void GetCurTime(char **cur_time)
{
	const time_t t = time(NULL);
	const time_t *pt = &t;
	*cur_time = strdup(ctime(pt));
}

char *getFileContent(const char *file)
{
    int i=0;
    char ch;
    char *out = (char *)malloc(1000);
    FILE *fp = fopen(file,"r");
    while((ch=getc(fp))!=EOF)
    {
        out[i] = ch;
        i+=1;
    }
    fclose(fp);
    return out;
}

void printSth(int num) {
	cout << "It's gonna be a good day. +" << num << endl;
}

bool myComparision(string &str1, string &str2)
{
    char tem1, tem2;
    tem1 = toupper(str1[0]);
    tem2 = toupper(str2[0]);

    return (tem1 < tem2);
}

void giveVal2Acc(Account &acc)
{
    acc.id = 1;

    acc.level = 5;

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


int main()
{
    unsigned char str[3] = {0x48, 0x49, 0x4A};
    // cout << str << endl;
    char realStr[7] = {52, 56, 52, 57, 52, 65};
    cout << realStr << endl;

    unsigned char uc = 0x48;
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (uc & (1 << i))
            sum += power(2, i);
    }
    cout << hex << sum << endl;
	return 0;
}
