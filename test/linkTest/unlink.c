#include<stdio.h>
#include<unistd.h>
/* 测试有文件链接的文件能否被unlink */
int main()
{
	if (unlink("testln") != 0)
		printf("error unlink hardlink\n");
	else
		printf("unlink hardlink success!\n");

	if (remove("testSln") != 0)
		printf("error removed softlink\n");
	else
		printf("removed softlink success!\n");


	return 0;
}
