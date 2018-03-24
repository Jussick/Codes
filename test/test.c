#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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



int main()
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



