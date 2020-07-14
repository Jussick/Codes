#ifndef _FTPTRANSFER_H_
#define _FTPTRANSFER_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
#include <sys/stat.h>

// ---- common progress display ---- //
struct CustomProgress
{
    curl_off_t lastruntime; /* type depends on version, see above */
    CURL *curl;
};

// ftp attribute
struct FtpInfo{
    char *username;
    char *password;
};

class FTPTransfer{
public:
    FTPTransfer() {}
    ~FTPTransfer() {}

    static size_t getContentLengthFunc(void *ptr, size_t size, size_t nmemb, void *stream);
    static size_t discardFunc(void *ptr, size_t size, size_t nmemb, void *stream);
    static size_t readfunc(void *ptr, size_t size, size_t nmemb, void *stream);
    static size_t writeFunc(void *ptr, size_t size, size_t nmemb, void *stream);
    void FtpOptionInfoSet(const char* username, const char* password);
    int FtpUpload(const char *remote_file_path, const char *local_file_path, long timeout, long tries = 3);     // tries为ftp连接次数
    int FtpDownload(const char *remote_file_path, const char *local_file_path, long timeout = 3);

private:
    FtpInfo m_FtpOption;
};


#endif
