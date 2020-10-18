#ifndef PHOENIX_COMMON_H_
#define PHOENIX_COMMON_H_
// #include "DBControl.h"
// #include "GSZmq.h"
// #include "INIReader.h"
// #include "elog.h"
// #include "GSFoundation.h"
#include <future>
// #include <bits/stdc++.h>

#define ROBOT_SQLITE_NAME 		"Robot.db"	//数据库路径
#define ROBOT_MYSQL_NAME 		"db=PHOENIX2 host=localhost user=root password='gsy2017' charset=utf8"	//数据库路径

#define PHOENIX_ASSERT(expr) do{\
        if (!(expr)) {\
        fprintf(stderr,\
        "Assertion failed in %s on line %d: %s\n",    \
        __FILE__,                                     \
        __LINE__,                                     \
#expr);                                       \
        abort();                                      \
        }                                             \
} while(0)


#define PHOENIX_RET(_condition) if(_condition){log_e("return failed : %s",#_condition); return;}

//错误码
#define V_OK						0		// 成功
#define V_ERR						-1		// 错误
#define V_ERR_INVALID_ARGUMENT		100		// 无效
#define V_ERR_NOT_SUPPORT			101		// 不支持
#define V_ERR_OUT_OF_MEMORY			102
#define V_ERR_NO_SUCH_DEVICE		103
#define V_ERR_NEED_INIT				104
#define V_ERR_IO_ERROR				105
#define V_ERR_END_OF_FILE			106
#define V_ERR_OPERATION_FAILED		107
#define V_ERR_NOT_SET_YET			108
#define V_ERR_NO_SUCH_FILE			109
#define V_ERR_PERMISSION_DENY		110
#define V_ERR_DATA_ILLEGAL			111
#define V_ERR_DATA_WRONG			112
#define V_ERR_UNRECOGNIZED			113
#define V_ERR_TIME_OUT				114
#define V_ERR_BUSY					115
#define V_ERR_OVERFLOW				116
#define V_ERR_AGAIN					117

//区域名字对应的标识符
#define DOOR_ZONE					"Door"


//告警类型汇总
typedef enum
{			 		 
	ROBOT_ALARM_TYPE_TEMP_TOP 				= 201,  // 温度上限告警    
	ROBOT_ALARM_TYPE_TEMP_LOW				= 200,	// 温度下限告警	
	ROBOT_ALARM_TYPE_HUMI_TOP 				= 203,  // 湿度上限告警
	ROBOT_ALARM_TYPE_HUMI_LOW				= 202,	// 湿度下限告警
	ROBOT_ALARM_TYPE_PM25					= 204,	// PM2.5 告警
	ROBOT_ALARM_TYPE_TUMB					= 205,  // 摔倒 告警
	ROBOT_ALARM_TYPE_HANG					= 206,	// 悬挂 告警
	ROBOT_ALARM_TYPE_POWER_LOW				= 207,  //电池 告警
	ROBOT_ALARM_TYPE_XBPOWER_LOW			= 208,	//信标电量低告警
	ROBOT_ALARM_TYPE_RAILSOUT				= 209,	//脱轨告警
	ROBOT_ALARM_TYPE_STOP					= 210,	//阻挡告警
	ROBOT_ALARM_TYPE_NOISE					= 211,	//异常告警
	ROBOT_ALARM_TYPE_PM10					= 212,	// PM1.0 告警
	ROBOT_ALARM_TYPE_LOWNET					= 213,  //低速无线告警
	ROBOT_ALARM_TYPE_MANUAL					= 214,	//一键告警 改为人体闯入告警
	ROBOT_ALARM_TYPE_POWER_COUNT_LIM		= 215,	//电池 充放电次数告警
	ROBOT_ALARM_TYPE_LINK0					= 216,	//link0告警
	ROBOT_ALARM_TYPE_LINK1					= 217,	//link1告警
	ROBOT_ALARM_TYPE_IPCLASH 				= 218,	//IP 冲突告警
	ROBOT_ALARM_TYPE_RAINING 				= 219,	//下雨
	ROBOT_ALARM_TYPE_POISONGAS				= 220,	//毒气告警  PoisonGas
	ROBOT_ALARM_TYPE_CO2_TOP 				= 221,	//二氧化碳高浓度告警
	ROBOT_ALARM_TYPE_CO2_LOW 				= 222,	//二氧化碳高低浓度告警
	ROBOT_ALARM_TYPE_IRTEMP_TOP 			= 223,	//红外温度上限告警(测温动作)
	ROBOT_ALARM_TYPE_IRTEMP_LOW 			= 224,	//红外温度下限告警(测温动作)
	
	ROBOT_ALARM_TYPE_HUMANBODY				= 225,	//口令错误
	
	ROBOT_ALARM_TYPE_MAP_INIT				= 226,	//初始化失败告警
	ROBOT_ALARM_MOTOR_DRVIE_ERROR			= 228,	//驱动器告警
	ROBOT_ALARM_NO_WAER_MARK				= 229,	//未带口罩告警
	ROBOT_ALARM_TYPE_INFRARED_TEMP_TOP 		= 311,	//烟火告警--红外高温告警
	ROBOT_ALARM_TYPE_SOS         		    = 326,  //sos按钮告警
	ROBOT_ALARM_TYPE_WATERLOGGING			= 427,	//水渍检测告警
	ROBOT_ALARM_TYPE_POSLOST				= 428,	//定位丢失告警(websocket)
	ROBOT_ALARM_TYPE_MCUCOMMERR				= 429,	//主控通信失败告警
	ROBOT_ALARM_TYPE_OPENDOORFAIL			= 431,	//开门失败告警
	ROBOT_ALARM_TYPE_POSNOTCHANGE			= 432,	//长时间滞留告警
	ROBOT_ALARM_TYPE_POINTNOTREACH			= 433,	//巡逻点不可达告警
	ROBOT_ALARM_TYPE_BODY_HIGH_TEMP			= 436,	//巡逻点不可达告警
}enRobotAlarmType;


template <typename F, typename... Args>
auto real_async(F&& f, Args&&... args)-> std::future<typename std::result_of<F(Args...)>::type>
{
    using _Ret = typename std::result_of<F(Args...)>::type;
    auto _func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    std::packaged_task<_Ret()> tsk(std::move(_func));
    auto _fut = tsk.get_future();
    std::thread thd(std::move(tsk));
    thd.detach();
    return _fut;
}


#endif
