/*
******************************************
Copyright (C), 2010-2011, GOSUN
Filename : GSMEDIADEFS.H
Author :  zouyx
Version : 0.1.0.0
Date: 2010/7/22 9:15
Description: �����ý���õ���һЩ����
********************************************
*/
#ifndef GSP_GSMEDIADEFS_DEF_H
#define GSP_GSMEDIADEFS_DEF_H

#include "GSTypes.h"
#include "GSStreamCodeID.h"

//�ṹΪ���ֽڶ���
#ifdef _WIN32
#define GS_MEDIA_ATTRIBUTE_PACKED 
#pragma pack( push,1 )
#else
#define GS_MEDIA_ATTRIBUTE_PACKED    __attribute__ ((packed)) 
#endif


/*
****************************************
brief : �����������
****************************************
*/
/*
typedef enum
{
    GS_CODEID_NONE = 0, //�ޱ�������
    GS_CODEID_BINARY,   //�����Ʊ���

	GS_CODEID_GS_PS,	// GOSUN PS ��̬����


    //��׼��Ƶ���� 
    GS_CODEID_ST_MP4        = 0x00000010,       //��׼�� MP4 ����
    GS_CODEID_ST_H264,                          //��׼�� H264 ����
	GS_CODEID_ST_SVAC,                           //��׼�� SVAC ����
 
    //��׼��Ƶ����
    GS_CODEID_ST_MP3        = 0x00000300,       //��׼MP4
	GS_CODEID_AUDIO_ST_PCM,	
	GS_CODEID_AUDIO_ST_G711A,
	GS_CODEID_AUDIO_ST_G711U,
	GS_CODEID_AUDIO_ST_G721,
	GS_CODEID_AUDIO_ST_G722,
	GS_CODEID_AUDIO_ST_G723,
	GS_CODEID_AUDIO_ST_G729,
	GS_CODEID_AUDIO_ST_H263,
	GS_CODEID_AUDIO_ST_SVAC,

	GS_CODEID_PS = 0x00000400,


    //��׼ͼ�����
    GS_CODEID_ST_JPEG       = 0x00000600,         //��׼JPG
    GS_CODEID_ST_BMP,                             //��׼JPG
    GS_CODEID_ST_YUV420P,                         //��׼YUV420P


    //�����̽��е��������



    //=====��������
    GS_CODEID_GS_V2160I     = 0x00001000,       // GOSUN 2160I ��Ƶ����
    GS_CODEID_GS_A2160I,                        // GOSUN 2160I ��Ƶ����
    GS_CODEID_GS_V462C,                         //GOSUN BASS462C ��Ƶ����
    GS_CODEID_GS_A462C,                         //GOSUN BASS462C ��Ƶ����
    GS_CODEID_GS_V461C,                         //GOSUN BASS461C ��Ƶ����
    GS_CODEID_GS_A461C,                         //GOSUN BASS461C ��Ƶ����
	GS_CODEID_GS_V461A,                         //GOSUN BASS461A ��Ƶ����
	GS_CODEID_GS_V2160IV,						// GOSUN 2160I_V ��Ƶ����
	GS_CODEID_GS_A2160IV,                       // GOSUN 2160I_V ��Ƶ����
	GS_CODEID_GS_VIPC,							// GOSUN IPC	 ��Ƶ����
	GS_CODEID_GS_AIPC,							// GOSUN IPC	 ��Ƶ����
	

    //===== ��ʨ 
    GS_CODEID_HI_VDEFAULT   = 0x00001200,        //��ʨ����Ƶͨ�ñ���
    GS_CODEID_HI_ADEFAULT,                      //��ʨ����Ƶͨ�ñ���
    GS_CODEID_HI_VH264,                         //��ʨ H264
    GS_CODEID_HI_VMP4,                          //��ʨ H264
    GS_CODEID_HI_COMPLEX,                          //��ʨ����ͨ�ñ���


    //===== ����
    GS_CODEID_HK_VDEFAULT    = 0x00001300,      //��������Ƶͨ�ñ���
    GS_CODEID_HK_ADEFAULT,                      //��������Ƶͨ�ñ���
    GS_CODEID_HK_VMP4,                          //���� MP4
    GS_CODEID_HK_VH264,                         //���� H264
    GS_CODEID_HK_COMPLEX,                       //��������ͨ�ñ���




    //===== ��
    GS_CODEID_DH_VDEFAULT    = 0x00001400,      //�󻪵���Ƶͨ�ñ���
    GS_CODEID_DH_ADEFAULT ,                     //�󻪵���Ƶͨ�ñ���
    GS_CODEID_DH_VMP4,                          //�� MP4
    GS_CODEID_DH_VH264,                         //�� H264
    GS_CODEID_DH_COMPLEX,                       //�󻪸���ͨ�ñ���

    //===== ����
    GS_CODEID_HY_VDEFAULT   = 0x00001500,       //�������Ƶͨ�ñ���
    GS_CODEID_HY_ADEFAULT,                      //�������Ƶͨ�ñ���
    GS_CODEID_HY_VMP4,                          //���� MP4
    GS_CODEID_HY_VH264,                         //���� H264
    GS_CODEID_HY_COMPLEX,                       //���渴��ͨ�ñ���


	//=====�ֻ�
	GS_CODEID_WM_XVID		= 0x00001600,		//�ֻ��ͻ��˽���1,̷־���Ӳ���

	// ===== �ƺ�
	GS_COIDEID_HH_VDEFULT   = 0x00001700,       //�ƺӵ���Ƶͨ�ñ���

	// ===== �б�
	GS_CODEID_ZBEN_VDEFULT  = 0x00001800,       //�б�����Ƶ����
	GS_CODEID_ZBEN_ADEFULT,                     //�б�����Ƶ����

	// ===== �߿���
	GS_CODEID_CALSYS_VDEFULT = 0x00001900,         //�߿��ӵ���Ƶͨ�ñ��� 
	GS_CODEID_CALSYS_ADEFULT,                      //�߿��ӵ���Ƶͨ�ñ���

    // ==== ��������
	GS_COIDEID_ALRS_VDEFULT   = 0x00002000,       //�������ӵ���Ƶͨ�ñ���

	// ====  Ѷ��
    GS_CODEID_XM_VDEFULT   = 0x00002100,          //Ѷ����Ƶͨ�ñ���

   // ====  �߿���GS76xxϵ��
    GS_CODEID_CALSYSGS76XX_VDEFULT = 0x00002200,         //�߿���GS76XX����Ƶͨ�ñ��� 
	
	//
	GS_CODEID_MEDIA = 0x00002300,
	// === FFmpeg�������
	GS_CODEID_GSVIDEO = 0x00002400,

    GS_CODEID_END,   //���ڽ�β 


}EnumGSCodeID;
*/







/*
****************************************
brief : ����ý������
****************************************
*/
typedef enum 
{
    GS_MEDIA_TYPE_NONE = 0,           //δ֪ý������
    GS_MEDIA_TYPE_VIDEO = 0x01,   //��Ƶ��, ��������  StruVideoDescri
    GS_MEDIA_TYPE_AUDIO,            //��Ƶ��, ��������  StruAudioDescri
    GS_MEDIA_TYPE_PICTURE,          //ͼƬ����,�������� StruPictureDescri
    GS_MEDIA_TYPE_OSD,              //OSD ����,�������� StruOSDDescri
    GS_MEDIA_TYPE_BINARY,          //��������, ��������  StruBinaryDescri   
	GS_MEDIA_TYPE_PROGRESS,        //���ȣ��������� StruPlayStatus
	GS_MEDIA_TYPE_RECORD_INFO,     //¼����Ϣ���������� GSStruRecordInfo
	GS_MEDIA_TYPE_IFRAME_INDEX,   //I֡������ ����Ϊ���������� �ṹ�ο� GMFDefs.h ����
	GS_MEDIA_TYPE_FILE_TO_END,    //�ļ�����

	GS_MEDIA_TYPE_SAS_INFO,    // �ṹ����Ϣ �������ݲο��ṹ����Ϣ�ṹ
	GS_MEDIA_TYPE_SEI,         //��ǿ��Ϣ

	GS_MEDIA_TYPE_USER_END,		   //������Ϣ�� ����ͳ��

	GS_MEDIA_TYPE_GOP_TO_END,		   //GOP������־

    GS_MEDIA_TYPE_SYSHEADER = 0x40,         //��Ϣͷ
	GS_MEDIA_TYPE_COMPLEX,			//��������
}EnumGSMediaType;


/*
****************************************
brief :  ¼����Ϣ����
****************************************
*/
typedef struct _GSStruRecordInfo
{
	UInt32 iType;              // 1��ʼ 0����
	unsigned char szTime[16];  // ʱ��: 20111013194000 
}GS_MEDIA_ATTRIBUTE_PACKED GSStruRecordInfo;
#define TYPE_RECORD_END   0
#define TYPE_RECORD_START 1

/*
****************************************
brief :  ��Ƶ����Ϣ����
****************************************
*/

typedef struct _StruVideoDescri
{
    UInt32 eCodeID;  //��������   EnumGSCodeID
    UInt16 iWidth;         //ͼ���         0 ��ʾ��Ч
    UInt16 iHeight;       //ͼ���          0 ��ʾ��Ч
    UInt8 iFrameRate;    //֡�� ��������    0 ��ʾ��Ч
    UInt8 iFrameRate2;    //֡�� С������   �ٷֱ� 
    UInt16 iReserver;      //������
}GS_MEDIA_ATTRIBUTE_PACKED StruVideoDescri;

/*
****************************************
brief :  ��Ƶ����Ϣ����
****************************************
*/
typedef struct _StruAudioDescri
{
    UInt32 eCodeID;    //��������   EnumGSCodeID
    UInt32 iSample;    //����Ƶ�� Hz         0 ��ʾ��Ч
    UInt16 iBits;      //����λ��  0 ��ʾ��Ч
	UInt8 iChannels;  //ͨ����     0 ��ʾ��Ч
	UInt8 iBitRate;   //���ʣ� ��λ kbits/s  0 ��ʾ��Ч, �� 16 ��ʾ  16kbits/s, 64 ��ʾ 64kbits/s   
}GS_MEDIA_ATTRIBUTE_PACKED StruAudioDescri;

/*
****************************************
brief : ͼƬ��Ϣ����
****************************************
*/
typedef struct _StruPictureDescri
{
    UInt32 eCodeID;    //��������   EnumGSCodeID
}GS_MEDIA_ATTRIBUTE_PACKED StruPictureDescri;


/*
****************************************
brief :  OSD��Ϣ����
****************************************
*/
//OSD ����������  ���ַ���
#define GS_OSD_TYPE_STRING  0x01   
//OSD ����������  ��RGB����
#define GS_OSD_TYPE_RBG     0x02   

typedef struct _StruOSDDescri
{
    UInt16 iPosX; //��ʼ��X����, �����ͼƬ���Ͻ�
    UInt16 iPosY; //��ʼ��Y����, �����ͼƬ���Ͻ�
    UInt8 iDataType; //��������     �ο� GS_OSD_TYPE_xxx
    UInt8 iTransparency; //͸����  0~100    0 ��ʾ��ȫ͸���� 100 ��ʾ��ȫ��͸��
}GS_MEDIA_ATTRIBUTE_PACKED StruOSDDescri;

/*
****************************************
brief : ��������������
****************************************
*/
typedef struct _StruBinaryDescri
{
    UInt64 iSize;  //�������������ĳ��ȣ� 0 ��ʾ���޳�
}GS_MEDIA_ATTRIBUTE_PACKED StruBinaryDescri;

/*
****************************************
brief : ��Ϣͷ��������
****************************************
*/
typedef struct _StruSysHeader
{
    UInt32 iSize; //��ʾ��Ϣͷ�ĳ��ȣ� 0 ��ʾδ֪ 	
}GS_MEDIA_ATTRIBUTE_PACKED StruSysHeaderDescri;

/*
****************************************
brief : ý��������װ
****************************************
*/
typedef union 
{
    StruVideoDescri struVideo;
    StruAudioDescri struAudio;
    StruPictureDescri struPicture;
    StruOSDDescri struOsd;
    StruBinaryDescri struBinary;
    StruSysHeaderDescri struSysHeader;
}UnionMediaDescri;


/*
****************************************
brief :  ��ý��������װ
****************************************
*/
typedef struct _StruGSMediaDescri
{
    UInt32  eMediaType;  //ý������ EnumGSMediaType
    UnionMediaDescri unDescri;  //ý������
}GS_MEDIA_ATTRIBUTE_PACKED StruGSMediaDescri;


/*
****************************************
brief :  ����ý�塢�洢֡��ʽ��װ
**************************************** 
����(3Bytes)|�Ƿ�ؼ�֡(1bytes)|ý������(7bytes)|ʱ����4Bytes)| ����... 
*/
#define INVALID_TIME_STAMP ((UInt32)-1)
#define GS_FRAME_HEADER_MAGIC  (('G'<<24) | ('s'<<16) | ('c'<<8) | 'N') 

   
typedef struct _StruGSFrameHeader
{
    UInt32 iMagic;        //ħ���֣� ���ڱ�ʶÿ֡�Ŀ�ͷ
    UInt32 iLenght : 24;  //���ݳ��ȣ� ����������ͷ , ָ aFrameData����
    UInt32 bKey : 1;      //�Ƿ��ǹؼ�֡
    UInt32 eMediaType : 7;  //ý������
    UInt32 iTimeStamp;      //ʱ���   (-1) Ϊ��Чʱ��� INVALID_TIME_STAMP // (��1970��1��1��0ʱ0��0�뵽��ʱ������) modified by jiangsx 20121213
    //   unsigned char aFrameData[];  //֡����
}GS_MEDIA_ATTRIBUTE_PACKED StruGSFrameHeader;

typedef struct _StruGSFrameHeaderV2
{
	UInt32 iMagic;        //ħ���֣� ���ڱ�ʶÿ֡�Ŀ�ͷ
	UInt32 iLenght : 24;  //���ݳ��ȣ� ����������ͷ , ָ aFrameData����
	UInt32 bKey : 1;      //�Ƿ��ǹؼ�֡
	UInt32 eMediaType : 7;  //ý������
	UInt32 iTimeStamp;      //ʱ���   (-1) Ϊ��Чʱ��� INVALID_TIME_STAMP // (��1970��1��1��0ʱ0��0�뵽��ʱ������) modified by jiangsx 20121213
	UInt32 iDurationStamp:31;		// ����
	UInt32 iValid:1;			// ��ʾiDurationStamp�Ƿ���Ч  1����Ч   0����Ч
	//   unsigned char aFrameData[];  //֡����

}GS_MEDIA_ATTRIBUTE_PACKED StruGSFrameHeaderV2;


#define  GS_NUM_DATA_POINTERS  8  

//ͼ������
typedef struct StruGSVideoRawFrameInfo
{
	UInt8  *pData[GS_NUM_DATA_POINTERS];		//�ֱ��ʾYUV��������
	Int32   nDataLen[GS_NUM_DATA_POINTERS];     //�ֱ��ʾYUV�����������ݴ�С
	Int32   nStride[GS_NUM_DATA_POINTERS];	    //�ֱ��ʾYUV���������Ŀ��
	
	StruVideoDescri stDescri;                   //����
	UInt64  nTimestamp;		  //ʱ���

}GS_MEDIA_ATTRIBUTE_PACKED StruGSVideoRawFrameInfo;


typedef enum EnumSampleFmt
{
	Sample_Fmt_None = -1,//����������Ƶ�����ʽʱ�������Sample_Fmt_None���򲻸ı�ԭʼ��Ƶ��ȡֵ��ʽ
	Sample_Fmt_unsigned,
	Sample_Fmt_signed,
	Sample_Fmt_float,
	Sample_Fmt_double,
}EnumSampleFmt;

typedef struct StruDecAudioDescri
{
	int bPlanar; //�����������Ƿ�ƽ��ֲ���0���񣻷�0���ǡ�
	EnumSampleFmt eSampleFmt;
	StruAudioDescri stDescri; //��Ƶ����
}StruDecAudioDescri;


//��Ƶ����
//���pcm��ƽ��ֲ��ģ���ô�ж���ͨ����pData��ǰ���ٸ�Ԫ�ؾͲ�Ϊ��ָ�룬nDataLenΪÿ��ͨ�������ݴ�С����2��ͨ���������
//      |------nDataLen----|
//		[LLLLLLLLLLLLLLLLLL]
//		[RRRRRRRRRRRRRRRRRR]
//		NULL
//      ... 
//���pcm����ƽ��ֲ���,��ôpDataֻ�е�һ��Ԫ�طǿգ�nDataLenΪpData��һ��Ԫ�صĳ��ȡ���2��ͨ���������
//	    |-------------nDataLen-------------|
//		[LRLRLRLRLRLRLRLRLRLRLRLRLRLRLRLRLR]
//		NULL
//      ... 
typedef struct StruGSAudioRawFrameInfo
{
	UInt8  *pData[GS_NUM_DATA_POINTERS];            //����
	Int32   nDataLen[GS_NUM_DATA_POINTERS];//���ݴ�С
	
	StruDecAudioDescri stDecDescri; //����
	UInt64  nTimestamp;		  //ʱ���

}GS_MEDIA_ATTRIBUTE_PACKED StruGSAudioRawFrameInfo;


//SEI����
typedef struct StruGSSEIInfo 
{
	UInt8  *pData[GS_NUM_DATA_POINTERS];           //����
	Int32   nDataLen[GS_NUM_DATA_POINTERS];	   //���ݴ�С

}GS_MEDIA_ATTRIBUTE_PACKED StruGSSEIInfo;


typedef struct StruGSRawFrameInfo
{	
	EnumGSMediaType  eMediaType;
	union
	{
		StruGSVideoRawFrameInfo  stVideo;   //��Ƶ
		StruGSAudioRawFrameInfo  stAudio;   //��Ƶ
		StruGSSEIInfo            stSEI;     //��ǿ��Ϣ
	}frame;

}GS_MEDIA_ATTRIBUTE_PACKED StruGSRawFrameInfo;


typedef struct StruGSFrameData
{
	UInt8  *pData;            //����
	Int32   nDataLen;		  //���ݳ���

	UInt64  nTimestamp;		  //ʱ���	

}GS_MEDIA_ATTRIBUTE_PACKED StruGSFrameData;

/*
*********************************************************************
*
*@brief : GS_CODEID_GS_PS ����װ��֡ͷ
*
*********************************************************************
*/
typedef struct _StruGSPSFrameHeader
{
#define GSPSFRAMEHEADER_MAGIC  0x10000000
#define GSPSFRAMEHEADER_MARK1  (('G'<<0) | ('S'<<8))
#define GSPSFRAMEHEADER_MARK2  (('P'<<0) | ('S'<<8))

#define GSPS_CODETYPE_NONE 0x00


#define GSPS_CODETYPE_V_H264	0x1B
#define GSPS_CODETYPE_V_MP4		0x10
#define GSPS_CODETYPE_V_SVAC	0x80

#define GSPS_CODETYPE_A_G711	0X90
#define GSPS_CODETYPE_A_G722	0X92
#define GSPS_CODETYPE_A_G723 0X93
#define GSPS_CODETYPE_A_G729 0X99
#define GSPS_CODETYPE_A_SVAC 0X9B

	//���� GSPSFRAMEHEADER_MAGIC 
	UInt32 iMagic;
	 // ���� 0xFFFF
	UInt16 iLabel;
	 //��  GSPSFRAMEHEADER_MARK1
	UInt16 iGSMark1;
	//��   GSPSFRAMEHEADER_MARK2
	UInt16 iGSMark2; 
	//��������, �ο� GB28181 PS ��װ����
	UInt8  iCodeType; 
	//���� �Ƿ�ؼ�֡
	UInt8  bKey : 1;  
	//���� 0xF7	
	UInt8  iReserver : 7;  
	//
	UInt64 iTimestamp;
} GS_MEDIA_ATTRIBUTE_PACKED StruGSPSHeader;

#define GSPSHEADER_INIT(h, streamtype, xbKey) \
do { \
 (h).iMagic = GSPSFRAMEHEADER_MAGIC; \
 (h).iLabel = 0xFFFF; \
 (h).iGSMark1 = GSPSFRAMEHEADER_MARK1; \
 (h).iGSMark2 = GSPSFRAMEHEADER_MARK2; \
 (h).iCodeType = (streamtype); \
 (h).bKey = ((xbKey) ? 1&0x1 : 0); \
 (h).iReserver = 0xF7; (h).iTimestamp=(UInt64)-1; }while(0)

#define IS_GSPSHEADER(h) \
	((h).iMagic==GSPSFRAMEHEADER_MAGIC && (h).iLabel==0xFFFF && \
	 (h).iGSMark1==GSPSFRAMEHEADER_MARK1 && (h).iGSMark2==GSPSFRAMEHEADER_MARK2)

#ifdef _WIN32
#pragma pack( pop )
#endif


INLINE static  EnumGSMediaType CodeID2MediaType( EnumGSCodeID codeID)
{
    switch( codeID)
    {
    case GS_CODEID_NONE :
        return GS_MEDIA_TYPE_NONE;
        break;
    case GS_CODEID_BINARY :
        return GS_MEDIA_TYPE_BINARY;
        break;

        //��Ƶ����
    case GS_CODEID_GS_V2160I:
    case GS_CODEID_GS_V462C:
    case GS_CODEID_GS_V461C:
	case GS_CODEID_GS_V461A:
	case GS_CODEID_GS_V2160IV:
	case GS_CODEID_GS_VIPC:

    case GS_CODEID_HI_VDEFAULT:
    case GS_CODEID_HI_VMP4:
    case GS_CODEID_HI_VH264:
    case GS_CODEID_HI_COMPLEX :

    case GS_CODEID_HK_VDEFAULT:
    case GS_CODEID_HK_VMP4:
    case GS_CODEID_HK_VH264:
    case GS_CODEID_HK_COMPLEX :

    case GS_CODEID_DH_VDEFAULT:
    case GS_CODEID_DH_VMP4:
    case GS_CODEID_DH_VH264:
    case GS_CODEID_DH_COMPLEX :

    case GS_CODEID_HY_VDEFAULT:
    case GS_CODEID_HY_VMP4:
    case GS_CODEID_HY_VH264:
    case GS_CODEID_HY_COMPLEX :

	case GS_COIDEID_HH_VDEFULT :

	case GS_CODEID_ZBEN_VDEFULT:

	case GS_CODEID_CALSYS_VDEFULT:

	case GS_COIDEID_ALRS_VDEFULT:

	case GS_CODEID_XM_VDEFULT:

	case GS_CODEID_PS:
	case GS_CODEID_GS_PS:
	case GS_CODEID_MEDIA:
	case GS_CODEID_GSVIDEO:
	case GS_CODEID_VSR:
	case GS_CODEID_JG_VDEFULT:
	case GS_CODEID_PACOM_VDEFULT:
		return GS_MEDIA_TYPE_VIDEO;
        break;

        //��Ƶ����
    case GS_CODEID_GS_A2160I:
    case GS_CODEID_GS_A462C:
    case GS_CODEID_GS_A461C:
    case GS_CODEID_GS_A2160IV:
	case GS_CODEID_GS_AIPC:

    case GS_CODEID_HI_ADEFAULT: 

    case GS_CODEID_HK_ADEFAULT :

    case GS_CODEID_DH_ADEFAULT :

    case GS_CODEID_HY_ADEFAULT :

	case GS_CODEID_ZBEN_ADEFULT:

	case GS_CODEID_CALSYS_ADEFULT:

	case GS_CODEID_JG_ADEFULT:
	case GS_CODEID_PACOM_ADEFULT:

        return GS_MEDIA_TYPE_AUDIO;
        break;
		
    default :
        if( codeID>=GS_CODEID_ST_MP4 && codeID<GS_CODEID_ST_MP3)
        {
            return GS_MEDIA_TYPE_VIDEO;
        }
        else if( codeID>=GS_CODEID_ST_MP3 && codeID<GS_CODEID_ST_JPEG )
        {
            return GS_MEDIA_TYPE_AUDIO;
        }
        else if( codeID>=GS_CODEID_ST_JPEG && codeID<GS_CODEID_GS_V2160I )
        {
            return GS_MEDIA_TYPE_PICTURE;
        }
        break;
    }
    return GS_MEDIA_TYPE_NONE;
}







// �����������������ȡ
// dzz - 2018-6-5


//��Ƶ�������
typedef struct _StruEncodeVideoParam
{	
	EnumGSCodeID  code_id;      //��������   EnumGSCodeID
	UInt16  width;        //ͼ���       
	UInt16  height;       //ͼ���        
	Int16   frame_rate;   //ͼ��֡��
	Int16   gop_size;     //I֡���
	Int16   max_b_frames; //��B֡������B֡����Ĭ��Ϊ0
}StruEncodeVideoParam;


//��Ƶ�������
typedef struct _StruEncodeAudioParam
{
	EnumGSCodeID  code_id;    //��������   EnumGSCodeID
	UInt32          sample;        //����Ƶ�� Hz        
	UInt16          bits;          //����λ��  
	UInt8           channels;      //ͨ����    
	UInt8           bit_rate;      //���ʣ� ��λ kbits/s  0 ��ʾ��Ч, �� 16 ��ʾ  16kbits/s, 64 ��ʾ 64kbits/s .Ŀǰ��Ч
}StruEncodeAudioParam;


//��Ƶ����
typedef struct _StruEncodeVideoDescri
{
	EnumGSCodeID  code_id;      //��������   EnumGSCodeID
	Int16	width;		  //ͼ���
	Int16 	height;		  //ͼ���
	Int16   frame_rate;   //ͼ��֡��,�����ڱ���ص�
	Int16   frame_type;   //֡����,�����ڱ���ص���0ΪP֡��1ΪI֡��2ΪB֡
}StruEncodeVideoDescri;


//��Ƶ����
typedef struct _StruEncodeAudioDescri
{ 
	EnumGSCodeID          code_id;       //��������   EnumGSCodeID
	UInt32          sample;        //����Ƶ�� Hz        
	UInt16          bits;          //����λ��  
	UInt8           channels;      //ͨ����    
	UInt8           bit_rate;      //���ʣ� ��λ kbyts/s  0 ��ʾ��Ч, �� 16 ��ʾ  16kbits/s, 64 ��ʾ 64kbits/s   
}StruEncodeAudioDescri;

//���������������
typedef struct _StruEncodeOutputFrameInfo
{	
	UInt32  media_type;   //EnumGSMediaType
	union
	{
		StruEncodeVideoDescri video; //��Ƶ����
		StruEncodeAudioDescri audio; //��Ƶ����
	}descri;
	UInt64 nTimeStamp;//ms
}StruEncodeOutputFrameInfo;



//////////////////////////////////////////////////////////////////////////

// ����Ӳ��ṹ����Ϣ [6/7/2018 zhangxinxiang]
typedef enum
{
	OCT_INTEL_MFX=0x00,
	OCT_NVIDIA_CUDA=0x10,
}EnumDecOriginContextType;

//��������EnumDeviceTypeΪEnumDecDeviceType [8/23/2018 linwucheng]
typedef enum
{
	DT_D3D9=0x00,
	DT_D3D9EX,
	DT_D3D11,
	DT_CUDA=0x20,
}EnumDecDeviceType;

typedef struct
{
	void*			pInter;
	void*			pDevice;		//D3D��device
	EnumDecDeviceType	eDeviceType;
	Int16			sReserve;
}StruGSDecIntelMFXContext;

typedef struct
{
	void* hDevice;				//cuda��device
	void* pCtx;					//cuda��context
	void* pSource;
	void* pDecoder;
	void* pParser;
	void* pFrameQueue;
	void* pStream;
	void* pLockCtx;
	EnumDecDeviceType eDeviceType; 

	Int16 sReserve;
}StruGSDecNvidiaCUDAContext;

typedef struct
{
	EnumDecOriginContextType nType;
	void* pRawFrame;
	StruVideoDescri stVideoDescri;
	Int64 lTimeStamp;
	Int16 sReserve;
}StruGSHWDecRawFrame;

typedef struct
{
	StruGSDecIntelMFXContext* pCtx;
	Int64			sourceID;	//��Դָ�룬Ŀǰ������surfaceָ��
	Int32			sourceType;	//0:surface,1:texture
	EnumGSCodeID	codeID;		//fourCC
	Int16			sReserve;	

}StruGSHWDecRawIntelMFXVideoMemFrame;

typedef struct
{
	StruGSDecNvidiaCUDAContext* pCtx;
	//NVIDIA��Ϣ������
}StruGSDecRawNvidiaCUDAVideoMemFrame;

#endif
