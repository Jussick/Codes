/**
 * Copyright 2018 YY.com Inc. All rights reserved.
 *
 * @file libs/common/util.cc
 * @author luohouqi
 * @date 2015/04/27 11:57:55
 * @brief
 *
 **/

#include "util.h"
#include <atomic>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "zlib.h"
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/vfs.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
#include <uuid/uuid.h>
#include "butil/base64.h"

namespace cim {
namespace common {

static std::atomic<int64_t> log_id_(CurrentMicros());

int SleepMs(int64_t milli_seconds) {
    struct timespec ts;
    ts.tv_sec = milli_seconds / 1000;
    ts.tv_nsec = (milli_seconds % 1000) * 1000000;
    return nanosleep(&ts, NULL);
}

int64_t GetTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000L + tv.tv_usec;
}

int64_t GetTimePoint() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000L + ts.tv_nsec / 1000;
}

int GetHour() {
    time_t timep;
    struct tm *p;
    time(&timep);
    p=localtime(&timep);
    return p->tm_hour;
}

int64_t GetMorningTime(int64_t timestamp) {
    struct tm * tm= localtime(&timestamp);
    tm->tm_hour = 0;
    tm->tm_min = 0;
    tm->tm_sec = 0;
    return mktime(tm);
}

static bool IsValidAddress(const std::string& address) {
    bool ok = true;
    for (size_t i = 0; i < address.size(); ++i) {
        if (address[i] == '.' || address[i] == ':' || (address[i] >= '0' && address[i] <= '9')) {
            continue;
        } else {
            ok = false;
            break;
        }
    }
    return ok;
}

bool DottedAddress2Int(const std::string& address, int64_t* server) {
    bool ok = false;
    std::string copy = address;
    if (IsValidAddress(copy)) {
        char* elements[4];
        if (4 == SplitString(&copy[0], '.', elements, 4)) {
            uint32_t host = 0;
            uint32_t port = 0;
            for (int i = 0; i < 3; ++i) {
                host += (atoi(elements[i]) << (i * 8));
            }
            char* data[2];
            if (2 == SplitString(elements[3], ':', data, 2)) {
                host += (atoi(data[0]) << 24);
                port += atoi(data[1]);
            }
            *server = HostPort2Address(host, port);
            ok = true;
        }
    }
    return ok;
}

std::string IntAddress2Dotted(int64_t server) {
    char address[64];
    sprintf(address, S_DOTTED_ADDRESS, DOTTED_ADDRESS(server));
    return std::string(address);
}

static bool IsValidHost(const std::string& host) {
    // ���ж��ַ��Ƿ�Ϸ�
    if (host.empty()) {
        return false;
    }
    bool ok = true;
    for (size_t i = 0; i < host.size(); ++i) {
        if (host[i] == '.' || (host[i] >= '0' && host[i] <= '9')) {
            continue;
        } else {
            ok = false;
            break;
        }
    }
    return ok;
}

bool DottedHost2Int(const std::string& host, int* ip) {
    bool ok = false;
    std::string copy = host;
    if (IsValidHost(copy)) {
        char* elements[4];
        if (4 == SplitString(&copy[0], '.', elements, 4)) {
            *ip = 0;
            for (int i = 0; i < 4; ++i) {
                *ip += (atoi(elements[i]) << (i * 8));
            }
            ok = true;
        }
    }
    return ok;
}

int SplitString(char* data, char c, char* elements[], int n) {
    char *p1, *p2;
    int i = 0;
    for (p1 = p2 = data; *p1; p1++) {
        if (*p1 == c) {
            *p1 = 0;
            if (i < n) {
                elements[i++] = p2;
            } else {
                break;
            }
            p2 = p1+1;
        }
    }
    if (i < n) {
        elements[i++] = p2;
    }
    return i;
}

void SplitString(const std::string& data, char c, std::vector<std::string>* results) {
    std::string::size_type pos1, pos2;
    pos2 = data.find(c);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        results->push_back(data.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = data.find(c, pos1);
    }
    results->push_back(data.substr(pos1));
}

/*uint32_t Adler32Value(const char* data, size_t n) {
    unsigned long  adler = adler32(0L, Z_NULL, 0);
    unsigned long adler1 = adler32(adler, (const Bytef*)data, n);
    return (uint32_t)adler1;
}*/

bool GetHostIp(std::string* hostip) {
    int i = 0;
    int sockfd;
    struct ifconf ifconf;
    char buf[10*sizeof(struct ifreq)];
    struct ifreq *ifreq;
    char* address;
    ifconf.ifc_len = 10*sizeof(struct ifreq);
    ifconf.ifc_buf = buf;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0))<0) {
        return false;
    }
    ioctl(sockfd, SIOCGIFCONF, &ifconf);
    close(sockfd);
    ifreq = (struct ifreq*)buf;

    for (i = (ifconf.ifc_len/sizeof(struct ifreq)); i > 0; i--) {
        address = inet_ntoa(((struct sockaddr_in*)&(ifreq->ifr_addr))->sin_addr);
        if (strcmp(address, "127.0.0.1") == 0) {
            ifreq++;
            continue;
        }
        std::string tmp_add(address);
        if (tmp_add.find("192.168.") != std::string::npos) {
            ifreq++;
            continue;
        }

        hostip->assign(address);
        return true;
    }

    return false;
}

// Copyright 2012 Facebook, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//   http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

namespace {
inline int StringPrintfImpl(std::string& output, const char* format,
                              va_list args) {
    // Tru to the space at the end of output for our output buffer.
    // Find out write point then inflate its size temporarily to its
    // capacity; we will later shrink it to the size needed to represent
    // the formatted string.  If this buffer isn't large enough, we do a
    // resize and try again.

    const int write_point = output.size();
    int remaining = output.capacity() - write_point;
    output.resize(output.capacity());

    va_list args_copy;
    va_copy(args_copy, args);
    int bytes_used = vsnprintf(&output[write_point], remaining, format,
                               args_copy);
    va_end(args_copy);
    if (bytes_used < 0) {
        return -1;
    } else if (bytes_used < remaining) {
        // There was enough room, just shrink and return.
        output.resize(write_point + bytes_used);
    } else {
        output.resize(write_point + bytes_used + 1);
        remaining = bytes_used + 1;
        va_list args_copy;
        va_copy(args_copy, args);
        bytes_used = vsnprintf(&output[write_point], remaining, format,
                               args_copy);
        va_end(args_copy);
        if (bytes_used + 1 != remaining) {
            return -1;
        }
        output.resize(write_point + bytes_used);
    }
    return 0;
}
}  // end anonymous namespace

std::string StringPrintf(const char* format, ...) {
    // snprintf will tell us how large the output buffer should be, but
    // we then have to call it a second time, which is costly.  By
    // guestimating the final size, we avoid the double snprintf in many
    // cases, resulting in a performance win.  We use this constructor
    // of std::string to avoid a double allocation, though it does pad
    // the resulting string with nul bytes.  Our guestimation is twice
    // the format string size, or 32 bytes, whichever is larger.  This
    // is a hueristic that doesn't affect correctness but attempts to be
    // reasonably fast for the most common cases.
    std::string ret;
    ret.reserve(std::max(32UL, strlen(format) * 2));

    va_list ap;
    va_start(ap, format);
    if (StringPrintfImpl(ret, format, ap) != 0) {
        ret.clear();
    }
    va_end(ap);
    return ret;
}

// Basic declarations; allow for parameters of strings and string
// pieces to be specified.
int StringAppendf(std::string* output, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    const size_t old_size = output->size();
    const int rc = StringPrintfImpl(*output, format, ap);
    if (rc != 0) {
        output->resize(old_size);
    }
    va_end(ap);
    return rc;
}

int StringVappendf(std::string* output, const char* format, va_list args) {
    const size_t old_size = output->size();
    const int rc = StringPrintfImpl(*output, format, args);
    if (rc == 0) {
        return 0;
    }
    output->resize(old_size);
    return rc;
}

int StringPrintf(std::string* output, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    output->clear();
    const int rc = StringPrintfImpl(*output, format, ap);
    if (rc != 0) {
        output->clear();
    }
    va_end(ap);
    return rc;
};

int StringVprintf(std::string* output, const char* format, va_list args) {
    output->clear();
    const int rc = StringPrintfImpl(*output, format, args);
    if (rc == 0) {
        return 0;
    }
    output->clear();
    return rc;
}
bool GetFileList(const std::string& path,
        std::vector<std::string>* file_list) {
    file_list->clear();
    DIR* dir = opendir(path.c_str());
    if(NULL == dir) {
        return false;
    }
    struct dirent* dir_entry= NULL;
    struct dirent temp;

    while(readdir_r(dir, &temp, &dir_entry) == 0) {
        if (NULL == dir_entry) {
            break;
        }

        if (!strcmp(dir_entry->d_name,".") || !strcmp(dir_entry->d_name,"..")) {
            continue;
        }
        file_list->push_back(dir_entry->d_name);
    }
    closedir(dir);
    return true;
}

bool FileExists(const std::string& file_name) {
    return access(file_name.c_str(), F_OK) == 0;
}

void TrimLastSlashes(std::string* src) {
    // Trim extra slashes
    int i = static_cast<int>(src->size()) - 1;
    while (i >= 1 && (*src)[i] == '/') {
        --i;
    }
    *src = src->substr(0, i + 1);
}

int64_t CurrentMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000L + tv.tv_usec;
}

std::string LocalTime() {
    std::time_t now = std::time(nullptr);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::string Iso8601UtcTime() {
    std::time_t now = std::time(nullptr);
    std::ostringstream ss;
    ss << std::put_time(std::gmtime(&now), "%Y-%m-%dT%H:%M:%SZ");
    return ss.str();
}

int64_t ParseIso8601UtcTime(const std::string& time) {
    std::tm t = {};
    std::istringstream ss{time};
    ss >> std::get_time(&t, "%Y-%m-%dT%H:%M:%SZ");
    if (ss.fail()) {
        return 0;
    }
    return timegm(&t);
}

int64_t GetLogId() {
    return log_id_++;
}

//only for linux platform
int64_t Rdtsc() {
    unsigned int lo, hi;
    /* We cannot use "=A", since this would use %rax on x86_64 */
    __asm__ __volatile__ (
            "rdtsc"
            : "=a" (lo), "=d" (hi)
            );
    return (int64_t)hi << 32 | lo;
}

std::string DateMicros(int64_t micros) {
    struct tm tb;
    time_t seconds = static_cast<time_t>(micros / 1000000);
    localtime_r(&seconds, &tb);
    char buf[256];
    snprintf(buf, sizeof(buf), "%04d-%02d-%02d_%02d:%02d:%02d_%06d",
            tb.tm_year + 1900, tb.tm_mon + 1, tb.tm_mday, tb.tm_hour, tb.tm_min,
            tb.tm_sec, static_cast<int>(micros % 1000000));
    return buf;
}

void Terminate() {
    pid_t pid = getpid();
    kill(pid, SIGTERM);
}

int PrevPowerOf2(int64_t n) {
    int cnt = 0;
    while (n > 1) {
        n = n >> 1;
        ++ cnt;
    }
    return cnt;
}

std::string BytesToString(const std::string& invisible) {
    char BYTE_LOW_BITS = 0x0F;
    unsigned char BYTE_HIGH_BITS = 0xF0;
    std::string visible;
    visible.clear();
    for (size_t i = 0; i < invisible.size(); i++) {
        unsigned char h = (invisible[i] & BYTE_HIGH_BITS) >> 4;
        if (h<=9) {
            visible.append(1, (char)(h+'0')); // convert
        } else {
            visible.append(1, (char)(h-0x0A+'A')); //ת�ɶ�Ӧ��д��ĸ
        }
        char l = (invisible[i] & BYTE_LOW_BITS);
        if (l>=0 && l<=9) {
            visible.append(1, (char)(l+'0')); //��Ӧ�����ַ�
        } else {
            visible.append(1, (char)(l-0x0A+'A')); //ת�ɶ�Ӧ��д��ĸ
        }
    }
    return visible;
}

std::string UrlEncode(const std::string& input) {
    std::ostringstream encoded;
    encoded.fill('0');
    encoded << std::hex;
    for (char c : input) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded << c;
            continue;
        }
        // Any other characters are percent-encoded
        encoded << std::uppercase;
        encoded << '%' << std::setw(2) << int((unsigned char) c);
        encoded << std::nouppercase;
    }
    return encoded.str();
}

std::string Base64Encode(const std::string& input) {
    std::string encoded;
    butil::Base64Encode(input, &encoded);
    return encoded;
}

void ReplaceCharacter(char src, char dst, std::string* str) {
    size_t size = str->size();
    for (size_t i = 0; i < size; ++i) {
        if ((*str)[i] == src) {
            (*str)[i] = dst;
        }
    }
}

static uint32_t DoChecksum(uint32_t value) {
    // Union to split word into 4 bytes;
    union {
        uint32_t w;
        uint8_t b[4];
    } v;
    v.w = value;

    // Key table
    static const uint32_t t[16] = {
        0xA00AE278L, 0xD70DD2EEL, 0x4E048354L, 0x3903B3C2L,
        0xA7672661L, 0xD06016F7L, 0x4969474DL, 0x3E6E77DBL,
        0xAED16A4AL, 0xD9D65ADCL, 0x40DF0B66L, 0x37D83BF0L,
        0xA9BCAE53L, 0xDEBB9EC5L, 0x47B2CF7FL, 0x30B5FFE9L };

    // The result
    uint32_t out;
    out = (t[v.b[0] & 0xf] ^ t[(v.b[3] >> 4) & 0xf]) +
        (t[v.b[1] & 0xf] ^ t[(v.b[2] >> 4) & 0xf]) +
        (t[v.b[2] & 0xf] ^ t[(v.b[1] >> 4) & 0xf]) +
        (t[v.b[3] & 0xf] ^ t[(v.b[0] >> 4) & 0xf]);

    return out;
}

static uint64_t DoChecksum64(uint64_t value) {
    return DoChecksum(value & 0xffffffff) | ((uint64_t)(DoChecksum((value >> 32) & 0xffffffff)) << 32);
}

uint64_t CalcAddBuddyReqChecksum(uint64_t from_uid, uint64_t to_uid, uint64_t app_id, uint64_t timestamp) {
    // Magic key for checksum calculation
    const uint32_t kCheckMagicNum = 0xEB3011CA;
    uint64_t out;

    out = DoChecksum64(from_uid);
    out ^= DoChecksum64(to_uid);
    out ^= DoChecksum64(app_id);
    out ^= DoChecksum64(timestamp);

    return out ^ kCheckMagicNum;
}

std::string GetPubPartitionKey(int64_t from_uid, int64_t to_uid) {
    int64_t min, max;
    if (from_uid < to_uid) {
        min = from_uid;
        max = to_uid;
    } else {
        min = to_uid;
        max = from_uid;
    }
    return common::StringPrintf("%ld:%ld", min, max);
}

std::string hmac_sha1(const char* key, size_t keylen, const char* input,
                             size_t len) {
  const EVP_MD* engine = EVP_sha1();

  unsigned char output[20];
  unsigned int output_len;

  HMAC_CTX* ctx = HMAC_CTX_new();
  HMAC_Init_ex(ctx, key, (int) keylen, engine, nullptr);
  HMAC_Update(ctx, (unsigned char*) input, len);

  HMAC_Final(ctx, output, &output_len);
  HMAC_CTX_free(ctx);

  return std::string((const char*) output, 20);
}

std::string sha1(const std::string& text) {
    unsigned char hash[SHA_DIGEST_LENGTH];
    char buf[SHA_DIGEST_LENGTH*2];
    SHA1((const unsigned char*)text.c_str(), text.size(), hash);

    for (int i=0; i < SHA_DIGEST_LENGTH; ++i) {
        sprintf(buf + i * 2, "%02x", hash[i]);
    }

    return std::string(buf, sizeof(buf));
}

std::string md5(const std::string& text) {
    unsigned char hash[MD5_DIGEST_LENGTH];
    char buf[MD5_DIGEST_LENGTH*2];
    MD5((const unsigned char*)text.c_str(), text.size(), hash);

    for (int i=0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(buf + i * 2, "%02x", hash[i]);
    }

    return std::string(buf, sizeof(buf));
}

std::string uuid_random() {
    uuid_t uuid;
    uuid_generate_random(uuid);

    char str[36];

    uuid_unparse(uuid, str);

    return str;
}


}
}
