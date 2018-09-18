//C file
/***********************************************
#
#      Filename: test.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-09-06 14:07:33
#**********************************************/
#include<stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include<string.h>


/***********************************************************
  功能:	
  域名转换为IP地址
  参数:	
  domain[in]		域名
  ip[out]			IP地址
  返回值:		
  =0			成功
  <0			失败，返回错误码
 ***********************************************************/
int UnionAPIGetHostByName(char *domain, char *ip)
{
	struct addrinfo		*res, *pt;   
	struct sockaddr_in	*sinp;   
	const char 		*addr;   
	char			abuf[INET_ADDRSTRLEN];   
	int			ret;

	ret = getaddrinfo(domain, NULL, NULL, &res);   
	if (ret != 0)   
	{   
		return(ret);
	}   

	for (pt=res; pt != NULL; pt=pt->ai_next)
	{   
		if (pt->ai_family != AF_INET)
			continue;
		sinp = (struct sockaddr_in *)pt->ai_addr;   
		//sinp = pt->ai_addr;   
		addr = (const char *)inet_ntop(AF_INET, &sinp->sin_addr, abuf, INET_ADDRSTRLEN);   
		strcpy(ip,addr);
		break;
	}   
	freeaddrinfo(res);
	return(0);
}

int main()
{
	char *domain = "localhost";
	char IP[128];
	UnionAPIGetHostByName(domain, IP);	
	printf("ip: %s\n", IP);
	return 0;
}
