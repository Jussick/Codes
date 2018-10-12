//C file
/***********************************************
#
#      Filename: unionTest.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 测试union的用法，用来判定大端小端, 判定函数在codeHub.cpp中
#        Create: 2018-10-09 15:09:07
#**********************************************/
#include<stdio.h>


int main()
{
	union
	{
		short i;
		char c[2];
	}un;
	un.i = 0x0102;
	printf("un.c[0]: %d, un.c[1]: %d\n", un.c[0], un.c[1]);
	printf("address of un.i: %p\n", &un.i);  // 联合体的所有变量首地址是一样的，只不过用不同方式存储
	printf("address of un.c: %p\n", &un.c);

	char *str = (char *)&un;  // 把un的首地址强转为char类型, 说明就算是未声明的也可以用，只要有地址，想存什么都可以！
	str[0] = 'a';
	str[1] = 'b';
	str[2] = '\0';
	printf("%s\n", str);

	return 0;
}


