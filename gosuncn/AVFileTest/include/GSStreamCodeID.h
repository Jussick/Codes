/*******************************************************************************
  Copyright (C), 2010-2014, GOSUNCN 
  File name   : GSSTREAMCODEID.H      
  Author      : 江盛欣      
  Version     : 1.0.0        
  DateTime    : 2015/4/2 9:49
  Description : 媒体流编码定义
*******************************************************************************/

#ifndef GSSTREAMCODEID_DEF_H
#define GSSTREAMCODEID_DEF_H


/*
****************************************
brief : 定义编码类型
****************************************
*/
typedef enum
{
    GS_CODEID_NONE = 0, //无编码类型
    GS_CODEID_BINARY,   //二进制编码

	GS_CODEID_GS_PS,	// GOSUN PS 动态码流


    //标准视频编码 
    GS_CODEID_ST_MP4        = 0x00000010,       //标准的 MP4 编码
    GS_CODEID_ST_H264,                          //标准的 H264 编码
	GS_CODEID_ST_SVAC,                          //标准的 SVAC 编码
	GS_CODEID_ST_H265,                          //标准的 H265 编码
	GS_CODEID_ST_H263,                          //标准的 H263 编码
	GS_CODEID_ST_MPEG2,
	GS_CODEID_ST_MPEG1,	
	GS_CODEID_ST_MJPG,
	GS_CODEID_FCC_MPEG4,
	GS_CODEID_MS_MPEG4,
	GS_CODEID_ST_FLV1,
	GS_CODEID_ST_WMV1,
	GS_CODEID_ST_WMV2,
	GS_CODEID_ST_WMV3,
 
    //标准音频编码
    GS_CODEID_ST_MP3        = 0x00000300,       //标准MP4
	GS_CODEID_AUDIO_ST_PCM,	
	GS_CODEID_AUDIO_ST_G711A,
	GS_CODEID_AUDIO_ST_G711U,
	GS_CODEID_AUDIO_ST_G721,
	GS_CODEID_AUDIO_ST_G722,
	GS_CODEID_AUDIO_ST_G723,
	GS_CODEID_AUDIO_ST_G726,					//默认G726_16
	GS_CODEID_AUDIO_ST_G729,
	GS_CODEID_AUDIO_ST_H263,
	GS_CODEID_AUDIO_ST_SVAC,
	GS_CODEID_AUDIO_ST_AAC,
	GS_CODEID_AUDIO_ST_G726_16,
	GS_CODEID_AUDIO_ST_G726_24,
	GS_CODEID_AUDIO_ST_G726_32,
	GS_CODEID_AUDIO_ST_G726_40,
	GS_CODEID_AUDIO_ST_OGGVORBIS,
	GS_CODEID_AUDIO_ST_AMR,
	GS_CODEID_AUDIO_ST_WMA1,
	GS_CODEID_AUDIO_ST_WMA2,
	GS_CODEID_AUDIO_ST_G722_1,

	GS_CODEID_PS = 0x00000400,


    //标准图像编码
    GS_CODEID_ST_JPEG       = 0x00000600,         //标准JPG
    GS_CODEID_ST_BMP,                             //标准JPG
    GS_CODEID_ST_YUV420P,                         //标准YUV420P
    GS_CODEID_ST_NV12,                            //标准NV12
    GS_CODEID_ST_RGB24,
	GS_CODEID_ST_ARGB,
	GS_CODEID_ST_RGBA,
	GS_CODEID_ST_BGR24,

    //按厂商进行的特殊编码



    //=====高新新兴
    GS_CODEID_GS_V2160I     = 0x00001000,       // GOSUN 2160I 视频编码
    GS_CODEID_GS_A2160I,                        // GOSUN 2160I 音频编码
    GS_CODEID_GS_V462C,                         //GOSUN BASS462C 视频编码
    GS_CODEID_GS_A462C,                         //GOSUN BASS462C 音频编码
    GS_CODEID_GS_V461C,                         //GOSUN BASS461C 视频编码
    GS_CODEID_GS_A461C,                         //GOSUN BASS461C 音频编码
	GS_CODEID_GS_V461A,                         //GOSUN BASS461A 视频编码
	GS_CODEID_GS_V2160IV,						// GOSUN 2160I_V 视频编码
	GS_CODEID_GS_A2160IV,                       // GOSUN 2160I_V 音频编码
	GS_CODEID_GS_VIPC,							// GOSUN IPC	 视频编码
	GS_CODEID_GS_AIPC,							// GOSUN IPC	 音频编码
	
	//======国迈======
	GS_CODEID_GS_GUOMAI_VIPC,					// 国迈4G执法仪视频编码
	GS_CODEID_GS_GUOMAI_AIPC,					// 国迈4G执法仪音频编码

    //===== 海狮 
    GS_CODEID_HI_VDEFAULT   = 0x00001200,        //海狮的视频通用编码
    GS_CODEID_HI_ADEFAULT,                      //海狮的音频通用编码
    GS_CODEID_HI_VH264,                         //海狮 H264
    GS_CODEID_HI_VMP4,                          //海狮 H264
    GS_CODEID_HI_COMPLEX,                          //海狮复合通用编码


    //===== 海康
    GS_CODEID_HK_VDEFAULT    = 0x00001300,      //海康的视频通用编码
    GS_CODEID_HK_ADEFAULT,                      //海康的音频通用编码
    GS_CODEID_HK_VMP4,                          //海康 MP4
    GS_CODEID_HK_VH264,                         //海康 H264
	GS_CODEID_HK_COMPLEX,                       //海康复合通用编码
	GS_CODEID_HK_PRIVATE,                       //海康私有格式编码




    //===== 大华
    GS_CODEID_DH_VDEFAULT    = 0x00001400,      //大华的视频通用编码
    GS_CODEID_DH_ADEFAULT ,                     //大华的音频通用编码
    GS_CODEID_DH_VMP4,                          //大华 MP4
    GS_CODEID_DH_VH264,                         //大华 H264
    GS_CODEID_DH_COMPLEX,                       //大华复合通用编码
	GS_CODEID_DH_PRIVATE,								//大华私有格式编码

    //===== 恒益
    GS_CODEID_HY_VDEFAULT   = 0x00001500,       //恒益的视频通用编码
    GS_CODEID_HY_ADEFAULT,                      //恒益的音频通用编码
    GS_CODEID_HY_VMP4,                          //恒益 MP4
    GS_CODEID_HY_VH264,                         //恒益 H264
    GS_CODEID_HY_COMPLEX,                       //恒益复合通用编码


	//=====手机
	GS_CODEID_WM_XVID		= 0x00001600,		//手机客户端解码1,谭志添加测试

	// ===== 黄河
	GS_COIDEID_HH_VDEFULT   = 0x00001700,       //黄河的视频通用编码

	// ===== 中本
	GS_CODEID_ZBEN_VDEFULT  = 0x00001800,       //中本的视频编码
	GS_CODEID_ZBEN_ADEFULT,                     //中本的音频编码

	// ===== 高凯视
	GS_CODEID_CALSYS_VDEFULT = 0x00001900,         //高凯视的视频通用编码 
	GS_CODEID_CALSYS_ADEFULT,                      //高凯视的音频通用编码

    // ==== 安联锐视
	GS_COIDEID_ALRS_VDEFULT   = 0x00002000,       //安联锐视的视频通用编码

	// ====  讯美
    GS_CODEID_XM_VDEFULT   = 0x00002100,          //讯美视频通用编码

   // ====  高凯视GS76xx系列
    GS_CODEID_CALSYSGS76XX_VDEFULT = 0x00002200,         //高凯视GS76XX的视频通用编码 
	
	//
	GS_CODEID_MEDIA = 0x00002300,
	// === FFmpeg解码测试
	GS_CODEID_GSVIDEO = 0x00002400,
	
	// ====  捷高
	GS_CODEID_JG_VDEFULT = 0x00002500,              //捷高设备通用编码
	GS_CODEID_JG_ADEFULT = 0x00002600,

	//=====柏康=======
	GS_CODEID_PACOM_VDEFULT = 0x00002700,
	GS_CODEID_PACOM_ADEFULT = 0x00002800,		    //柏康设备

	//======希华======
	GS_CODEID_XIHUA_VDEFULT = 0x00002900,			//希华视频编码
	GS_CODEID_XIHUA_ADEFULT = 0x00003000,			//希华音频编码

	//======宇视======
	GS_CODEID_UVNVR_AR_VDEFULT = 0x00003100,        //宇视NVR AR的视频通用编码 
	GS_CODEID_UVNVR_AR_ADEFULT = 0x00003200,	    //宇视NVR音频编码

	//======宇视IPC======
	GS_CODEID_UNIVIEW_IPC_VDEFULT = 0x00003300,		//宇视ipc摄像机视频编码
	GS_CODEID_UNIVIEW_IPC_ADEFULT = 0x00003400,		//宇视ipc摄像机音频编码

	GS_CODEID_VSR = 0x00003500,				        //结构化数据帧

	//======罗克士NVR======
	GS_CODEID_ROCOS_VDEFULT = 0x00003600,			//ROCOSNVR视频编码
    GS_CODEID_ROCOS_ADEFULT = 0x00003700,			//ROCOSNVR音频编码

	//======图敏======
	GS_CODEID_TM_VDEFULT = 0x00003800,			//图敏视频编码
    GS_CODEID_TM_ADEFULT = 0x00003900,			     //图敏音频编码
    
    //======启扬======
	GS_CODEID_QIY_VDEFULT = 0x00004000,			     //启扬视频编码
	GS_CODEID_QIY_ADEFULT = 0x00004100,			     //启扬音频编码
    
   	//======景阳======
	GS_CODEID_SUNELL_VDEFULT = 0x00004200,			 //景阳视频编码
	GS_CODEID_SUNELL_ADEFULT = 0x00004300,			 //景阳音频编码
	
	//======华为======
	GS_CODEID_HUAWEI_VDEFULT = 0x00004400,			 //华为视频编码
	GS_CODEID_HUAWEI_ADEFULT = 0x00004500,			 //华为音频编码
	GS_CODEID_HUAWEI_COMPLEX,
	
	//======天地伟业======
	GS_CODEID_TDWY_VDEFULT = 0x00004600,			 //天地伟业视频编码
	GS_CODEID_TDWY_ADEFULT = 0x00004700,			 //天地伟业音频编码
	GS_CODEID_TDWY_COMPLEX,

	//======博世======
	GS_CODEID_BOSCH_VDEFULT = 0x00004800,			 //博世视频编码
	GS_CODEID_BOSCH_ADEFULT,						 //博世音频编码
	GS_CODEID_BOSCH_COMPLEX,

	//======浩云======
	GS_CODEID_HAOYUN_VDEFULT = 0x00004900,			 //浩云视频编码
	GS_CODEID_HAOYUN_ADEFULT,						 //浩云音频编码
	GS_CODEID_HAOYUN_COMPLEX,

	//======清华同方======
	GS_CODEID_TONGFANG_VDEFULT = 0x00005000,		 //清华同方视频编码
	GS_CODEID_TONGFANG_ADEFULT,						 //清华同方音频编码
	GS_CODEID_TONGFANG_COMPLEX,

	//======天跃科技======
	GS_CODEID_TYKJ_VDEFULT = 0x00005100,			 //天跃科技视频编码
	GS_CODEID_TYKJ_ADEFULT,							 //天跃科技音频编码
	GS_CODEID_TYKJ_COMPLEX,

	//======蓝色星际======
	GS_CODEID_BLUESTAR_VDEFULT = 0x00005200,		 //蓝色星际视频编码
	GS_CODEID_BLUESTAR_ADEFULT,						 //蓝色星际音频编码
	GS_CODEID_BLUESTAR_COMPLEX,

	//======汉邦高科======
	GS_CODEID_HANBANG_VDEFULT = 0x00005300,			 //汉邦高科视频编码
	GS_CODEID_HANBANG_ADEFULT,						 //汉邦高科音频编码
	GS_CODEID_HANBANG_COMPLEX,

	//======宇视新设备======
	GS_CODEID_UV2017_VDEFULT  = 0x00005400,			 //宇视新设备类型视频编码

	//======华途设备======
	GS_CODEID_NSDPANO_VDEFULT  = 0x00005500,			 //NsdPano 华途设备设备类型视频编码

    GS_CODEID_END,   //放在结尾 


}EnumGSCodeID;

#endif // GSSTREAMCODEID_DEF_H
