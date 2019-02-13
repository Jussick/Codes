//C++ file
/***********************************************
#
#      Filename: sleepSort.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 睡眠排序
#        Create: 2018-12-19 11:14:53
#**********************************************/
#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include<pthread.h>
#include<iostream>
#include<vector>
using namespace std;

void *sleepSort(void *num) {
	double *realNum = (double *)num;
	sleep(*realNum / 100);
	printf("%.1f\n", *realNum);
}
class sortThread {
	double num = 0;
	pthread_t thread;
	
public:

	sortThread(double num) { 
		pthread_create(&this->thread, NULL, sleepSort, (void *) &num);
	}
};

int main()
{
	double a[8] = {1,3,2,5,4,7,6,8};
	for (int i = 0; i < 8; ++i)
	{
		sortThread(a[i]);
	} 
	
	return 0;
}


