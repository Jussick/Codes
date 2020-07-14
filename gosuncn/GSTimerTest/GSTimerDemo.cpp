//C++ file
/***********************************************
#
#      Filename: gsTimerDemo.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-05-26 11:12:15
#**********************************************/
#include <iostream>
#include "GSTime.h"
#include <unistd.h>

using namespace std;

// 时间信息结构体                                                                                                          
struct StruTimerParam                                                                                                      
{                                                                                                                          
    long timerID;                                                                                                          
    GSAtomic ticks;                                                                                                        
    int interval;                                                                                                          
    UInt64 lastTv;                                                                                                         
    GSAtomic nsync;                                                                                                        
    int maxInterval;                                                                                                       
    StruTimerParam( long id=0, int inter=10) : timerID(id), ticks(0), interval(inter),lastTv(0),nsync(0), maxInterval(-1){}
                                                                                                                           
    void Init( long id, int inter )                                                                                        
    {                                                                                                                      
        timerID = id;                                                                                                      
        interval = maxInterval;                                                                                            
    }                                                                                                                      
};                                                                                                                         

static void GS_CALLBACK RunOnTimerEvent(GSTimer & Timer , void *TimerParam)
{
    cout << "yeeee" << endl;
}

int main()
{

    GSTimer::ModuleInit();                                                                  
    GSTimer *m_TimerRun = new GSTimer(1);      
    StruTimerParam m_ParaRun(1, 400);
    m_TimerRun->Init(m_ParaRun.interval , RunOnTimerEvent , &m_ParaRun); 
    m_TimerRun->Start(true);                                                                 

    while (1)
    {
        sleep(1);
    }
}
