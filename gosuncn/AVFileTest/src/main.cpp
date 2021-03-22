//C++ file
/***********************************************
#
#      Filename: main.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 录像操作库的demo使用方法
#        Create: 2021-02-24 11:32:09
#**********************************************/
#include <iostream>
#include <chrono>
#include <thread>
#include "LocalSTAVFileInterface.h"

using namespace std;

int main()
{
    av_register_all();

    //打印ffmpeg的日志
    av_log_set_callback([](void *ptr, int level, const char *fmt, va_list vl){
        auto result = new char[500];
        switch (level)
        {
            case AV_LOG_INFO:
                vsprintf(result, fmt, vl);
                cout << result;
                break;
            case AV_LOG_WARNING:
                vsprintf(result, fmt, vl);
                cout<<result;
                break;
            case AV_LOG_ERROR:
                vsprintf(result, fmt, vl);
                cout<<result;
                break;
            default:
                break;
        }
        delete result;
    }); 
    
    CLocalSTAVFileReadInterface *m_readInterface = new CLocalSTAVFileReadInterface();
    CLocalSTAVFileWriteInterface *m_writeInterface = new CLocalSTAVFileWriteInterface();
    // string filename = "../videos/test.mp4";    
    string filename = "../videos/ttt.avi";    

    // 打开mp4的录像文件
    EnumGSAVFileRetCode ret = m_readInterface->OpenFile((char*)filename.c_str(), eOPEN_READ);
    if ( ret != eAVF_SUCCESS  )  
    { 
        cout << "file open failed!" << endl; 
        return -1;  
    }

    //获取轨道数量
    auto mediaDescriCount = m_readInterface->GetMediaDescriCounts();

    //创建新的录像文件，写入各个轨道的媒体信息
    auto createRecordFile = [&]()
    {
        //初始化媒体信息
        auto initDescri = [&]()
        {
            auto describtions = new StruGSMediaDescri[mediaDescriCount];

            for(int i=0;i<mediaDescriCount;i++)
            {
                //获取录像的各个轨道的媒体信息
                auto descri = m_readInterface->GetMediaDescri(i);
                if(descri->eMediaType == GS_MEDIA_TYPE_VIDEO)
                {
                    describtions[i].eMediaType = descri->eMediaType;
                    describtions[i].unDescri.struVideo.eCodeID = descri->unDescri.struVideo.eCodeID;

                    cout << "codeId:" << descri->unDescri.struVideo.eCodeID << endl;

                    describtions[i].unDescri.struVideo.iWidth = descri->unDescri.struVideo.iWidth;
                    describtions[i].unDescri.struVideo.iHeight = descri->unDescri.struVideo.iHeight;
                    describtions[i].unDescri.struVideo.iFrameRate = descri->unDescri.struVideo.iFrameRate;
                }
                if(descri->eMediaType == GS_MEDIA_TYPE_AUDIO)
                {
                    describtions[i].eMediaType = GS_MEDIA_TYPE_AUDIO;
                    describtions[i].unDescri.struAudio.eCodeID = descri->unDescri.struAudio.eCodeID;

                    cout << "codeId:" << descri->unDescri.struVideo.eCodeID << endl;

                    describtions[i].unDescri.struAudio.iSample = descri->unDescri.struAudio.iSample;
                    describtions[i].unDescri.struAudio.iBits = descri->unDescri.struAudio.iBits;
                    describtions[i].unDescri.struAudio.iChannels = descri->unDescri.struAudio.iChannels;
                    describtions[i].unDescri.struAudio.iBitRate = descri->unDescri.struAudio.iBitRate;
                }
            }
            return describtions;
        };

        auto describs = initDescri();
        // auto ret = m_writeInterface->CreateFile("../videos/output.mp4", "output.mp4", describs, mediaDescriCount);
        auto ret = m_writeInterface->CreateFile("../videos/output.avi", "output.avi", describs, mediaDescriCount);
        if(ret != eAVF_SUCCESS)
        {
            cout<<"Create File is failure.Result is "<<ret<<endl;
        }
    }; 

    createRecordFile();

    while (true)
    {
        //从avi里面读取一帧帧的信息
        StruGSAVFrame pstFrame;
        auto ret = m_readInterface->ReadFrame(&pstFrame, false);
        if ( ret != eAVF_SUCCESS && ret != eAVF_END_OF_GOP ) break;
        cout << "Is key frame :" << pstFrame.bKeyFrame << " ,timestamp is " << pstFrame.iTimestamp
             << " , media data len is " << pstFrame.iMediaDataLen << endl;

        //把媒体帧写入到新的录像文件里面
        ret = m_writeInterface->WriteFrame(&pstFrame);
        cout<<"Write frame result is "<<ret<<endl;

        /*一般一帧数据来了，需要判断当前数据是不是视频帧，因为帧的类型分成几种。SPS/PPS/SEI/I/P
          摄像头因为实时视频的原因，会在I帧跟P帧前插入1帧SEI帧，如果只是I帧前插入是影响不大的，但是因为会在每帧P帧前都插入SEI这个结构化数据，
          如果把这个数据也写入进去的话，录像的文件会增大1倍。所以在实际的帧过来的时候，需要调用这个函数，把数据传进去，通过下面这个方法，
          把这个P帧前的SEI给去掉。*/
        auto GetFramePos = [](const unsigned char *frameData, unsigned int frameLen){
            int type = 0;
            int nalHeadPos = 0;
            int offset = 0;
            while (nalHeadPos < frameLen)
            {
                //search for nal header
                if ( frameData[nalHeadPos++] == 0x00 && frameData[nalHeadPos++] == 0x00 )
                {
                    if ( frameData[nalHeadPos++] != 0x01 )
                    {
                        nalHeadPos--;
                        if ( frameData[nalHeadPos++] == 0x00 && frameData[nalHeadPos++] == 0x01 )
                        {
                            offset = 4;
                        }
                        else
                        {
                            nalHeadPos--;
                            nalHeadPos--;
                            if ( frameData[nalHeadPos++] == 0x00 && frameData[nalHeadPos++] == 0x00 &&
                                 frameData[nalHeadPos++] == 0x01 )
                            {
                                offset = 5;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                }
                else
                {
                    continue;
                }

                // 判断帧类型
                type = frameData[nalHeadPos] & 0x1f;
                if ((type == 0x01) || (type == 0x05))
                {
                    nalHeadPos -= offset;
                    return nalHeadPos;
                }
            }
            return 0;
        };
    }

    m_readInterface->Close();
    m_writeInterface->Close();

}
