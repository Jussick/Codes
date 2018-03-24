#include<stdio.h>
#include<stdlib.h>

int power(int num, int powNum)
{
	int n = 1;
	int result = 1;
	while(n<=powNum){
		result *= num;
		n++;
	}
	return result;
}

int GenerateRandomNum() 
{   
    int randomNum = 0; 
    int tem = 0; 
    int n;
    srand(time(0));
    for(n=0; n<3; n++){
        tem = rand() % 10; 
        randomNum += tem * power(10, n); 
    }
    return randomNum; 
}

int main(int argc, char *argv[])
{
	int num = 0;
	num = GenerateRandomNum();
	printf("num=%d\n",num);
	return 0;
}
