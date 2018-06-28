#include <stdio.h>
#include<stdlib.h>

int main(void)
{
	extern char **environ;
	int i;
	for(i=0; environ[i]!=NULL; i++)
	printf("%s\n", environ[i]);

	char *PATH = getenv("PATH");
	printf("getenv result PATH=%s\n", PATH);
	return 0;
}
