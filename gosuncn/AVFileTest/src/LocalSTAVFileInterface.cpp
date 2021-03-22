#include "CommonDef.h"
#include "LocalSTAVFileInterface.h"
#include <sys/stat.h>

#ifndef WIN32

#include <unistd.h>
#include <iostream>

#endif

CLocalSTAVFileReadInterface::CLocalSTAVFileReadInterface()
{
	m_pAvFormat = NULL;
	m_pMediaDescriArry = NULL;
	m_nVideoIndex = -1;
	m_nAudioIndex = -1;
	m_iMediaDesNum = 0;
	m_iFrameInterval = 0;

	m_iFrameIndexList.clear();
	m_iVideoSeq = 1;
	m_iAudioBitRate = 64000;//默认给64K

	m_bHadReadFrame = false;


	av_init_packet(&m_avPakcet);


}

CLocalSTAVFileReadInterface::~CLocalSTAVFileReadInterface()
{
	if ( m_bHadReadFrame )
	{
		av_packet_unref(&m_avPakcet);
		m_bHadReadFrame = false;
	}

	if ( m_pMediaDescriArry )
	{
		delete[]m_pMediaDescriArry;
		m_pMediaDescriArry = NULL;
	}

	Close();
}

void CLocalSTAVFileReadInterface::Release(void)
{
	delete this;
}

int CLocalSTAVFileReadInterface::GetMediaDescriCounts(void)
{
	return m_iMediaDesNum;
}

const StruGSMediaDescri *CLocalSTAVFileReadInterface::GetMediaDescri(int iIndex)
{
	if ( iIndex < 0 || iIndex > m_iMediaDesNum )
		return NULL;
	return &m_pMediaDescriArry[iIndex];
}

int GSGetFileInfo(const char* szFileName, UInt64 *pLastModifiedTime, UInt64 *pFileSize )
{
	if( !szFileName )
	{
		return -6;
	}

	struct stat  f_stat;
	if ( 0 == stat(szFileName, &f_stat))
	{
		if( pFileSize )
		{
			*pFileSize = f_stat.st_size;
		}
		if( pLastModifiedTime )
		{
			*pLastModifiedTime = f_stat.st_mtime;
		}
		return 0;

	}

	if( errno == ENOENT )
	{
		//文件不存在
		return -3;
	}

	if(  errno == EINVAL)
	{
		return -6;
	}
	return -1;
}

//返回文件信息
EnumGSAVFileRetCode CLocalSTAVFileReadInterface::GetInfo(StruGSAVFileInfo *pstInfo)
{
	if ( m_strFileFullName.empty())
	{
		return eAVF_ENOPEN;
	}
	int eOSError = GSGetFileInfo(m_strFileFullName.c_str(), &(pstInfo->iLastModifyTime),
	                                       &(pstInfo->iSize));
	if ( eOSError != 0 )
		return eAVF_EIO;

	if ( m_nVideoIndex != -1 )
	{
		AVStream *st = m_pAvFormat->streams[m_nVideoIndex];
		if ( st )
		{
			Int32 iFrameRate = 10;
			if ( st->time_base.den > 0 && st->time_base.num > 0 )
			{
				iFrameRate = st->time_base.den / st->time_base.num;
			}
			Int64 iFrameNum = st->nb_frames - 1;
			if ( iFrameNum > 0 && iFrameRate > 0 )
				pstInfo->iTimeLength = (1000 / iFrameRate) * iFrameNum / 1000;
			else
				pstInfo->iTimeLength = 30 * 60;//读取失败默认给30分钟的时长?
		}
		return eAVF_SUCCESS;
	}

	return eAVF_EINVALID;
}

EnumGSAVFileRetCode CLocalSTAVFileReadInterface::Close(void)
{
	if ( m_pAvFormat )
	{
		avformat_close_input(&m_pAvFormat);
		m_pAvFormat = NULL;
	}
	return eAVF_SUCCESS;
}

EnumGSAVFileRetCode CLocalSTAVFileReadInterface::SetReadDirection(bool bForward)
{
	return eAVF_NOT_IMPELETE;
}

EnumGSAVFileRetCode CLocalSTAVFileReadInterface::ReadFrame(StruGSAVFrame *pstFrame,
		bool bOnlyVideoKey)
{
	while (true)
	{
		bool bKey = false;
		if ( m_bHadReadFrame )
		{
			av_free_packet(&m_avPakcet);    //先释放上一次读取的数据
			av_init_packet(&m_avPakcet);
			m_bHadReadFrame = false;
		}

		int ret = av_read_frame(m_pAvFormat, &m_avPakcet);
		if (ret >= 0 )
		{
			m_bHadReadFrame = true;

			if ( m_avPakcet.stream_index == m_nVideoIndex )            //视频帧.
			{
				pstFrame->eMediaType = GS_MEDIA_TYPE_VIDEO;
				pstFrame->pMediaData = m_avPakcet.data;
				pstFrame->iMediaDataLen = m_avPakcet.size;
				pstFrame->iTimestamp = m_iVideoSeq * m_iFrameInterval;    //毫秒
				m_iVideoSeq++;
				if ( m_avPakcet.flags == AV_PKT_FLAG_KEY )
				{
					pstFrame->bKeyFrame = 1;
					bKey = true;
				}
				else
				{
					pstFrame->bKeyFrame = 0;
				}
			}
			else if ( m_avPakcet.stream_index == m_nAudioIndex )
			{
				pstFrame->eMediaType = GS_MEDIA_TYPE_AUDIO;
				pstFrame->pMediaData = m_avPakcet.data;
				pstFrame->iMediaDataLen = m_avPakcet.size;
				pstFrame->bKeyFrame = 0;

				if ( m_iAudioBitRate > 0 )
				{
					pstFrame->iTimestamp = (m_avPakcet.pts * 8) * 1000 / m_iAudioBitRate;
				}
				else
				{
					pstFrame->iTimestamp = (m_avPakcet.pts * 8) * 1000 / 64000;
				}
			}
			if ( bOnlyVideoKey && !bKey )
			{
				continue;
			}
			else
			{
				return eAVF_SUCCESS;
			}
		}
		else
		{
			gs_printf("Read frame failed,Result is %d",ret);
			return eAVF_EIO;
		}
	}
}


void CLocalSTAVFileReadInterface::ReadPause(void)
{

}

EnumGSAVFileRetCode CLocalSTAVFileReadInterface::SeekTime(UInt64 iTimestamp, bool bSeekToVideoKey, UInt32 *pRealTimeStamp, Int32 iDirect)
{
	if ( iTimestamp < 0 )
		return eAVF_EINVALID;

	Int32 iFrameIndex = (Int32) (iTimestamp * 1000 / m_iFrameInterval);    //算出帧序号,可能是P帧

	if ( bSeekToVideoKey )
		iFrameIndex = GetIFrameIndex(iFrameIndex);    //指定到I帧序号

	if ( iFrameIndex < 0 )
		return eAVF_ERROR;

	Int64 iStamp = iFrameIndex * m_iFrameInterval * 1000;    //时间戳的单位为毫秒

	if ( !m_pAvFormat )
		return eAVF_ENOPEN;
	Int32 iSeekFlag = AVSEEK_FLAG_BACKWARD;
	if ( bSeekToVideoKey )
		iSeekFlag = AVSEEK_FLAG_BACKWARD;        //测试发现向前找I帧
	else
		iSeekFlag = AVSEEK_FLAG_BACKWARD | AVSEEK_FLAG_ANY;    //不定位到I帧
	Int32 iRet = av_seek_frame(m_pAvFormat, -1, iStamp, iSeekFlag);
	if ( iRet < 0 )
		return eAVF_ERANGE;

	if ( pRealTimeStamp )
	{
		*pRealTimeStamp = iStamp / 1000 / 1000;
	}

	return eAVF_SUCCESS;
}

// 按位置定位
EnumGSAVFileRetCode CLocalSTAVFileReadInterface::SeekPos(UInt64 iPos)
{
	Int32 iRet = av_seek_frame(m_pAvFormat, -1, iPos, AVSEEK_FLAG_BYTE);
	if ( iRet < 0 )
		return eAVF_ERANGE;

	return eAVF_SUCCESS;
}


// 获取当前播放位置
Int64 CLocalSTAVFileReadInterface::GetCurrentPos()
{
	return -1;    // 暂时未实现
}

// 定位到当前位置最近的上一个I帧
EnumGSAVFileRetCode CLocalSTAVFileReadInterface::SeekPreviousIFrame()
{
	return eAVF_NOT_IMPELETE;
}

// 定位到最后一个I帧
EnumGSAVFileRetCode CLocalSTAVFileReadInterface::SeekLastIFrame()
{
	return eAVF_NOT_IMPELETE;
}

static UInt16 CnvAudioFormat2Bit(AVSampleFormat format)
{
	switch (format)
	{
		case AV_SAMPLE_FMT_U8:
			return 8;
		case AV_SAMPLE_FMT_S16:
			return 16;
		case AV_SAMPLE_FMT_S32:
			return 32;
		default:
			return 8;
	}
	return 8;
};

EnumGSAVFileRetCode CLocalSTAVFileReadInterface::OpenFile(char *szFullName, EnumGSAVFileOpenMode eMode)
{
	if ( eMode == eOPEN_READ )
	{
		int err = avformat_open_input(&m_pAvFormat, szFullName, NULL, NULL);

		if ( err < 0 )
		{
			char* errStr= new char[300];
			av_strerror(err,errStr,sizeof(char)*300);
			cout<<errStr<<endl;
			return eAVF_EINVALID;
		}
		av_format_inject_global_side_data(m_pAvFormat);

		err = avformat_find_stream_info(m_pAvFormat, NULL);
		if ( err < 0 )
		{
			return eAVF_EIO;
		}


		Int32 iChnNum = m_pAvFormat->nb_streams;
		m_pMediaDescriArry = new StruGSMediaDescri[iChnNum];
		m_iMediaDesNum = iChnNum;

		for (int i = 0; i < iChnNum; i++)
		{
			AVStream *st = m_pAvFormat->streams[i];
			AVCodecContext *codec = m_pAvFormat->streams[i]->codec;
			if ( codec->codec_type == AVMEDIA_TYPE_VIDEO )
			{
				m_pMediaDescriArry[i].eMediaType = GS_MEDIA_TYPE_VIDEO;
				EnumGSCodeID codeId = AVCodecID2GSCodeID(codec->codec_id);
				if ( codeId == GS_CODEID_NONE )
				{
					if ( codec->codec_tag == (('0' << 24) + ('1' << 16) + ('M' << 8) + ('H')))
						codeId = GS_CODEID_ST_H265;
				}
				m_pMediaDescriArry[i].unDescri.struVideo.eCodeID = codeId;
				if ( st )
				{
					Int32 iFrameRate = 10;
					if ( st->time_base.den > 0 && st->time_base.num > 0 )
						iFrameRate = st->time_base.den / st->time_base.num;

					if ( iFrameRate > 0 )
						m_pMediaDescriArry[i].unDescri.struVideo.iFrameRate = iFrameRate;
					else
						m_pMediaDescriArry[i].unDescri.struVideo.iFrameRate = 10;

					m_iFrameInterval = 1000 / m_pMediaDescriArry[i].unDescri.struVideo.iFrameRate;    //计算帧间隔
				}
				else
				{
					m_pMediaDescriArry[i].unDescri.struVideo.iFrameRate = 10;
					m_iFrameInterval = 100;
				}
				m_pMediaDescriArry[i].unDescri.struVideo.iHeight = codec->height;
				m_pMediaDescriArry[i].unDescri.struVideo.iWidth = codec->width;
				m_nVideoIndex = i;

				//保存I帧索引
				for (Int32 i = 0; i < st->nb_index_entries; i++)
				{
					AVIndexEntry *pAVIndex = &(st->index_entries[i]);
					if ( pAVIndex != NULL && pAVIndex->flags == 1 )
					{
						StruIFrameIndex stFrameIndex;
						stFrameIndex.iTimeStamp = st->index_entries[i].timestamp + 1;
						stFrameIndex.iOffset = st->index_entries[i].pos;
						m_iFrameIndexList.push_back(stFrameIndex);
					}
				}
			}

			if ( codec->codec_type == AVMEDIA_TYPE_AUDIO )
			{
				m_pMediaDescriArry[i].eMediaType = GS_MEDIA_TYPE_AUDIO;
				m_pMediaDescriArry[i].unDescri.struAudio.eCodeID = AVCodecID2GSCodeID(codec->codec_id);
				m_pMediaDescriArry[i].unDescri.struAudio.iSample = codec->sample_rate;
				m_pMediaDescriArry[i].unDescri.struAudio.iBits = CnvAudioFormat2Bit(codec->sample_fmt);
				m_pMediaDescriArry[i].unDescri.struAudio.iChannels = codec->channels;
				m_pMediaDescriArry[i].unDescri.struAudio.iBitRate = codec->bit_rate / 1000;
				if ( m_pMediaDescriArry[i].unDescri.struAudio.iBitRate == 0 )
				{
					if ((unsigned) GS_CODEID_AUDIO_ST_G726 == m_pMediaDescriArry[i].unDescri.struAudio.eCodeID )
					{
						m_pMediaDescriArry[i].unDescri.struAudio.iBitRate = 16;
					}
					else if (
							(unsigned) GS_CODEID_AUDIO_ST_G711U == m_pMediaDescriArry[i].unDescri.struAudio.eCodeID ||
							(unsigned) GS_CODEID_AUDIO_ST_G711A == m_pMediaDescriArry[i].unDescri.struAudio.eCodeID )
					{
						m_pMediaDescriArry[i].unDescri.struAudio.iBitRate = 64;
					}
					else
					{
						m_pMediaDescriArry[i].unDescri.struAudio.iBitRate = 128;
					}
					m_iAudioBitRate = m_pMediaDescriArry[i].unDescri.struAudio.iBitRate * 1000;
				}
				else
				{
					m_iAudioBitRate = codec->bit_rate;
				}

				if(iChnNum ==1)
				{
					/*
					 * 对于这个独立音频的话，这个帧间隔应该是通过扫描时间，得出的间隔。但是因为现在机器人上来的都是G711A，而且扫描间隔都为40ms
					 * 所以写死了25帧，也就是40ms，如果以后写入的格式或者扫描的间隔发生了变化，那这个也需要变，不然找的帧会不正确。
					 * */
					m_iFrameInterval = 40;
				}

				m_nAudioIndex = i;
			}
		}
	}

	m_strFileFullName = szFullName;

	return eAVF_SUCCESS;
}

EnumGSCodeID CLocalSTAVFileReadInterface::AVCodecID2GSCodeID(AVCodecID codeID)
{
	switch (codeID)
	{
		case AV_CODEC_ID_H264:
			return GS_CODEID_ST_H264;
		case AV_CODEC_ID_PCM_ALAW:
			return GS_CODEID_AUDIO_ST_G711A;
		case AV_CODEC_ID_PCM_MULAW:
			return GS_CODEID_AUDIO_ST_G711U;
		case AV_CODEC_ID_MP3:
			return GS_CODEID_ST_MP3;
		case AV_CODEC_ID_ADPCM_G726:
			return GS_CODEID_AUDIO_ST_G726;
		case AV_CODEC_ID_HEVC:
			return GS_CODEID_ST_H265;
		default:
			return GS_CODEID_NONE;
	}
}

Int32 CLocalSTAVFileReadInterface::GetIFrameIndex(Int32 iFrameIndex)
{
	if ( m_iFrameIndexList.empty())
		return -1;

	size_t vecSize = m_iFrameIndexList.size();

	if ( iFrameIndex <= m_iFrameIndexList[0].iTimeStamp )
		return m_iFrameIndexList[0].iTimeStamp;
	else if ( iFrameIndex >= m_iFrameIndexList[vecSize - 1].iTimeStamp )
		return m_iFrameIndexList[vecSize - 1].iTimeStamp;
	else
	{
		for (size_t i = 0; i < vecSize - 1; i++)
		{
			if ( iFrameIndex <= m_iFrameIndexList[i].iTimeStamp && iFrameIndex < m_iFrameIndexList[i + 1].iTimeStamp )
				return m_iFrameIndexList[i].iTimeStamp;
		}
	}
	return -1;
}

EnumGSAVFileRetCode CLocalSTAVFileReadInterface::Repair(void)
{
	return eAVF_SUCCESS;
}

EnumGSAVFileRetCode CLocalSTAVFileReadInterface::RepairGetLastTime(Int64 &tv)
{
	return eAVF_NOT_IMPELETE;
}


CLocalSTAVFileWriteInterface::CLocalSTAVFileWriteInterface()
{
	m_pAvFormat = NULL;
	m_pVideoStream = NULL;
	m_pAudioStream = NULL;
	m_videopts = 0;
	m_audioopts = 0;

}


CLocalSTAVFileWriteInterface::~CLocalSTAVFileWriteInterface()
{
	if ( m_pAvFormat )
	{
		if ( m_pAvFormat->pb )
		{
			av_write_trailer(m_pAvFormat);
			avio_close(m_pAvFormat->pb);
		}
		avformat_free_context(m_pAvFormat);
		m_pAvFormat = NULL;
	}
}

//释放对象
void CLocalSTAVFileWriteInterface::Release(void)
{
	delete this;
}

//关闭文件
EnumGSAVFileRetCode CLocalSTAVFileWriteInterface::Close(void)
{
	if ( m_pAvFormat )
	{
		if ( m_pAvFormat->pb )
		{
			av_write_trailer(m_pAvFormat);
			avio_close(m_pAvFormat->pb);
		}
		avformat_free_context(m_pAvFormat);
		m_pAvFormat = NULL;
	}
	return eAVF_SUCCESS;
}

EnumGSAVFileRetCode CLocalSTAVFileWriteInterface::WriteFrame(const StruGSAVFrame *pstFrame)
{
	Int32 iRet = 0;

	if ( pstFrame->eMediaType == GS_MEDIA_TYPE_VIDEO )
	{
		AVPacket pkt;
		av_init_packet(&pkt);
		if ( pstFrame->bKeyFrame )
			pkt.flags |= AV_PKT_FLAG_KEY;
		pkt.stream_index = m_nVideoIndex;
		pkt.data = (UInt8 *) pstFrame->pMediaData;
		pkt.size = pstFrame->iMediaDataLen;
		pkt.dts = AV_NOPTS_VALUE;
		pkt.pts = AV_NOPTS_VALUE;

		iRet = av_interleaved_write_frame(m_pAvFormat, &pkt);

		av_free_packet(&pkt);

		if ( iRet < 0 )
			return eAVF_EIO;
	}
	else if ( pstFrame->eMediaType == GS_MEDIA_TYPE_AUDIO )
	{
		AVPacket pkt;
		av_init_packet(&pkt);
		pkt.stream_index = m_nAudioIndex;
		pkt.data = (UInt8 *) pstFrame->pMediaData;
		pkt.size = pstFrame->iMediaDataLen;
		pkt.dts = AV_NOPTS_VALUE;
		pkt.pts = AV_NOPTS_VALUE;

		iRet = av_interleaved_write_frame(m_pAvFormat, &pkt);

		av_free_packet(&pkt);

		if ( iRet < 0 )
			return eAVF_EIO;
	}
	else
		return eAVF_EINVALID;

	return eAVF_SUCCESS;
}


EnumGSAVFileRetCode CLocalSTAVFileWriteInterface::CreateFile(const char *czFullFilename, const char *czShortFilename,
		const StruGSMediaDescri *vMediaDescri,
		int nMediaDescriNumber)
{
	GS_ASSERT_RET_VAL(czFullFilename && czShortFilename, eAVF_EINVALID);
	m_strFileFullName = czFullFilename;
	m_strShortFilename = czShortFilename;
	return WriteHeadInfo((char *) czFullFilename, vMediaDescri, nMediaDescriNumber);
}

static enum AVSampleFormat CnvAudioFormat(int iBits)
{
	switch (iBits)
	{
		case 16 :
			return AV_SAMPLE_FMT_S16;
		case 32 :
			return AV_SAMPLE_FMT_S32;
		case 8 :
			return AV_SAMPLE_FMT_U8;
	}
	return AV_SAMPLE_FMT_S16;
};

EnumGSAVFileRetCode CLocalSTAVFileWriteInterface::WriteHeadInfo(char *szFullName, const StruGSMediaDescri *vMediaDescri,
		int nMediaDescriNumber)
{
	if ( !vMediaDescri || nMediaDescriNumber < 1 )
	{
		return eAVF_EINVALID;
	}

	int ret = avformat_alloc_output_context2(&m_pAvFormat, NULL, NULL, szFullName);
	gs_printf("avformat_alloc_output_context2 , result is %d",ret);
	if ( ret < 0 )
	{
		return eAVF_EINVALID;
	}

	AVStream *pAvStream = NULL;

	for (int i = 0; i < nMediaDescriNumber; i++)
	{
		pAvStream = avformat_new_stream(m_pAvFormat, NULL);

		if ( pAvStream )
		{
			auto enc_ctx = pAvStream->codecpar;

			if ( vMediaDescri[i].eMediaType == GS_MEDIA_TYPE_VIDEO )
			{
				m_pVideoStream = pAvStream;
				m_nVideoIndex = pAvStream->index;
				enc_ctx->codec_id = GSCodeID2AVCodecID((EnumGSCodeID) vMediaDescri[i].unDescri.struVideo.eCodeID);
				enc_ctx->codec_type = AVMEDIA_TYPE_VIDEO;
				enc_ctx->width = vMediaDescri[i].unDescri.struVideo.iWidth;
				enc_ctx->height = vMediaDescri[i].unDescri.struVideo.iHeight;
				if ( enc_ctx->width < 1 || enc_ctx->height < 1 )
				{
					enc_ctx->width = 1024;
					enc_ctx->height = 720;
				}
				enc_ctx->bit_rate = enc_ctx->width * enc_ctx->height * 4;
				enc_ctx->format = AV_PIX_FMT_YUV420P;

				if ( enc_ctx->codec_id == AV_CODEC_ID_HEVC )
				{
					enc_ctx->codec_tag = (('0' << 24) + ('1' << 16) + ('M' << 8) + ('H'));
				}

				pAvStream->time_base = (AVRational) {1, vMediaDescri[i].unDescri.struVideo.iFrameRate};

			}
			else if ( vMediaDescri[i].eMediaType == GS_MEDIA_TYPE_AUDIO )
			{
				m_pAudioStream = pAvStream;
				m_nAudioIndex = pAvStream->index;

				enc_ctx->codec_id = GSCodeID2AVCodecID((EnumGSCodeID) vMediaDescri[i].unDescri.struAudio.eCodeID);
				enc_ctx->codec_type = AVMEDIA_TYPE_AUDIO;
				enc_ctx->format = CnvAudioFormat(vMediaDescri[i].unDescri.struAudio.iBits);
				enc_ctx->sample_rate = vMediaDescri[i].unDescri.struAudio.iSample;
				enc_ctx->channels = vMediaDescri[i].unDescri.struAudio.iChannels;
				enc_ctx->bit_rate = vMediaDescri[i].unDescri.struAudio.iBitRate * 1000;

				if ( enc_ctx->sample_rate < 1 )
				{
					enc_ctx->sample_rate = 8000;
				}

				if ( enc_ctx->channels < 1 )
				{
					enc_ctx->channels = 1;
				}

				if ( enc_ctx->bit_rate == 0 )
				{

					if ((EnumGSCodeID) vMediaDescri[i].unDescri.struAudio.eCodeID == GS_CODEID_AUDIO_ST_G726 )
					{
						enc_ctx->bit_rate = 16000;
					}
					else if ( GS_CODEID_AUDIO_ST_G711A == (EnumGSCodeID) vMediaDescri[i].unDescri.struAudio.eCodeID ||
					          GS_CODEID_AUDIO_ST_G711U == (EnumGSCodeID) vMediaDescri[i].unDescri.struAudio.eCodeID )
					{
						enc_ctx->bit_rate = 128000;
					}
					else
					{
						enc_ctx->bit_rate =
								enc_ctx->sample_rate * vMediaDescri[i].unDescri.struAudio.iBits * enc_ctx->channels;
					}
				}

				pAvStream->time_base = (AVRational) {1, 25};//使用G711A的采样频率来作为流的帧率，当前采样频率为40ms，也就是1s25帧。
			}
		}
	}

	ret = avio_open(&m_pAvFormat->pb, szFullName, AVIO_FLAG_WRITE);
	gs_printf("avio_open , result is %d",ret);
	if ( ret < 0 )
	{
		return eAVF_EINVALID;
	}


	ret = avformat_write_header(m_pAvFormat, NULL);

	gs_printf("avformat_write_header , File name : %d",ret);

	if ( ret < 0 )
	{
		avio_close(m_pAvFormat->pb);
		m_pAvFormat->pb = NULL;
		return eAVF_EINVALID;
	}

	return eAVF_SUCCESS;
}

AVCodecID CLocalSTAVFileWriteInterface::GSCodeID2AVCodecID(EnumGSCodeID codeID)
{
	switch (codeID)
	{
		case GS_CODEID_ST_H264:
			return AV_CODEC_ID_H264;
		case GS_CODEID_AUDIO_ST_G711A:
			return AV_CODEC_ID_PCM_ALAW;
		case GS_CODEID_AUDIO_ST_G711U:
			return AV_CODEC_ID_PCM_MULAW;
		case GS_CODEID_AUDIO_ST_G726:
			return AV_CODEC_ID_ADPCM_G726;
		case GS_CODEID_ST_MP3:
			return AV_CODEC_ID_MP3;
		case GS_CODEID_ST_H265:
			return AV_CODEC_ID_HEVC;
		default:
			return AV_CODEC_ID_NONE;
	}
}

//返回完整目录名
const char *CLocalSTAVFileWriteInterface::GetFullFilename(void)
{
	return m_strFileFullName.c_str();
}

//返回相对目录名
const char *CLocalSTAVFileWriteInterface::GetShortFilename(void)
{
	return m_strShortFilename.c_str();
}


//返回文件大小
EnumGSAVFileRetCode CLocalSTAVFileWriteInterface::GetSize(UInt64 &iFileSize)
{
	struct stat f_stat;
	if ( stat(m_strFileFullName.c_str(), &f_stat) != -1 )
	{
		iFileSize = f_stat.st_size;
		return eAVF_SUCCESS;
	}
	return eAVF_EIO;
}