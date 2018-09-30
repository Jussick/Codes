#ifndef _SHARED_H
#define _SHARED_H
#include<stdio.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

#define MAPLEN 0x1000

typedef struct {
	int id;
	char sex;
	char name[20];
}STU;

void sysErr(const char *prompt, int exit_num)
{
	perror(prompt);
	exit(exit_num);
}
#endif
