//C file
/***********************************************
#
#      Filename: 02-有关内存的思考.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-04-09 10:45:25
#**********************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GetMemory1(char *p) {
	p = (char *)malloc(100);

}


void Test1() {
	char *str = NULL;
	GetMemory1(str);
	strcpy(str, "hello");
	printf("str: %s\n", str);

}

char *GetMemory2(void) {
	char p[] = "hello, world";
	return p;
}

void Test2() {
	char *str = NULL;
	str = GetMemory2();
	printf("str:%s\n", str);
}

int main() {
	Test2();
}
