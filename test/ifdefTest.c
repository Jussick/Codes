#include<stdio.h>
#define TEST 1
int main()
{
#ifdef TEST
	printf("hello world!\n");
#endif
	return 0;
}

