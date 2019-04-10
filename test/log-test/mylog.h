#ifndef _LOG_H_
#define _LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

   #define SIZE_16M               16777216  //1024*1024*16
   #define LOG_FILE_PATH          "./ssh.log"  //日志的路径
   #define LOG_PARAMS             LOG_FILE_PATH,__FILE__,__func__,__LINE__  //日志文件路径 调用函数所在文件 调用函数名 调用debugInfo时所在行号   
   #define STR_LEN_2048           2048
   #define VS_ERR 1 
   #define VS_OK  0

   extern  int debugInfo(char *pLogPath, char *pFile, const char *pFuncName, int iLineNumb, char *fmt, ...); 

#ifdef __cplusplus
}
#endif

#endif
