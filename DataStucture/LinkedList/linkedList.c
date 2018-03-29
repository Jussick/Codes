#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 45

struct film{
	char title[TSIZE];
	int rating;
	struct film *next;
};
typedef struct film Film;

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

int main(void)
{
	Film *head= NULL;
	Film *prev = NULL;
	Film *current= NULL;
	char input[TSIZE];

	// 初始化链表信息
	printf("Enter the film title:<empty to finish>\n");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (Film *)malloc(sizeof(Film));
		if (head == NULL)
			head = current;
		else
			prev->next = current;

		strcpy(current->title, input);
		printf("Input the rating od this film:<0-10>\n");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;

		printf("Enter the film title:<empty to finish>\n");
		prev = current;
	}

	// 打印链表信息
	if (head == NULL)
		printf("There is nothing.\n");
	else
		printf("Here is the film infos:\n");
	current = head;
	while(current != NULL)
	{	
		printf("title:%s\trating:%d\n", current->title, current->rating);
		printf("&current:%p\n", &current);
		current = current->next;
	}

	// 释放链表内存
	current = head;
	while(current != NULL)
	{
		free(current);
		current = current->next;
	}

	printf("Bye!\n");
	return 0;
}
