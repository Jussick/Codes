//C file
/***********************************************
#
#      Filename: ftpDownload.c
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-11-04 17:11:04
#**********************************************/
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <strings.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
 
#define FTP_SERVER "192.168.41.220"
 
int main(int argc,char* argv[])
{
    int sk_data,sk_ctrl; //客户端的两个套接字，分别与服务器端的数据端口、命令端口端口进行通信
    struct sockaddr_in addr_data,addr_ctrl; //服务器的两个地址，分别与客户端的数据端口、命令端口端口进行通信
    struct in_addr inp;
 
    //我这里的用户名是leetow,口令是leetow
    char bufrecv[100],user[]="USER luhengguang\r\n",passwd[]="PASS 123456\r\n",pasv[]="PASV\r\n";
    char size[30]="SIZE ",type[]="TYPE A\r\n",download[30]="RETR ",quit[100]="QUIT\r\n",line_end[]="\r\n";
    char filebuf[50000],str[100]; //文件缓冲区
    int  lensnd,lenrecv,err;
    int a1,a2,a3,a4,p1,p2;//从服务器返回的地址和端口
    FILE *fp;
    int len;
 
    //获得文件名
    if(argc!=2)
    {
        printf("Usage:%s filename \n", argv[0]);
        return -1;
    }
    //补齐文件大小与下载文件的命令
    strcat(size,argv[1]);
    strcat(size,line_end);
 
    strcat(download,argv[1]);
    strcat(download,line_end);
 
    //create two socket for SOCK_STREAM
    sk_data=socket(AF_INET,SOCK_STREAM,0);
    sk_ctrl=socket(AF_INET,SOCK_STREAM,0);
    if(sk_data<0 )
    {
        perror("creat socket sk_data error");
        return -1;
    }
    if(sk_ctrl < 0 )
    {
        perror("creat socket sk_ctrl error");
        close(sk_data);
        return -1;
    }
    //与服务器上的21号端口连接
    bzero(&addr_ctrl,sizeof(struct sockaddr_in));
    inet_aton(FTP_SERVER, &inp);  //服务器IP地址
    addr_ctrl.sin_family=AF_INET;
    addr_ctrl.sin_addr=inp;
    addr_ctrl.sin_port=htons(21);   //FTP命令端口
    //connect to server
    err=connect(sk_ctrl,(struct sockaddr*)&addr_ctrl,sizeof(struct sockaddr));
    if(-1==err)
    {
        perror("connect 21 error");
        close(sk_data);
        close(sk_ctrl);
        return -1;
    }
 
    //输出服务器端的连接成功的信息
    bzero(bufrecv,100);
    lenrecv=recv(sk_ctrl,bufrecv,100,0);
    if(lenrecv>0)
    {
      printf("connect 21 successfully:%s\n",bufrecv);
     }
    //发送用户名
    lensnd=send(sk_ctrl,user,strlen(user),0);
    if(lensnd>0)
    {
      bzero(bufrecv,100);
      recv(sk_ctrl,bufrecv,100,0);
      printf("user name:%s\n",bufrecv);
     }
 
     //发送口令
    lensnd=send(sk_ctrl,passwd,strlen(passwd),0);
    if(lensnd>0)
    {
      bzero(bufrecv,100);
      recv(sk_ctrl,bufrecv,100,0);
      printf("password:%s\n",bufrecv);
     }
     //PASV
     lensnd=send(sk_ctrl,pasv,strlen(pasv),0);
     if(lensnd>0)
     {
      bzero(bufrecv,100);
      recv(sk_ctrl,bufrecv,100,0);
      printf("pasv:%s\n",bufrecv);
      sscanf(bufrecv,"%*[^(]%[^)]",str);  //字符串中从"（"开始一直到"）"之间的字符存到str中,包括"("
      sscanf(str,"(%d,%d,%d,%d,%d,%d",&a1,&a2,&a3,&a4,&p1,&p2);
      printf("p1,p2=%d,%d\n",p1,p2);
      printf("p1*256+p2=%d\n",p1*256+p2);
     }
     //指定服务器的数据端口
     bzero(&addr_data,sizeof(struct sockaddr_in));
     inet_aton(FTP_SERVER, &inp);  //服务器IP地址
     addr_data.sin_family=AF_INET;
     addr_data.sin_addr=inp;
     addr_data.sin_port=htons(p1*256+p2);
 
    err=connect(sk_data,(struct sockaddr*)&addr_data,sizeof(struct sockaddr));
    if(-1==err)
    {
        perror("connect 20 error");
        close(sk_data);
        close(sk_ctrl);
        return -1;
    }
     //获得文件大小
     lensnd=send(sk_ctrl,size,strlen(size),0);
     if(lensnd>0)
     {
       bzero(bufrecv,100);
       recv(sk_ctrl,bufrecv,100,0);
       printf("sz:%s\n",bufrecv);
       sscanf(bufrecv,"%d %d",&a1,&len);
       printf("a1,len=%d,%d\n",a1,len);
      }
     //从服务器上获得文件
    lensnd=send(sk_ctrl,download,strlen(download),0);
    if(lensnd>0)
    {
       bzero(bufrecv,100);
       recv(sk_ctrl,bufrecv,100,0);
       printf("get file:%s\n",bufrecv);
    }
 
    //本地建文件并写入数据
    fp=fopen(argv[1],"w");
    if(NULL==fp)
    {
        printf("fopen error:\n");
        close(sk_data);
        close(sk_ctrl);
        return -1;
    }
    lenrecv=recv(sk_data,filebuf,len,0);
    if(lenrecv>0)
    {
         fwrite(filebuf,len,1,fp);
         fclose(fp);
     }
 
     //退出
     lensnd=send(sk_ctrl,quit,strlen(quit),0);
    if(lensnd>0)
    {
      bzero(bufrecv,100);
      recv(sk_ctrl,bufrecv,100,0);
      printf("quit:%s\n",bufrecv);
      printf("send qexit successful\n");
     }
 
    close(sk_data);
    close(sk_ctrl);
    return 0;
}


