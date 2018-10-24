//C file
/***********************************************
#
#      Filename: test.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-09-06 14:07:33
#**********************************************/
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#define MAXINTERFACES 16


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

/***********************************************
#      函数名称: GetIPbyInterface
#
#   Description: 通过网卡名称获取IP
#     parameter: interface 网卡名称
#   returnValue: 网卡对应的IP
#        Create: 2018-10-16 16:36:23
#**********************************************/
char *GetIPbyInterface( char *interface )
{
	register int fd, intrface;
	struct ifreq buf[MAXINTERFACES];
	struct ifconf ifc;
	

	if ( ( fd = socket (AF_INET, SOCK_DGRAM, 0 ) ) < 0 )
	{
		return NULL;
	} 

	ifc.ifc_len = sizeof(buf);        
	ifc.ifc_buf = (caddr_t)buf;
	if ( ioctl( fd, SIOCGIFCONF, (char *)&ifc ) < 0 ) 
	{ 
		return NULL; 
	}

	intrface = ifc.ifc_len / sizeof(struct ifreq); 
	while ( intrface-- > 0 )
	{
		if ( strcmp( buf[intrface].ifr_name, interface ) )
			continue;

		if ( ( ioctl(fd, SIOCGIFFLAGS, (char *)&buf[intrface] ) ) < 0 )
		{
			close( fd );
			return NULL;
		}

		if ( !( ioctl( fd, SIOCGIFADDR, (char *)&buf[intrface] ) ) )
		{
			close( fd );
			return inet_ntoa( ((struct sockaddr_in*)(&buf[intrface].ifr_addr))->sin_addr );
		}
		close( fd );
		return NULL;
	}
	close( fd );
	return NULL;
}
int main()
{
	char *ip = strdup(GetIPbyInterface("ens33"));	
	printf("ip: %s\n", ip);
	free(ip);
	return 0;
}
