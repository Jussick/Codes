/*
******************************************
Copyright (C): GOSUN
Filename : AVFILEINTERFACE.H
Author :  zouyx
Description: 媒体文件 读写接口定义
********************************************
*/

#ifndef _GS_H_AVFILEINTERFACE_H_
#define _GS_H_AVFILEINTERFACE_H_

#include "CommonDef.h"

class GSAVFileReadInterface
{
public :	
	//所有的接口 不保证
	//释放对象
	virtual void Release(void) = 0;

	//返回媒体描述个数
	virtual int GetMediaDescriCounts(void) = 0;
	//返回 媒体描述， iIndex 有 0 开始 < GetMediaDescriCounts 返回值
	virtual const StruGSMediaDescri *GetMediaDescri( int iIndex) = 0;

	//返回文件信息
	virtual EnumGSAVFileRetCode GetInfo( StruGSAVFileInfo* pstInfo ) = 0;

	//关闭文件
	virtual EnumGSAVFileRetCode Close(void) = 0;

	//设置读取方向, bForward=true向前读取， 默认 是向前读取 
	virtual EnumGSAVFileRetCode SetReadDirection( bool bForward = true) = 0;

	//文件读取
	//读取下一帧, bOnlyVideoKey 只读视频关键帧
	virtual EnumGSAVFileRetCode ReadFrame(StruGSAVFrame* pstFrame,
		bool bOnlyVideoKey = false) = 0;
	
	//读取暂停
	virtual void ReadPause(void) = 0;

	//拖动
	// iTimestamp 相对 文件开头的时间偏移， 单位 秒,
	// bSeekVideoKey 如果为真， 定位前一个最近的 视频关键帧 
	virtual EnumGSAVFileRetCode SeekTime(UInt64 iTimestamp, bool bSeekToVideoKey=true, UInt32* pRealTimeStamp=NULL,Int32 iDirect = 0) = 0;
	
	// 按位置定位
	virtual EnumGSAVFileRetCode SeekPos(UInt64 iPos) = 0 ;

	// 获取当前播放位置
	virtual Int64 GetCurrentPos() = 0;

	// 定位到当前位置最近的上一个I帧
	virtual EnumGSAVFileRetCode SeekPreviousIFrame() = 0 ;
	
	// 定位到最后一个I帧
	virtual EnumGSAVFileRetCode SeekLastIFrame() = 0 ;

	//修复文件
	virtual EnumGSAVFileRetCode Repair(void) = 0;


	//修复文件, 获取最后时戳
	virtual EnumGSAVFileRetCode RepairGetLastTime(Int64 &tv) = 0;
};


class GSAVFileWriteInterface
{
public:
	//释放对象
	virtual void Release(void) = 0;

	//关闭文件
	virtual EnumGSAVFileRetCode Close(void) = 0;

	//写数据
	virtual EnumGSAVFileRetCode WriteFrame(const StruGSAVFrame* pstFrame) = 0;
	
	

	//返回完整目录名
	virtual const char *GetFullFilename(void) = 0;

	//返回相对目录名
	virtual const char *GetShortFilename(void) = 0;

	//返回文件大小, Release 前都可以调用， 单位：字节
	//Close 前调用返回当前写入媒体大小， 
	//Close 后调用返回正个文件的大小
	virtual EnumGSAVFileRetCode GetSize( UInt64 &iFileSize ) = 0;

};


//普通文件
class GSNormalFile
{
public :
	virtual void Release(void) = 0;

	//顺序写
	virtual EnumGSAVFileRetCode Write(const void *data,  int size) = 0;

	//读到结尾返回 eAVF_READ_END, 顺序读
	virtual EnumGSAVFileRetCode Read(const void *data,  int size) = 0;

	//关闭文件
	virtual EnumGSAVFileRetCode Close(void) = 0;
};


typedef struct _StruNameInfo
{
	bool isDir;
	char *szFullFilename; //全路径
	_StruNameInfo(void) : isDir(false),szFullFilename(NULL)
	{

	}
}StruNameInfo;


class GSAVFileSystemInterface
{
public :
	// czRootPath 路径名称， 根目录:  disk_label/
	//					如:  E:/   192.168.0.1:8000/cluster1
	// czShortFilename 相对目录名 

	//新建录像文件, czFilename 该文名 为参考文件名, czFormat 参考文件格式， 如 "avi", "gmf" 等
	//真正的文件 由 调用  GSAVFileInterface::GetShortFilename 返回
	// vMediaDescri  媒体属性描述
	// nMediaDescriNumber vMediaDescri 的个数

	// CMCC云存储说明
	// 文件完整路径	bucketName/foldername/filename, 其中foldername可为空
	// czRootPath			bucketName/
	// czShortFilename		foldername/filename

	//dah 云存储 
	// 文件完整路径 ip:port/ducket|/foldername|/filename
	// czRootPath			bucketName/
	// czShortFilename		foldername/filename
	virtual EnumGSAVFileRetCode CreateFile( const char *czRootPath,
											const char *czShortFilename,	
											const StruGSMediaDescri *vMediaDescri, int nMediaDescriNumber,
											GSAVFileWriteInterface **ppAVFile ) = 0;

	//打开存在的录像文件
	// czFilename 文件名 由   GSAVFileInterface::GetShortFilename 返回 的文件名
	virtual EnumGSAVFileRetCode OpenFile( const char *czRootPath,
										  const char *czFilename,
										  EnumGSAVFileOpenMode eMode, 
										  GSAVFileReadInterface **ppAVFile ) = 0;

	virtual EnumGSAVFileRetCode OpenNormalFile(const char *czFullFilename
		, EnumGSAVFileOpenMode e, GSNormalFile **ppFile) = 0;

	//返回文件系统类型
	virtual EnumFileSystemType GetMediumType(void) = 0;

	//删除文件
	virtual EnumGSAVFileRetCode RemoveFile(const char *czFullFilename) = 0;

	//获取文件信息
	virtual EnumGSAVFileRetCode GetFileInfo( const char *czFullFilename,
											 StruGSAVFileInfo* pstInfo ) = 0;

	//返回存储设备的空间大小, czStorageDevLabel 存储设备标签(盘符),  单位 Byte
	virtual EnumGSAVFileRetCode GetStorageDevSpace(const char *czStorageDevLabel,
					UInt64* pTotal,UInt64* pFree  ) = 0;

	// 获取磁盘列表
	virtual EnumGSAVFileRetCode GetDiskList(StruDisk** pstDisk, int *iNums) = 0;
	virtual void FreeDiskList(StruDisk* pstDisk) = 0;

	// 创建UUID
	virtual EnumGSAVFileRetCode CreateUUID(const char *szDir, const char *szUUID) = 0;

	// 读取UUID,szUUID内存由外面传入，长度不小于64字节
	virtual EnumGSAVFileRetCode ReadUUID(const char *szDir, char *szUUID) = 0;

	// 创建目录
	virtual EnumGSAVFileRetCode MakeDir( const char *szDir ) = 0;

	// 删除目录
	virtual EnumGSAVFileRetCode RemoveDir( const char *szDir ) = 0;

	//目是否为空 0 表示空
	virtual EnumGSAVFileRetCode IsDirEmpty( const char *szDir ) = 0;

	//例举szDir目录下的文件和文件夹信息 (不包含子目录文件和子文件夹)
	virtual EnumGSAVFileRetCode List(const char *szDir,
							StruNameInfo **vNameInfo, int *iNums) = 0;
	virtual void FreeNameList(StruNameInfo* pstDisk) = 0;
};


#endif //end _GS_H_AVFILEINTERFACE_H_
