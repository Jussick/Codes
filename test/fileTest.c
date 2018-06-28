#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static char *GetLine(char *line, char *src, char **saved)
{
	char *ptr = NULL;
	if (src != NULL)
	{
		ptr = src;
	}
	else if (*saved != NULL && **saved != '\0') 
	{
		ptr = *saved;
	}
	else return NULL;
	int i,j;
	for (i = 0, j = 0; ptr[i] != '\0'; ++i)
	{
		line[j++] = ptr[i];
		if (ptr[i] == '\n' || ptr[i] == '\r')
		{
			break;
		}
	}
	line[j] = 0;
	if (ptr[i] == '\0')
		*saved = ptr+i;
	else
		*saved = ptr+i+1;
	return line;
}

// 读取文件的内容并打印
char *readFileContent(char *filename)
{
	char *result = (char *)calloc(1, 1024*1024*5);
	char line[1024];
	FILE *fp = fopen(filename, "r");
	while(!feof(fp))
	{
		fgets(line, sizeof(line), fp);
		//printf("%s", line);
		snprintf(result+strlen(result), sizeof(line), "%s", line);
	}
	fclose(fp);
	return result;
}


int main()
{
	char line[1024];
	char *ptr = readFileContent("linux");
	char *save = NULL;
	
	ptr = GetLine(line, ptr, &save);
	printf("----------------------------------------------------------------------------ptr=%s\n", ptr);
	printf("----------------------------------------------------------------------------line=%s\n", line);
	printf("----------------------------------------------------------------------------save=%s\n", save);

	ptr = GetLine(line, ptr, &save);
	printf("----------------------------------------------------------------------------ptr=%s\n", ptr);
	printf("----------------------------------------------------------------------------line=%s\n", line);
	printf("----------------------------------------------------------------------------save=%s\n", save);

	return 0;
}
