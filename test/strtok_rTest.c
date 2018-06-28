#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main1()
{
	char str[] = "123:456:789";
	char *save = NULL;
	char *p = strtok_r(str, ":", &save);
	printf("s = %s\n", p);
	p = strtok_r(save, ":", &save);
	printf("s = %s\n", p);
	printf("s = %s\n", save);

	return 0;
}

// 函数功能：把字符串通过“逗号”分割，保存到数组里
void str2array(char *str, int *arr)
{
	int i = 0;
	char *save = NULL;
	char *p = strtok_r(str, ",", &save);
	while (p != NULL)
	{
		arr[i++] = atoi(p);
		p = strtok_r(save, ",", &save);
	}
}
int main()
{
	int array[20] = {0};
	char str[50] = "7,8,9";
	str2array(str, array);
	int i;
	for (i = 0; array[i] != 0; i++)
	{
		printf("array[%d]=%d\n", i, array[i]);
	}
	return 0;
}
int main2()
{
	char *word[20] = {NULL};
	char *result = NULL;
	int i = 0;
	char sql[50] = "select *from union_user where id=2";	
	char *save = NULL;
	char *p = strtok_r(sql, " ", &save);
	while(p != NULL){
		printf("%s\n", p);
		word[i++] = p;
		p = strtok_r(save, " ", &save);
	}

	i = 0;
	while(word[i] != NULL){
		//printf("word[%d]=%s\n", i, word[i]);
		if (strstr(word[i], "from") != NULL)
		{
			result = word[++i];	
			break;
		}
		i++;
	}

	printf("result = %s\n", result);

	return 0;
}
