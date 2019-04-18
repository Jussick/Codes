//C file
/***********************************************
#
#      Filename: 02-只知道睡的子进程.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-04-16 10:35:46
#**********************************************/
#include <stdio.h>
#include <unistd.h>

int main() {
	while (1) {
		sleep(1);
	}
	return 1;
}


