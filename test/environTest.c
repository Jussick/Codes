#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	putenv("LUCAS=Edward");
#if 1
	extern char **environ;
	int i;
	for(i=0; environ[i]!=NULL; i++)
	printf("%s\n", environ[i]);
#endif


	setenv("LUCAS", "Edward3", 1);  // 

	char *LUCAS= getenv("LUCAS");
	printf("getenv result LUCAS=%s\n", LUCAS);

	return 0;
}
