#include<stdio.h>
#include<string.h>

int main()
{
	char str[] = "123:456:789";
	char *save = NULL;
	char *p = strtok_r(str, ":", &save);
	printf("s = %s\n", p);
	p = strtok_r(save, ":", &save);
	printf("s = %s\n", p);
	printf("s = %s\n", save);

	return 0;
}
