#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>


//STDIN_FILENO标准输入描述符（0）
//
////STDOUT_FILENO标准输出描述符（1）
//
////STDERR_FILENO标准错误描述符（2） 都是int类型的

int main()
{
	int old_fd;
	int new_fd;
	char buff[32];

	int fd = open("./a.txt", O_RDWR | O_CREAT, 0600);
	strcpy(buff, "hello\n");

	old_fd = dup(STDOUT_FILENO);
	new_fd = dup2(fd, STDOUT_FILENO); // 把标准输出重定向为fd
	close(fd);
	write(STDOUT_FILENO, buff, strlen(buff));

	//还原重定向
	dup2(old_fd, STDOUT_FILENO);
	write(STDOUT_FILENO, buff, strlen(buff));

	return 0;
}
