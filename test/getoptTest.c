#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	extern char *optarg;
	char *user = NULL;
	char *pwd = NULL;

	int opt;

	while ((opt = getopt(argc, argv, "u:p:")) != -1)
	{
		switch (opt){
			case 'u':
				user = strdup(optarg);
				break;
			case 'p':
				pwd = strdup(optarg);
				break;
			default:
				printf("usage: -u[user] -p[password]\n");

		}
	}
	printf("user:%s\t", user);
	printf("pwd:%s\n", pwd);

	free(user);
	free(pwd);
	return 0;
}
