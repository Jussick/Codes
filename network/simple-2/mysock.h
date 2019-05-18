#ifndef _MYSOCK_H
#define _MYSOCK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/***********************************************
#      函数名称: decToHex
#
#   Description: 十进制转任意位数的十六进制(目前只能实现转换成4位16进制)
#     parameter: 
			- dec: 		要转换的十进制数
			- fighres:  转换的十六进制数的位数
#   returnValue:
			- hex:		转换好的十六进制数
#   	 Author: luhg
#        Create: 2019-04-28 22:07:30
#**********************************************/
void decToHex(int dec, unsigned short figures, char *hex) {

	snprintf(hex, figures+1, "%04X", dec);
	
}

#endif

