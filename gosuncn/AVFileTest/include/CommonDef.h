#ifndef _MAVFS_COMMON_DEF_H_
#define _MAVFS_COMMON_DEF_H_

#include "GSMediaDefs.h"
#include "GSDefs.h"
#include "GSStrUtil.hpp"



#include <errno.h>

#ifdef _WIN32
#include <io.h>
#include <Windows.h>
#include <sys/stat.h>
#include <direct.h>
#else
#include <sys/vfs.h>    // or <sys/statfs.h>
#include <sys/io.h>
#endif
	

#define UUID_FILENAME "uuid.bat"

namespace MAVFS
{

typedef enum
{
	eOPEN_READ = 1,			//只读	
	eOPEN_WRITE = 2,		//只写
	eOPEN_REPARE = 3		//修复
}EnumGSAVFileOpenMode;

typedef enum
{
	eNULL_SYSTEM = 0,
	eNOMAL_SYSTEM = 1,	// 普通文件系统
	eAliOSS_SYSTEM = 2, // 阿里云存储文件系统
	eONEST_SYSTEM = 3,	// 移动云存储
	eDAHUA_SYSTEM = 4,	// 大华云存储系统
	eHikHCS_SYSTEM = 5,   //海康云存储
}EnumFileSystemType;

const int ACCESS_INTERFACE_C = 1;
const int ACCESS_INTERFACE_FUSE = 2;


typedef enum
{
	eAVF_END_OF_GOP = 1, //读一帧成功,并且是该GOP的最后一帧
	eAVF_SUCCESS = 0, //成功
	eAVF_EIO = -1, //读写IO 失败
	eAVF_EINVALID = -2, //参数错误
	eAVF_READ_END = -3, //读取到结尾
	eAVF_ERANGE = -4, //超出范围
	eAVF_ENEXIST =-5, //文件不存在
	eAVF_EEXIST = -6, //文件已经存在
	eAVF_EOPER = -7,  //当前模式下不运行的操作
	eAVF_ENFILESYSTEM = -8, //不支持的文件系统
	eAVF_ENOPEN = -9, //文件没有打开
	eAVF_EUNLOAD = -10, //文件系统已经卸载
	eAVF_NOT_IMPELETE = -11, //接口未实现
	eAVF_INIT_ERROR = -12,	//初始化失败
	eAVF_SDK_ERROR	= -13,	//调用SDK接口失败
	eAVF_FILE_ERROR	= -14,		//文件格式错误
	eAVF_MEMORY_ERROR = -15,	//内存错误
	eAVF_BUF_OVERFLOW = -16,	//缓冲区溢出
	eAVF_NO_FRAMEINDEX = -17,	//没有帧索引
	eAVF_READ_CLOUDDATA_FAIL = -18,	//读取云端数据失败
	eAVF_CREATE_CLOUDFILE_FAIL = -19, //创建云存储文件失败
	eAVF_DEL_CLOUDFILE_FAIL = -20,	//删除云端文件失败
	eAVF_OVERFILE_MAXSIZE = -21,	//超过文件最大限制
	eAVF_ERROR = -22,				//内部错误		
	eAVF_IDX_DAMAGED = -23,			//索引不完成
	eAVF_EIDX_FILE = -24,  //非索引文件
	eAVF_EVERSION = -25, //不支持的版本
	eAVF_ENSPACE = -26, //没空间


	//一下是内部错误
#define eAVF_EINNER_MARK -100000
	eAVF_DIR_NEXIST = (eAVF_EINNER_MARK+(int)eAVF_ENEXIST), //目录不存在
	eAVF_DIR_EEXIST = (eAVF_EINNER_MARK+(int)eAVF_EEXIST), //目录已经存在
}EnumGSAVFileRetCode;



//数据帧
typedef struct _StruGSAVFrame
{
	EnumGSMediaType eMediaType; //媒体类型
	Int64 iTimestamp; //绝对时间 ,UTC 秒，就是当前帧的index*帧间隔（25帧的话，间隔是40ms），例如：第一帧的stamp就是1*40,第二帧是2*40....第n帧是n*40
	int bKeyFrame; //是否关键帧	1：关键帧   0：非关键帧，也就是不是I帧，是就为1，不是就为0

	const unsigned char *pMediaData; //媒体数据
	unsigned int iMediaDataLen; //媒体数据长度

	UInt32 iDurationStamp;  //毫秒时戳
	bool isValidDurationStamp; //毫秒时戳是否有效
	_StruGSAVFrame(void) 
		:eMediaType(GS_MEDIA_TYPE_NONE)
		,iTimestamp(-1),bKeyFrame(0)
		,pMediaData(NULL), iMediaDataLen(0)
		,iDurationStamp(0),isValidDurationStamp(false)
	{
			
	}

}StruGSAVFrame;



//文件信息
typedef struct _StruGSAVFileInfo
{
	UInt64 iSize;			//文件大小
	UInt64 iTimeLength;		//返回文件时间长度, 单位秒
	UInt64 iLastModifyTime; //最后修改时间 ， UTC 秒数
	_StruGSAVFileInfo() : iSize(0),iTimeLength(0),iLastModifyTime(0)
	{

	}
}StruGSAVFileInfo;

#define DISK_LEN 128
#define UUID_LEN 128

typedef struct _StruDisk
{
	char szDisk[DISK_LEN+1];
	char szUUID[UUID_LEN+1];
	bool bActive;
	_StruDisk()
	{
		memset(this,0, sizeof(*this));
	}
} StruDisk, *StruDiskPtr;


} //end namspace MAVFS

//兼用旧的定义
#ifndef _DISABLE_MAVFS_NAMESPACE_
using namespace MAVFS;
#endif



#endif