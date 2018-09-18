#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

#define CMDTOKEN "#*SSOConFigure:"

typedef struct HappyForYCMsuccess
{
	char *YooHoo;
	char *emotion;
	int howHard;
}AHa;

typedef struct account{
    int id;
    char *name;
    int level;
}Account;

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

int main6()
{
	printf("file:%s func:%s line:%d\n", __FILE__, __func__, __LINE__);
	pid_t pid;
	int fd[2];
	char line[64] = {0};
	
	pipe(fd);
	if ( (pid = fork()) > 0)
	{
		close(fd[0]);
		strcpy(line, "Hello Edward!\n");
		write(fd[1], line, strlen(line));
	}
	else if (pid == 0)
	{
		close(fd[1]);
		char buf[64];
		memset(buf, 0, sizeof(buf));
		read(fd[0], buf, sizeof(buf));
		write(STDOUT_FILENO, buf, strlen(buf));
	}
	int status;
	waitpid(pid, &status, 0);
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

typedef int *pint;
int main(int argc, char *argv[])
{
	pint a;
	int aa = 0;
	a = &aa;
	cout << "aa is " << *a << endl;
	return 0;
}
