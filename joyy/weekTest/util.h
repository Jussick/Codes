/**
 * Copyright 2018 YY.com Inc. All rights reserved.
 *
 * @file libs/common/util.h
 * @author dingtao
 * @date 2015/04/27 11:57:55
 * @brief
 *
 **/

#ifndef  _CIM_LIBS_COMMON_UTIL_H_
#define  _CIM_LIBS_COMMON_UTIL_H_

#include <stdint.h>
#include <string>
#include <vector>
#include <map>
#include <stdarg.h>                              // va_list

#ifndef DISALLOW_COPY_AND_ASSIGN
    #define DISALLOW_COPY_AND_ASSIGN(TypeName) \
        TypeName(const TypeName&); \
        void operator=(const TypeName&)
#endif

#define likely(x)   __builtin_expect((x),1)
#define unlikely(x) __builtin_expect((x),0)

#define HostPort2Address(ip, port)  (((int64_t)((uint32_t)ip))<<16 | ((int64_t)((uint32_t)port & 0x0000ffff)))
#define Address2Host(addr)          ((int)((addr)>>16))
#define Address2Port(addr)          ((int)(addr) & 0x0000ffff)

#define S_DOTTED_HOST               "%d.%d.%d.%d"
#define DOTTED_HOST(h)              (int)(((h)&0x000000ff0000ULL) >> 16), \
                                    (int)(((h)&0x0000ff000000ULL) >> 24), \
                                    (int)(((h)&0x00ff00000000ULL) >> 32), \
                                    (int)(((h)&0xff0000000000ULL) >> 40)

#define S_DOTTED_ADDRESS            "%d.%d.%d.%d:%d"
#define DOTTED_ADDRESS(h)           (int)(((h)&0x000000ff0000ULL) >> 16), \
                                    (int)(((h)&0x0000ff000000ULL) >> 24), \
                                    (int)(((h)&0x00ff00000000ULL) >> 32), \
                                    (int)(((h)&0xff0000000000ULL) >> 40), \
                                    (int)(((h)&0x00000000ffffULL))

namespace cim {
namespace common {

class Status;

const int64_t TimeUs  = 1000LL;
const int64_t TimeMs  = 1000000LL;
const int64_t TimeSec = 1000000000LL;

extern int64_t GetTime();

extern int64_t GetTimePoint();

extern int GetHour();

extern int SleepMs(int64_t ms);

extern bool DottedAddress2Int(const std::string& address, int64_t* server);

extern std::string IntAddress2Dotted(int64_t server);

extern bool DottedHost2Int(const std::string& host, int* ip);

extern int SplitString(char* data, char c, char* elements[], int n);
extern void SplitString(const std::string& data, char c, std::vector<std::string>* results);

//extern uint32_t Adler32Value(const char* data, size_t n);

extern bool GetHostIp(std::string* hostip);

extern bool GetFileList(const std::string& path, std::vector<std::string>* file_list);

extern bool FileExists(const std::string& file_name);

extern void TrimLastSlashes(std::string* src);

extern int64_t CurrentMicros();

extern std::string LocalTime();

extern std::string Iso8601UtcTime();

extern int64_t ParseIso8601UtcTime(const std::string& time);

extern int64_t GetMorningTime(int64_t timestamp);

extern std::string DateMicros(int64_t micros);

extern int64_t GetLogId();

extern int64_t Rdtsc();

extern void ReplaceCharacter(char src, char dst, std::string* str);

// Convert |format| and associated arguments to std::string
std::string StringPrintf(const char* format, ...)
    __attribute__ ((format (printf, 1, 2)));

// Write |format| and associated arguments into |output|
// Returns 0 on success, -1 otherwise.
int StringPrintf(std::string* output, const char* fmt, ...)
    __attribute__ ((format (printf, 2, 3)));

// Write |format| and associated arguments in form of va_list into |output|.
// Returns 0 on success, -1 otherwise.
int StringVprintf(std::string* output, const char* format, va_list args);

// Append |format| and associated arguments to |output|
// Returns 0 on success, -1 otherwise.
int StringAppendf(std::string* output, const char* format, ...)
    __attribute__ ((format (printf, 2, 3)));

// Append |format| and associated arguments in form of va_list to |output|.
// Returns 0 on success, -1 otherwise.
int StringVappendf(std::string* output, const char* format, va_list args);

template <class T,class V>
void ClipToRange(T* ptr, V minvalue, V maxvalue) {
    if (static_cast<V>(*ptr) > maxvalue) *ptr = maxvalue;
    if (static_cast<V>(*ptr) < minvalue) *ptr = minvalue;
}

extern void Terminate();

extern int PrevPowerOf2(int64_t n);

template <typename Type>
Type FindTarget(const std::string& key,
     const std::map<std::string, Type, bool(*)(const std::string&, const std::string&)>& targets) {

    Type type;
    typename std::map<std::string, Type>::const_iterator tablet_it = targets.upper_bound(key);
    if (tablet_it != targets.cend()) {
        if (tablet_it != targets.cbegin()) {
            --tablet_it;
            type = tablet_it->second;
        }
    } else {
        typename std::map<std::string, Type>::const_reverse_iterator reverse_it = targets.crbegin();
        if (reverse_it != targets.crend()) {
            type = reverse_it->second;
        }
    }
    return type;

    /*
    Type type;
    auto it = targets.lower_bound(key);
    if (it == targets.end()) {
        if (it != targets.begin()) {
            type = (--it)->second;
        }
    } else if (!CompareTabletId(it->first, key)) {
        type = it->second;
    } else {
        if (it != targets.begin()) {
            type = (--it)->second;
        }
    }
    return type;
    */
}

extern std::string BytesToString(const std::string& invisible);

extern std::string UrlEncode(const std::string& input);

extern std::string Base64Encode(const std::string& input);

extern uint64_t CalcAddBuddyReqChecksum(uint64_t from_uid, uint64_t to_uid, uint64_t app_id, uint64_t timestamp);

inline unsigned int DJBHash(const char* str, size_t len) {
  unsigned int hash = 5381;
  for (size_t i = 0; i < len; i++)
    hash = ((hash << 5) + hash) + str[i];
  return hash;
}

extern std::string GetPubPartitionKey(int64_t from_uid, int64_t to_uid);

extern std::string hmac_sha1(const char* key, size_t keylen, const char* input, size_t len);

extern std::string sha1(const std::string& text);

extern std::string md5(const std::string& text);

extern std::string uuid_random();


/*
static const char* const kChatServiceName = "svc_Im_ChatService";
static const char* const kBuddyServiceName = "svc_Im_BuddyService";
static const char* const kPDCServiceName = "svc_Im_PDCService"; // TODO change name
static const char* const kPullServiceName = "svc_Im_PullService";
static const char* const kSeqServiceName = "svc_Im_SeqService";
static const char* const kPushServiceName = "service_api_gateway";
static const char* const kGroupServiceName = "svc_Im_GroupService";

static const char* const kP2PChatMethodName = "cim.proto.ChatService.P2PChat";
static const char* const kAddBuddyMethodName = "cim.proto.BuddyManagerService.AddBuddy";
static const char* const kAgreeToBeBuddyMethodName = "cim.proto.BuddyManagerService.AgreeToBeBuddy";
static const char* const kRejectToBeBuddyMethodName = "cim.proto.BuddyManagerService.RejectToBeBuddy";
static const char* const kDeleteBuddyMethodName = "cim.proto.BuddyManagerService.DeleteBuddy";
static const char* const kListBuddyMethodName = "cim.proto.BuddyQueryService.ListBuddy";
static const char* const kReportPullProcessMethodName = "cim.proto.PdcService.ReportPullProcess";
static const char* const kPullMsgMethodName = "cim.proto.PullService.PullMsg";
static const char* const kReversePullMsgMethodName = "cim.proto.PullService.ReversePullMsg";
static const char* const kMsgNotifyMethodName = "cim.proto.PushService.MsgNotify";
static const char* const kGetNextSeqMethodName = "cim.proto.SeqService.GetNextSeq";
*/


}
}

#endif
