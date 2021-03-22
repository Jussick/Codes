#ifndef LOCAL_STAV_FILE_INTERFACE_H_H_
#define LOCAL_STAV_FILE_INTERFACE_H_H_

#include "AVFileInterface.h"
#include "GMFDefs.h"
#include <string>
#include <vector>

using namespace std;

#ifdef __cplusplus
extern "C"{
#endif

#include "stdint.h"
#include "inttypes.h" 
#include "libavutil/opt.h"
#include "libavutil/mathematics.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"

#ifdef __cplusplus
};
#endif


typedef vector<StruIFrameIndex> IFrameIndexList;
typedef vector<StruIFrameIndexV2> IFrameIndexListV2;

class CLocalSTAVFileReadInterface : public GSAVFileReadInterface
{
public:
	CLocalSTAVFileReadInterface();
	virtual ~CLocalSTAVFileReadInterface();

public:
	//所有的接口 不保证
	//释放对象
	virtual void Release(void) ;

	//返回媒体描述个数
	virtual int GetMediaDescriCounts(void);

	//返回 媒体描述， iIndex 有 0 开始 < GetMediaDescriCounts 返回值
	virtual const StruGSMediaDescri *GetMediaDescri( int iIndex);

	//返回文件信息
	virtual EnumGSAVFileRetCode GetInfo( StruGSAVFileInfo* pstInfo );

	//关闭文件
	virtual EnumGSAVFileRetCode Close(void);

	//设置读取方向, bForward 向后读取， 默认 是向后读取 
	virtual EnumGSAVFileRetCode SetReadDirection( bool bForward = true);

	//文件读取
	//读取下一帧, bOnlyVideoKey 只读视频关键帧
	//bForward 向后读取 
	virtual EnumGSAVFileRetCode ReadFrame(StruGSAVFrame* pstFrame,bool bOnlyVideoKey = false);

	//读取暂停
	virtual void ReadPause(void);

	//拖动
	// iTimestamp 相对 文件开头的时间偏移， 单位 秒,
	// bSeekVideoKey 如果为真， 定位前一个最近的 视频关键帧 
	virtual EnumGSAVFileRetCode SeekTime(UInt64 iTimestamp, bool bSeekToVideoKey=true, UInt32* pRealTimeStamp=NULL,Int32 iDirect = 0);
	
	// 按位置定位
	EnumGSAVFileRetCode SeekPos(UInt64 iPos);

	// 定位到当前位置最近的上一个I帧
	virtual EnumGSAVFileRetCode SeekPreviousIFrame();

	// 定位到最后一个I帧
	virtual EnumGSAVFileRetCode SeekLastIFrame();	

	// 获取当前播放位置
	Int64 GetCurrentPos();

	//修复文件
	virtual EnumGSAVFileRetCode Repair(void) ;

	virtual EnumGSAVFileRetCode RepairGetLastTime(Int64 &tv);

	EnumGSAVFileRetCode OpenFile(char* szFullName,EnumGSAVFileOpenMode eMode);

private:
	EnumGSCodeID	AVCodecID2GSCodeID(AVCodecID codeID);

	Int32	GetIFrameIndex(Int32 iFrameIndex);

	AVFormatContext* m_pAvFormat;
	AVStream*		 m_pVideoStream; 
	AVStream*		 m_pAudioStream;
	Int32			 m_nVideoIndex;
	Int32			 m_nAudioIndex;

	StruGSMediaDescri* m_pMediaDescriArry;
	Int32			 m_iMediaDesNum;
	string			 m_strFileFullName;
	Int32			 m_iFrameInterval;

	IFrameIndexList  m_iFrameIndexList;
	Int32			 m_iVideoSeq;	//记录当前播放的视频帧号,从1开始

	Int32			 m_iAudioBitRate;//音频的比特率

	bool			 m_bHadReadFrame;//已经读取过数据，用来判断是否需要释放AVPacket;
	AVPacket		 m_avPakcet;//
};


class CLocalSTAVFileWriteInterface : public GSAVFileWriteInterface
{
public:
	CLocalSTAVFileWriteInterface();
	~CLocalSTAVFileWriteInterface();
	//释放对象
	virtual void Release(void) ;

	//关闭文件
	virtual EnumGSAVFileRetCode Close(void);

	//写数据
	virtual EnumGSAVFileRetCode WriteFrame(const StruGSAVFrame* pstFrame);

	//创建文件
	EnumGSAVFileRetCode	CreateFile(const char* czFullFilename,const char *czShortFilename,  const StruGSMediaDescri *vMediaDescri, int nMediaDescriNumber);

	//返回完整目录名
	virtual const char *GetFullFilename(void);

	//返回相对目录名
	virtual const char *GetShortFilename(void);



	//返回文件大小
	virtual EnumGSAVFileRetCode GetSize( UInt64 &iFileSize );

private:
	EnumGSAVFileRetCode WriteHeadInfo(char* szFullName,const StruGSMediaDescri *vMediaDescri, int nMediaDescriNumber);
	AVCodecID	GSCodeID2AVCodecID(EnumGSCodeID codeID);
	

	AVFormatContext* m_pAvFormat;
	AVStream*		 m_pVideoStream; 
	AVStream*		 m_pAudioStream;
	Int32			 m_nVideoIndex;
	Int32			 m_nAudioIndex;
	string			 m_strFileFullName;
	string			 m_strShortFilename;
	Int64			 m_videopts;
	Int64			 m_audioopts;
};
#endif