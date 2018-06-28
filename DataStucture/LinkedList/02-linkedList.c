#include<stdio.h>                                                                                                                    
#include<stdlib.h>                                                                                                                  
#include<string.h>
#include "list.h"
#include "list.h" // 由于在list.h中使用了条件编译，所以重复包含此头文件不会报错


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

void showItems(Item item)
{
	printf("title: %s\trating: %d\n", item.title, item.rating);
}

int main()
{
	Item item;
	List current = NULL;	
	List prev = NULL;
	List head = NULL;
	List movie;
	InitailizeList(&movie);

	printf("Input title name:<empty to finish>\n");
	while(s_gets(item.title, MSIZE) != NULL && item.title[0] != '\0')
	{
		current = (List)malloc(sizeof(Node));
		printf("Input the rating:<0-10>\n");
		scanf("%d", &item.rating);

		while(getchar() != '\n')
			continue;

		// 添加项前先判断内存是否已满
		if (ListIsFull())
		{
			fprintf(stderr, "Malloc memory failed!\n");
			break;
		}
		// 添加项到链表结尾(用方法)
		if (AddItem(item, &movie) != true)
		{
			fprintf(stderr, "Add item failed.\n");
		}

		// 添加链表项(直接)
		//if(ListIsEmpty(&head))
		//	head = current;
		//else
		//	prev->next = current;
		//current->next = NULL;

		//current->item= item;
		//prev = current;

		printf("Input title name:<empty to finish>\n");
	}

	// 打印信息(直接)
	//current = head;
	//while(current!=NULL)
	//{
	//	showItems(current->item);	
	//	current = current->next;
	//}
	
	
	// 打印信息(用方法)
	if(ListIsEmpty(&movie))
		puts("No data input!");
	else
	{
		puts("Here is the movie list:");
		Traverse(&movie, showItems);
	}
	

	// 总数
	unsigned int count = ListItemCount(&movie);
	printf("%d movies in total.\n", count);

	// 释放空间
	EmptyTheList(&movie);

	printf("Bye!\n");
	return 0;

}
