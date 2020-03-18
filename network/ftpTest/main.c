//C file
/***********************************************
#
#      Filename: main.c
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-11-04 17:25:10
#**********************************************/
//test.c

#include <stdio.h>
#include "ftp-manager.h"

int main()
{
    FTP_OPT ftp_opt;
    ftp_opt.url = "ftp://192.168.41.200//个人/卢恒光/upload.txt";
    ftp_opt.user_key = "luhengguang:123456";
    ftp_opt.file = "/home/luhengguang/upload.txt";

    if(FTP_UPLOAD_SUCCESS == ftp_upload(ftp_opt))
        printf("Upload success.\n");
    else
        printf("Upload failed.\n");

    /* ftp_opt.url = "ftp://127.0.0.1//var/ftp/download.txt"; */
    /* ftp_opt.file = "/home/xxx/project/ftpManager/download.txt"; */

    /* if(FTP_DOWNLOAD_SUCCESS == ftp_download(ftp_opt)) */
        /* printf("Download success.\n"); */
    /* else */
        /* printf("Download failed.\n"); */

    return 0;
}
