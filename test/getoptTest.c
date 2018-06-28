#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	extern char *optarg;
	char *user = NULL;
	char *pwd = NULL;
	char *authKeylen = NULL;
	char *str = NULL;

	int opt;

	puts("start");
	while ((opt = getopt(argc, argv, "u:p:L:s:")) != -1)
	{
		switch (opt){
			case 'u':
				user = strdup(optarg);
				break;
			case 'p':
				pwd = strdup(optarg);
				break;
			case 'L':
				authKeylen = strdup(optarg);
				break;
			case 's':
				str = strdup(optarg);
				break;
			default:
				printf("usage: -u[user] -p[password]\n");

		}
	}
	puts("end");
	printf("str=%s\n", str);

	return 0;
}
