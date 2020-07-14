//C++ file
/***********************************************
#
#      Filename: FTPTransfer.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 支持断点续传的ftp客户端
#        Create: 2020-03-09 19:02:45
#**********************************************/
#include "FTPTransfer.h"
#include <functional>

using namespace std;


static int getVersion()
{
    CURLcode  return_code;
    return_code = curl_global_init(CURL_GLOBAL_ALL);
    if(CURLE_OK != return_code)
    {
        cout << "init libcurl failed" << endl;
        return -1;
    }
    cout << "curl_version = " << curl_version() << endl;
    curl_version_info_data *p = curl_version_info(CURLVERSION_NOW);
    cout << "curl_version_info_data = " << p->version_num << endl;
    curl_global_cleanup();
    return 0;
}


//
//  Make sure libcurl version > 7.32
//


// work for both download and upload
// int progressCallback(void *p,
                     // curl_off_t dltotal,
                     // curl_off_t dlnow,
                     // curl_off_t ultotal,
                     // curl_off_t ulnow)
// {
    // struct CustomProgress *progress = (struct CustomProgress *)p;
    // CURL *curl = progress->curl;
    // curl_off_t curtime = 0;

    // curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME_T, &curtime);

    // [> under certain circumstances it may be desirable for certain functionality
     // to only run every N seconds, in order to do this the transaction time can
     // be used */
    // if ((curtime - progress->lastruntime) >= 3000000)
    // {
        // progress->lastruntime = curtime;
        // printf("TOTAL TIME: %f \n", curtime);
    // }

    // // do something to display the progress
    // printf("UP: %ld bytes of %ld bytes, DOWN: %ld bytes of %ld bytes \n", ulnow, ultotal, dlnow, dltotal);
    // if (ultotal)
        // printf("UP progress: %0.2f\n", float(ulnow / ultotal));
    // if (dltotal)
        // printf("DOWN progress: %0.2f\n", float(dlnow / dltotal));

    // return 0;
// }

// ---- upload related ---- //
// parse headers for Content-Length
size_t FTPTransfer::getContentLengthFunc(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int r;
    long len = 0;

    r = sscanf((const char*)ptr, "Content-Length: %ld\n", &len);
    if (r) /* Microsoft: we don't read the specs */
        *((long *) stream) = len;
    return size * nmemb;
}

// discard already downloaded data
size_t FTPTransfer::discardFunc(void *ptr, size_t size, size_t nmemb, void *stream)
{
    return size * nmemb;
}

// read data to upload
size_t FTPTransfer::readfunc(void *ptr, size_t size, size_t nmemb, void *stream)
{
    FILE *f = (FILE*)stream;
    size_t n;
    if (ferror(f))
        return CURL_READFUNC_ABORT;
    n = fread(ptr, size, nmemb, f) * size;
    return n;
}

// do upload, will overwrite existing file
int FTPTransfer::FtpUpload(const char *remote_file_path, const char *local_file_path, long timeout, long tries)
{
    // init curl handle
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curlhandle = curl_easy_init();

    // get user_key pair
    char user_key[1024] = {0};
    sprintf(user_key, "%s:%s", m_FtpOption.username, m_FtpOption.password);

    cout << "userpwd: " << user_key << endl;

    FILE *file;
    long uploaded_len = 0;
    CURLcode ret = CURLE_GOT_NOTHING;
    file = fopen(local_file_path, "rb");
    if (file == NULL) 
    {
        perror(NULL);
        return 0;
    }
    curl_easy_setopt(curlhandle, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curlhandle, CURLOPT_URL, remote_file_path);
    curl_easy_setopt(curlhandle, CURLOPT_USERPWD, user_key);
    if (timeout)
        curl_easy_setopt(curlhandle, CURLOPT_FTP_RESPONSE_TIMEOUT, timeout);
    curl_easy_setopt(curlhandle, CURLOPT_HEADERFUNCTION, FTPTransfer::getContentLengthFunc);
    curl_easy_setopt(curlhandle, CURLOPT_HEADERDATA, &uploaded_len);
    curl_easy_setopt(curlhandle, CURLOPT_WRITEFUNCTION, FTPTransfer::discardFunc);
    curl_easy_setopt(curlhandle, CURLOPT_READFUNCTION, FTPTransfer::readfunc);
    curl_easy_setopt(curlhandle, CURLOPT_READDATA, file);
    curl_easy_setopt(curlhandle, CURLOPT_FTPPORT, "-"); 
    curl_easy_setopt(curlhandle, CURLOPT_FTP_CREATE_MISSING_DIRS, 1L);

    // set upload progress
    // curl_easy_setopt(curlhandle, CURLOPT_XFERINFOFUNCTION, progressCallback);
    
    struct CustomProgress prog;
    curl_easy_setopt(curlhandle, CURLOPT_XFERINFODATA, &prog);
    curl_easy_setopt(curlhandle, CURLOPT_NOPROGRESS, 0);

   // curl_easy_setopt(curlhandle, CURLOPT_VERBOSE, 1L); // if set 1, debug mode will print some low level msg

    // upload: 断点续传
    for (int c = 0; (ret != CURLE_OK) && (c < tries); c++)
    {
        /* are we resuming? */
        if (c)
        { /* yes */
            /* determine the length of the file already written */
            /*
            * With NOBODY and NOHEADER, libcurl will issue a SIZE
            * command, but the only way to retrieve the result is
            * to parse the returned Content-Length header. Thus,
            * getContentLengthfunc(). We need discardfunc() above
            * because HEADER will dump the headers to stdout
            * without it.
            */
            curl_easy_setopt(curlhandle, CURLOPT_NOBODY, 1L);
            curl_easy_setopt(curlhandle, CURLOPT_HEADER, 1L);
            ret = curl_easy_perform(curlhandle);
            if (ret != CURLE_OK)
                continue;
            curl_easy_setopt(curlhandle, CURLOPT_NOBODY, 0L);
            curl_easy_setopt(curlhandle, CURLOPT_HEADER, 0L);
            fseek(file, uploaded_len, SEEK_SET);
            curl_easy_setopt(curlhandle, CURLOPT_APPEND, 1L);
        }
        else
            curl_easy_setopt(curlhandle, CURLOPT_APPEND, 0L);

        ret = curl_easy_perform(curlhandle);
    }
    fclose(file);

    int curl_state = 0;
    if (ret == CURLE_OK)
        curl_state = 1;
    else
    {
        fprintf(stderr, "%s\n", curl_easy_strerror(ret));
        curl_state = 0;
    }

    // exit curl handle
    curl_easy_cleanup(curlhandle);
    curl_global_cleanup();

    return curl_state;
}

// ---- download related ---- //
// write data to upload
size_t FTPTransfer::writeFunc(void *ptr, size_t size, size_t nmemb, void *stream)
{
    std::cout << "--- write func ---" << std::endl;
    return fwrite(ptr, size, nmemb, (FILE*)stream);
}


// do download, will overwrite existing file
int FTPTransfer::FtpDownload(const char *remote_file_path, const char *local_file_path, long timeout)
{
    // init curl handle
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curlhandle = curl_easy_init();

    // get user_key pair
    char user_key[1024] = {0};
    sprintf(user_key, "%s:%s", m_FtpOption.username, m_FtpOption.password);

    FILE *file;
    curl_off_t local_file_len = -1 ;
    long filesize =0 ;
    CURLcode ret = CURLE_GOT_NOTHING;
    struct stat file_info;
    int use_resume = 0; // resume flag

    // get local file info, if success ,set resume mode
    if(stat(local_file_path, &file_info) == 0)
    {
        local_file_len = file_info.st_size;
        use_resume = 1;
    }

    // read file in append mode: 断点续传
    file = fopen(local_file_path, "ab+");
    if (file == NULL)
    {
        perror(NULL);
        return 0;
    }
    curl_easy_setopt(curlhandle, CURLOPT_URL, remote_file_path);
    curl_easy_setopt(curlhandle, CURLOPT_USERPWD, user_key); // set user:password
    // set connection timeout
    curl_easy_setopt(curlhandle, CURLOPT_CONNECTTIMEOUT, timeout);
    // set header process, get content length callback
    curl_easy_setopt(curlhandle, CURLOPT_HEADERFUNCTION, &FTPTransfer::getContentLengthFunc);
    curl_easy_setopt(curlhandle, CURLOPT_HEADERDATA, &filesize);

    // 断点续传 set download resume, if use resume, set current local file length
    curl_easy_setopt(curlhandle, CURLOPT_RESUME_FROM_LARGE, use_resume ? local_file_len : 0);
//    curl_easy_setopt(curlhandle, CURLOPT_WRITEFUNCTION, writeFunc);
    curl_easy_setopt(curlhandle, CURLOPT_WRITEDATA, file);

    // set download progress
    // curl_easy_setopt(curlhandle, CURLOPT_XFERINFOFUNCTION, progressCallback);
    struct CustomProgress prog;
    curl_easy_setopt(curlhandle, CURLOPT_XFERINFODATA, &prog);
    curl_easy_setopt(curlhandle, CURLOPT_NOPROGRESS, 0);


//    curl_easy_setopt(curlhandle, CURLOPT_VERBOSE, 1); // if set 1, debug mode will print some low level msg

    ret = curl_easy_perform(curlhandle);
    fclose(file);

    int curl_state = 0;
    if (ret == CURLE_OK)
        curl_state = 1;
    else
    {
        fprintf(stderr, "%s\n", curl_easy_strerror(ret));
        curl_state = 0;
    }

    // exit curl handle
    curl_easy_cleanup(curlhandle);
    curl_global_cleanup();

    return curl_state;
}


void FTPTransfer::FtpOptionInfoSet(const char* username, const char* password)
{
    m_FtpOption.username = (char*)username;
    m_FtpOption.password = (char*)password;
}
