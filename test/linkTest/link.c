#include<stdio.h>
#include<unistd.h>

int main()
{
	char *existingpath = "/tmp/test";
	char *newpath = "testln";
	if (link(existingpath, newpath) == 0)  // 创建硬链接
		printf("hard link success\n");
	else
		printf("hard link failed\n");

	if (symlink(existingpath, "testSln") == 0)  // 创建软链接
		printf("soft link success\n");
	else
		printf("soft link failed\n");

	return 0;
}
