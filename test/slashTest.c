#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>


// 读公钥文件，并转义
void TransferredPubKey(const char *path, char *value)
{
	int i, j;
	char content[1001];
	memset(content, 0, sizeof(content));
	char ch;	
	FILE *fp = fopen(path, "r");
	for (i = 0; (ch=getc(fp)) != EOF; i++)
	{
		if (ch == '/')
		{
			for (j = 0; j < 4; j++)
			{
				content[i+j] = '\\';
			}
			i = i + j;
			content[i] = ch;
		}
		else
		{
			content[i] = ch;
		}
	}
	fclose(fp);
	strcpy(value, content);
	printf("content=%s\n", content);
}

int main()
{
	char pubKeyPath[50] = {0};
	char value[1001] = {0};
	strcpy(pubKeyPath, "/root/.ssh/id_rsa123.pub");
	TransferredPubKey(pubKeyPath, value);
	printf("value=%s\n", value);

	return 0;
}
