/*
******************************************
Copyright (C), 2011-2012, GOSUN
Filename : GSTYPES.H
Author :  邹阳星
Version : 1.0.0.1
Date: 2015/2/10 9:02
Description: 基础数据类型定义
********************************************
*/

#ifndef _GS_H_GSTYPES_H_
#define _GS_H_GSTYPES_H_


#if defined(_MSC_VER) || defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

//定义使用window 平台
//# define _MSWINDOWS_

// 定义使用linux平台
# define _LINUX


#if defined(_WIN64) || defined(WIN64)
//64 位系统定义
# define __LP64__
#endif


#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#elif defined (__APPLE__)
#   define _IOS_
#   define _ios_


#endif // end defined(_MSC_VER)








#if defined(_MSWINDOWS_)
	//
	// Windows/Visual C++
	//
	//typedef signed long ssize_t;
	typedef long pid_t;

	typedef signed char            Int8;
	typedef unsigned char          UInt8;
	typedef signed short           Int16;
	typedef unsigned short         UInt16;
	typedef signed int             Int32;
	typedef unsigned int           UInt32;
	typedef signed __int64         Int64;
	typedef unsigned __int64       UInt64;

	#define GSAtomic		volatile LONG

#if defined(__LP64__)
//指针长度是 64 位
#define GS_PTR_IS_64_BIT 1
	typedef signed __int64     IntPtr;
	typedef unsigned __int64   UIntPtr;
#else
	typedef signed long        IntPtr;
	typedef unsigned long      UIntPtr;

	
	
#endif
	#define GS_CALLBACK CALLBACK
	//有64 位长度数据定义
#define GS_HAVE_INT64 1

#define EXPORT_API     extern "C" __declspec(dllexport) 
#define IMPORT_API     extern "C" __declspec(dllimport)
#define EXPORT_CLASS     __declspec(dllexport) 
#define IMPORT_CLASS     __declspec(dllimport)

#ifdef	__cplusplus
#define INLINE    	inline
#else
#define INLINE 
#endif

//格式化打印定义
// 如 :  Int64 v=0; UInt x=0; printf( "%" _PINT64 ",%" _PUINT32 "\n", v, X);

#define _PINT64 "I64d"
#define _PUINT64 "I64u"

#ifdef __LP64__
# define _PINT32  "d"
# define _PUINT32 "u"
#else
# define _PINT32  "ld"
# define _PUINT32 "lu"
#endif

#ifndef MIN_INT8
# define MIN_INT8  _I8_MIN
#endif
#ifndef MAX_INT8
# define MAX_INT8  _I8_MAX
#endif
#ifndef MAX_UINT8
# define MAX_UINT8 _UI8_MAX
#endif

#ifndef MIN_INT16
# define MIN_INT16  _I16_MIN
#endif
#ifndef MAX_INT16
# define MAX_INT16  _I16_MAX
#endif
#ifndef MAX_UINT16
# define MAX_UINT16 _UI16_MAX
#endif


#ifndef MIN_INT32
# define MIN_INT32 _I32_MIN
#endif

#ifndef MAX_INT32
# define MAX_INT32 _I32_MAX
#endif
#ifndef MAX_UINT32
# define MAX_UINT32 _UI32_MAX
#endif

#ifndef MIN_INT64
# define MIN_INT64  _I64_MIN
#endif
#ifndef MAX_INT64
# define MAX_INT64  _I64_MAX
#endif
#ifndef MAX_UINT64
# define MAX_UINT64  _UI64_MAX
#endif


#elif defined(__GNUC__) || defined(_LINUX)
#include <pthread.h>
// _ANDROID_  //安卓平台
// _IOS_	//苹果平台
	//
	// Unix/GCC || linux
	//
	typedef signed char            Int8;
	typedef unsigned char          UInt8;
	typedef signed short           Int16;
	typedef unsigned short         UInt16;
	typedef signed int             Int32;
	typedef signed long long       Int64;
    typedef void*                  LPVOID;
    typedef long                   LONG;
    typedef unsigned long          DWORD;
    

#ifndef __APPLE__
	typedef unsigned int           UInt32;
#else
    #import <MacTypes.h>
#endif

	typedef signed long            IntPtr;
	typedef unsigned long          UIntPtr;


	typedef void * HANDLE;

	#define  GSAtomic volatile long


	#define GS_CALLBACK 

#define INVALID_HANDLE_VALUE NULL

#if defined(__LP64__)

	//指针长度是 64 位
#define GS_PTR_IS_64_BIT 1
	//typedef signed long        Int64;
#ifndef __APPLE__
	typedef unsigned long long   UInt64;
#endif
#else
	typedef signed long long   Int64;
	typedef unsigned long long UInt64;
#endif
#define GS_HAVE_INT64 1



#define INLINE	inline



#define _PINT64 "lld"
#define _PUINT64 "llu"
#ifdef __LP64__

# define _PINT32  "d"
# define _PUINT32 "u"
#else

# define _PINT32  "ld"
# define _PUINT32 "lu"

#endif

# ifdef __cplusplus
# define EXPORT_API   extern "C"  
# define IMPORT_API   extern "C"  
# else
# define EXPORT_API   
# define IMPORT_API   
# endif

#define EXPORT_CLASS  
#define IMPORT_CLASS  
	//回调函数 
#ifndef CALLBACK
#define CALLBACK
#endif


#ifndef MIN_INT8
# define MIN_INT8  -128
#endif
#ifndef MAX_INT8
# define MAX_INT8  127
#endif
#ifndef MAX_UINT8
# define MAX_UINT8 0xff
#endif

#ifndef MIN_INT16
# define MIN_INT16  -32768
#endif
#ifndef MAX_INT16
# define MAX_INT16  32767
#endif
#ifndef MAX_UINT16
# define MAX_UINT16 0xffff
#endif

#ifndef MIN_INT32
# define MIN_INT32 -2147483648
#endif
#ifndef MAX_INT32
# define MAX_INT32 2147483647
#endif
#ifndef MAX_UINT32
# define MAX_UINT32 0xffffffff
#endif


#ifndef MIN_INT64
# define MIN_INT64  (-9223372036854775807ll-1)
#endif
#ifndef MAX_INT64
# define MAX_INT64  9223372036854775807ll
#endif
#ifndef MAX_UINT64
# define MAX_UINT64  0xffffffffffffffffllu
#endif



#else // end linux 
	typedef int 		              INT;
	typedef signed char              Int8;
	typedef unsigned char           UInt8;
	typedef signed short            Int16;
	typedef unsigned short         UInt16;
	typedef signed int              Int32;
	typedef unsigned int           UInt32;
	typedef signed long long        Int64;
#error "Not support os"
#endif


typedef UInt8 Byte;

#ifndef __APPLE__
#ifndef BOOL
#define BOOL int
#endif
#else
#include <objc/objc.h>
#endif

#ifndef TRUE
# define TRUE 0x1
# define FALSE 0
#endif

//==========地断定义
#define GS_ASSERT assert
#define GS_ASSERT_RET_VAL( x, val); do{ if(!(x)){ GS_ASSERT(0); return val;} }while(0)
#define GS_ASSERT_RET(x) do{ if(!(x)){ GS_ASSERT(0); return;} }while(0)


#if defined(_WIN32) || defined(_WIN64)
#define GS_EXIT_PRO(x)  TerminateProcess(GetCurrentProcess(),0)
#else
#define GS_EXIT_PRO(x)  _exit(x)
#endif

#define GS_ASSERT_EXIT(x, val ) do{ \
        if(!(x))  { \
        GS_ASSERT(0); \
        printf("Assert Exit %s %d\n", __FILE__, __LINE__); \
        GS_EXIT_PRO(val); \
        } }while(0)



#endif //end _GS_H_GSTYPES_H_
