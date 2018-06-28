#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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

int main()
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
