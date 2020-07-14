/*
******************************************
Copyright (C): GOSUN
Filename : GSDEFS.H
Author :  zouyx
Description: 通用宏定义
********************************************
*/

#ifndef _GS_H_GSDEFS_H_
#define _GS_H_GSDEFS_H_

#include "GSTypes.h"
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#ifdef _MSWINDOWS_
#include <process.h>
#else
#include <string.h>
#endif

#define gs_sprintf sprintf

#define gs_fprintf fprintf

#define gs_printf printf

#ifdef _MSWINDOWS_
//#define gs_snprintf _snprintf
#define  gs_snprintf(xbuf, xbufsize , xfmt, ... ) _snprintf_s(xbuf,xbufsize, _TRUNCATE,xfmt, __VA_ARGS__)
#define bzero(_m, _s) memset(_m, 0, _s)
#define gs_vsnprintf(xbuf, xbufsize , xfmt, ... ) _vsnprintf_s(xbuf,xbufsize, _TRUNCATE,xfmt, __VA_ARGS__)
#define strcasecmp _stricmp 
#define strncasecmp _strnicmp 
#define gs_strncpy strncpy_s
#define gs_strdup _strdup
#else
#define gs_snprintf snprintf
#define gs_vsnprintf vsnprintf
#define gs_strncpy strncpy
#define gs_strdup strdup
#endif







static void MyAbort(char *s)
{
	gs_printf("%s\n", s);
	abort();
}


#define kAssertBuffSize 256

#ifdef _DEBUG

static void MyAssert(char *s)
{
	gs_printf("%s\n", s);

#ifdef _MSWINDOWS_
	//DebugBreak();
	assert(0);
#else
	(*(int*)0) = 0;
#endif

}

#define GSAssert(condition)    {                              \
	\
	if (!(condition))                                       \
{                                                       \
	char s[kAssertBuffSize];                            \
	s[kAssertBuffSize -1] = 0;                          \
	gs_snprintf (s,kAssertBuffSize -1, "_Assert: %s, %s, %d", #condition, __FILE__, __LINE__ ); \
	MyAssert(s);                                        \
}   }


#define GSAssertV(condition,errNo)    {                                   \
	if (!(condition))                                                   \
{                                                                   \
	char s[kAssertBuffSize];                                        \
	s[kAssertBuffSize -1] = 0;                                      \
	gs_snprintf( s,kAssertBuffSize -1, "_AssertV: %s, %s, %d (%d)", #condition, __FILE__, __LINE__, errNo );    \
	MyAssert(s);                                                    \
}   }

#else
#define GSAssert(condition) (condition)
#define GSAssertV(condition,errNo) (condition)
#endif


#define GSAbort(condition)    {                              \
	\
	if (!(condition))                                       \
{                                                       \
	char s[kAssertBuffSize];                            \
	s[kAssertBuffSize -1] = 0;                          \
	gs_snprintf (s,kAssertBuffSize -1, "_Abort: %s, %s, %d", #condition, __FILE__, __LINE__ ); \
	MyAbort(s);                                        \
}   }


#define GSAbortV(condition,errNo)    {                                   \
	if (!(condition))                                                   \
{                                                                   \
	char s[kAssertBuffSize];                                        \
	s[kAssertBuffSize -1] = 0;                                      \
	gs_snprintf( s,kAssertBuffSize -1, "_AbortV: %s, %s, %d (%d)", #condition, __FILE__, __LINE__, errNo );    \
	MyAbort(s);                                                    \
}   }


#define GSWarn(condition) {                                       \
	if (!(condition))                                       \
	gs_printf( "_Warn: %s, %s, %d\n",#condition, __FILE__, __LINE__ );     }                                                           

#define GSWarnV(condition,msg)        {                               \
	if (!(condition))                                               \
	gs_printf ("_WarnV: %s, %s, %d (%s)\n",#condition, __FILE__, __LINE__, msg );  }                                                   

#define GSWarnVE(condition,msg,err)  {                           		\
	if (!(condition))                                               \
	gs_printf ("_WarnVE: %s, %s, %d (%s [err=%d])\n",#condition, __FILE__, __LINE__, msg, err );  }


#define GS_CLASS_NOCOPY(classname) \
private : \
classname( const classname &dest ); \
classname &operator= (const  classname &dest);

#define GS_ASSERT_RET_VAL(_condition, _val) if(!(_condition)){GSAssert(0); return _val;}
#define GS_ASSERT_RET(_condition) if(!(_condition)){ GSAssert(0); return;}


#ifndef MIN
#define MIN(_a , _b) ( (_a) < (_b) ? _a : _b)
#endif

#ifndef MAX
#define MAX(_a , _b) ( (_a) > (_b) ? _a : _b)
#endif
#endif //end _GS_H_GSDEFS_H_
