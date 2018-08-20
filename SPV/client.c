#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include "unionxml.h"
#include "unionsynch.h"
#include "unionsock.h"
#include "unionenc.h"
#include "unionrandom.h"
#include "unionerror.h"
#include "unionbox.h"
#include "unionlog.h"
#include "uniondb.h"
#include <sys/stat.h>
#include <fcntl.h>
#define MAXLINE 4096
#define SPLIT_1 "\001"
#define DBNAME UnionGetDBName()

char buffer[4] = {0};

char *inttohex(int aa)
{
    static int i = 0;
    if (aa < 16)            //递归结束条件 
    {
        if (aa < 10)        //当前数转换成字符放入字符串 
            buffer[i] = aa + '0';
        else
            buffer[i] = aa - 10 + 'A';
        buffer[i+1] = '\0'; //字符串结束标志 
    }
    else
    {
        inttohex(aa / 16);  //递归调用 
        i++;                //字符串索引+1 
        aa %= 16;           //计算当前值
        if (aa < 10)        //当前数转换成字符放入字符串 
            buffer[i] = aa + '0';
        else
            buffer[i] = aa - 10 + 'A';
    }
	return buffer;
}

char *GetAppDrawWorknoteByAccount(char *devIP, char *accountname)
{
    char **sqlresult = NULL;                                                     
    char sql[1024] = {0};                                                        
    int row, col;
    char *errmsg = NULL;
    int UnionErr = UNION_OPERATE_SUCCESS;

	// 数据库初始化连接
	UnionErr = UnionDBInit(DBNAME);	

	// 根据账户名和IP查询帐户ID
	UnionDBPrintf(sql, sizeof(sql), "SELECT account.id FROM account, device WHERE device.IP ='%s' \
			AND device.id = account.deviceID AND account.name='%s'", devIP, accountname);
	UnionErr = UnionDBQuery(sql, &sqlresult, &row, &col, &errmsg);
	int accountID = atoi(sqlresult[0]);

	// 根据帐户ID查询worknote
	memset(sql, 0, sizeof(sql));
	UnionDBPrintf(sql, sizeof(sql), "SELECT worknote FROM worknote_account WHERE accountID=%d AND worknoteType='17957132'", accountID);
	UnionErr = UnionDBQuery(sql, &sqlresult, &row, &col, &errmsg);
	char *worknote = strdup(sqlresult[0]);
	printf("worknote = %s", worknote);

	return worknote;
}

int main(int argc, char** argv)
{
    int    sockfd;
    char   sendline[MAXLINE];
    struct sockaddr_in    servaddr;

    if( argc != 6){
    printf("usage: ./client <SPVIP> <devip> <appname> <accountname> <worknote>\n");
    exit(0);
    }

	/* 向SPV发送密码查询请求报文 */
	char *SPVIP = strdup(argv[1]);
	char *devip = strdup(argv[2]);
	char *appname = strdup(argv[3]);
	char *accountname = strdup(argv[4]);
	char *worknote = strdup(argv[5]);
	//char *worknote = strdup(GetAppDrawWorknoteByAccount(devip, accountname));
	printf("worknote = %s\n", worknote);


	char accountname_bak[128] = {0};
	char devip_bak[32] = {0};
	strcpy(accountname_bak, accountname);
	strcpy(devip_bak, devip);

    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
    exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(61121);
    if( inet_pton(AF_INET, SPVIP, &servaddr.sin_addr) <= 0){
		printf("inet_pton error for %s\n",SPVIP);
		exit(0);
    }

	if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
	printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
	exit(0);
	}
	// 组发送XML
	UnionXmlNode *OutputNode = NULL;		
	OutputNode = UnionXmlCreateInit( "AccPswdQuery" );
	char data[512] = {0};
	snprintf(data, sizeof(data), "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
			"systype", SPLIT_1, "2", SPLIT_1, "sysid", SPLIT_1, appname, SPLIT_1, "worknote", SPLIT_1, worknote,
			SPLIT_1, "user", SPLIT_1, accountname, SPLIT_1, "devip", SPLIT_1, devip, SPLIT_1, "protocol", SPLIT_1, "SSH");
	UnionXmlCreateNode(OutputNode, "request", NULL, data);
	char result[1024] = {0};
	char finalresult[1024] = {0};
	strcpy(result, UnionXmlCreateFinal(1, OutputNode));
	snprintf(finalresult, sizeof(finalresult), "%s", result+38);
	// 组报文头
	int xmllen = strlen(finalresult);
	char temp[5] = {0};
	char hxmllen[5] = {0}; // 16进制长度
	inttohex(xmllen+12);  // 十进制转十六进制
	// 把16进制长度前面填充0
	if (strlen(buffer) == 2)
		snprintf(temp, sizeof(temp), "00%s", buffer);	
	else if (strlen(buffer) == 3)
		snprintf(temp, sizeof(temp), "0%s", buffer);	

	strcpy(hxmllen, temp);
	char header[24] = {0};
	snprintf(header, sizeof(header), "%s%s", hxmllen, "00010402");
	// 组发送报文
	snprintf(sendline, sizeof(sendline), "%s%s", header, finalresult);	
	//printf("发送报文%s\n", sendline);
		
	if( send(sockfd, sendline, strlen(sendline), 0) < 0)  
	{
		printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}
	char recvBuf[MAXLINE];
	recv(sockfd, recvBuf, sizeof(recvBuf), 0);
	printf("----recive from SPV----\n");
	printf("%s\n", recvBuf);

	char *recvXML = strdup(recvBuf+12);

	free(SPVIP);
	free(devip);
	free(appname);
	free(accountname);
	free(worknote);
	close(sockfd);



	// 从SPV返回的XML中找到epswd
	char *hpswd = NULL, *epswd = NULL;
	UnionXmlNode *xmlnode = NULL;
	xmlnode = UnionXmlRead( 1, recvXML, "AccPswdQuery/response");
	hpswd = XmlGetValue( xmlnode, "epswd" );
	//printf("hpwd=%s\n", hpswd);
	epswd = calloc( 1, strlen(hpswd)/2+1 );
	UnionHex2Str( epswd, hpswd, strlen(hpswd)/2 );
	//printf("epwd=%s\n", epswd);

	/* 开始SM4解密 */
	int connfd = UnionConnectServer( SPVIP, UNION_SYNCH_SER_PORT );   
	char randomstr[32] = "juu@#NG873";
	char errmsg[256] = {0};
	time_t timestamp = 0;	
	char pwd[256] = {0};	
	unsigned char key[32] = {0};                                         
    unsigned char iv[32] = {0};                                          
    unsigned char newkey[16] = {0};                                      
    unsigned char newiv[16] = {0};
	// 把标准输出和错误输出重定向
	int out_fd, err_fd;
	out_fd = dup(STDOUT_FILENO);
	err_fd = dup(STDERR_FILENO);
	int fd1 = open("/tmp/a.txt", O_RDWR | O_CREAT, 0600);
	int fd2 = open("/tmp/b.txt", O_RDWR | O_CREAT, 0600);
	dup2(fd1, STDOUT_FILENO);
	dup2(fd2, STDERR_FILENO);
	//密钥校验
	UnionSynGetKey( key, iv, "InnerTest", 0 );
	SPVSynKeyChk( connfd, key, iv, "InnerTest", 0, randomstr, errmsg );
	//密钥初始化
	memset( errmsg, 0, 256 );                 
	timestamp = time( NULL );       //生成时间戳                                                                          
	SPVSynKeyInit( connfd, key, iv, newkey, newiv,  "InnerTest", 0, timestamp, errmsg );
	UnionDataDecSM4( (unsigned char *)epswd, UnionSM4PaddingLen(strlen(hpswd)/2), 
						(unsigned char *)pwd, newkey, newiv );
	// 还原重定向
	dup2(out_fd, STDOUT_FILENO);
	dup2(err_fd, STDOUT_FILENO);
	printf("%s@%s's pwd=%s\n", accountname_bak, devip_bak, pwd);



	close(fd1);
	close(fd2);
	free(recvXML);
	close(connfd);
	exit(0);
}
