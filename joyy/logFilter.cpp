//C++ file
/***********************************************
#
#      Filename: logFilter.cpp
#
#        Author: luhg - luhengguang@joyy.com
#   Description: 用正则过滤(匹配)日志
#        Create: 2021-11-26 17:45:06
#**********************************************/

#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <regex.h>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

class LogFilter {
public:
    LogFilter(const std::string& match_pattern, const std::string& skip_pattern)
        : match_pattern_(match_pattern) , skip_pattern_(skip_pattern) {
    }
    ~LogFilter() {
    }

    const std::string& match_pattern() const { return match_pattern_; }
    const std::string& skip_pattern() const { return skip_pattern_; }

    void set_match_pattern(const std::string& match_pattern) {
        match_pattern_ = match_pattern;
    }
    void set_skip_pattern(const std::string& skip_pattern) {
        skip_pattern_ = skip_pattern;
    }

    bool Init() {
        if (!match_pattern_.empty()) {
            int code = regcomp(&match_regex_, match_pattern_.c_str(), REG_NOSUB | REG_EXTENDED);
            if (code != 0) {
                return false;
            }
        }

        if (!skip_pattern_.empty()) {
            int code = regcomp(&skip_regex_, skip_pattern_.c_str(), REG_NOSUB | REG_EXTENDED);
            if (code != 0) {
                return false;
            }
        }

        return true;
    }

    bool Match(std::string& log) {
        if (match_pattern_.empty()) {
            return true;
        }

        regmatch_t pmatch[1];
        const size_t nmatch = 1;
		int ret = regexec(&match_regex_, &log[0], nmatch, pmatch, 0);

        cout << "pmatch[0].rm_so: " << pmatch[0].rm_so << ", " << "pmatch[1].rm_so: " << pmatch[1].rm_so << endl;
        string str1 = log.substr(pmatch[0].rm_so,log.length()-pmatch[0].rm_so);
    printf("With the whole expression, "
             "a matched substring \"%d, %s\" is found at position %d to %d.\n",
             pmatch[0].rm_eo - pmatch[0].rm_so, str1.c_str(),
             pmatch[0].rm_so, pmatch[0].rm_eo - 1);
		
		return ret == 0;
        // return 0 == regexec(&match_regex_, &log[0], nmatch, pmatch, 0);
    }

    bool Skip(std::string& log) {
        if (skip_pattern_.empty()) {
            return false;
        }

        regmatch_t pmatch[1];
        const size_t nmatch = 1;
        return 0 == regexec(&skip_regex_, &log[0], nmatch, pmatch, 0);
    }

private:
    regex_t match_regex_;
    regex_t skip_regex_;
    std::string match_pattern_;
    std::string skip_pattern_;
};

std::vector<std::string> splitWithStl(const std::string &str,const std::string &pattern)
{
    std::vector<std::string> resVec;

	if ("" == str)
    {
        return resVec;
    }
    //方便截取最后一段数据
    std::string strs = str + pattern;
    
    size_t pos = strs.find(pattern);
    size_t size = strs.size();

    while (pos != std::string::npos)
    {
        std::string x = strs.substr(0,pos);
        resVec.push_back(x);
        strs = strs.substr(pos+1,size);
        pos = strs.find(pattern);
    }
    
    return resVec;
}


int main() {
    // string pattern = "appkey=63e9db3b7193482ecce76090f0c6024b|appkey=7aa1e1cb6389b1c1487e4088f8954a87";
    string pattern = "appkey=e853c046c0ba95cef76b2baa007f6404|appkey=51ad230b052e1b4414f2d04d4ac4a57a|appkey=09a04d77b73665fd91c835ff9ba5df11|appkey=25adf2755a5fbdfa2c14b6dd45b2416f|appkey=aea27a57f5142f0380a66b3e8ae096af|appkey=eb634127d855227063758ba71617d206|appkey=4de130ed6c21fcac6400e9d5c6243364|appkey=00dae25a2b7cf44b2927fe0fdc19fc70|appkey=4b04df0edd0bbc0881cfe72233e0be63|appkey=b62623c4f94bc1ebe8afdbcd86ac7a0e|appkey=ed07c074665dbfc250421e635b694b7f|appkey=78b516ed5a534fb8af406bffc652206f|appkey=b139b86707d5eae42b5fb6cf7053cd73|appkey=26fb235f1b73db614560000226af9cf2|appkey=4b35b1c0673526e6949f861d1599f6cb|appkey=f46185df80b3cbfd45bc20f1a41ee767|appkey=bae03cf473c31d49e9f515d9a80665be|appkey=9dbd321ebcb44e79ec4124f1dd20fad1|appkey=c9a84bd1ce86a3445ede51770f8dc23d|appkey=e6515d905072f22449d7f29baaae184e|appkey=1643af9f39aae968944d4a1d3d11b223|appkey=dc3827c898bff6c5956695bbd9fc52dc|appkey=a699c4f3e9dca55792cca70f6f905e0a|appkey=9f0ec8ec4d42bb9068c7d1b1851027a7|appkey=db6ded236a3763dedc3ec1a89e62ffeb|appkey=f9f8ccf9db91f2fb97af4a8442f90bc3|appkey=f7987eb644987a0580918c16221ef89c|appkey=979057ece292d0857a0f30fb489e2f04|appkey=7d66b96e9ca594c4040d2d35a2d52818|appkey=2e515cc2811d551e1a4f1d8a90d880e2|appkey=8277d4b0a5eaf47a1bd801a7efd9275f|appkey=65713fe8966f8e69ce40a150a8b0f1f3|appkey=daf7acc9b1f8ba9bdb06689573b394e2|appkey=934c876531426a56add977debd149f78|appkey=b97daf76bbd3f14cfc9808d01c5ef798|appkey=0b0adc4d46c3ec67a34a1ab04d2895b7|appkey=4ab6c6a9e3a94beac806ab369192e944|appkey=ab0c03383f174111533482539b8084e9|appkey=87115c5cf7c064081badb0332117abb2|appkey=73e7fc3e30368e9edf59980411a8d101|appkey=14fbcb672e920f578e7486b68ca5dc40|appkey=3e717f93417d1edb434e35753ea44680|appkey=749f5f74c9065ed8805883878b218efb|appkey=a2051bebbca6e42f7c56de20391313ed|appkey=b91fdf2bb4790613df37e59433afb8bc|appkey=9099f8b6fafc0c3662b345dd6847ab06|appkey=c97b756b31c783be826f7649af263002|appkey=cad3a25995a6eb96ade5568ac4f2a632|act=aladdinopenapidata|act=apaccess|act=audiodownload|act=audioupload|act=biugomonitor|act=browserhistory|act=credityy|act=ddmgevent|act=firstaccess|act=hagoaf|act=hmrp2precvmsg|act=hmrp2psendmsg|act=hwsmsgateway|act=hwudblog|act=hwudbreginfo|act=hwudbsms|act=lpfanchordownload|act=lpfanchorfirstaccess|act=lpfcatonpromptflow|act=lpfplayerbusinessflow|act=lpfplayerdownload|act=lpfplayerfirstaccess|act=lpfservicecdnpush|act=luluboxafpushapi|act=luluboxtransqcstats|act=matrack|act=mbsdkaction|act=mbsdkbmhis|act=mbsdkdo1|act=mbsdkerror|act=mbsdklocation|act=mediadownload|act=mediaupload|act=mobileapaccess|act=mobileaudiodownload|act=mobileaudioupload|act=mobilefirstaccess|act=mobilevideodownload|act=mobilevideoupload|act=nodetaskquality|act=noizzafpushapi|act=pcapaccess|act=pcaudiodownload|act=pcaudioupload|act=pcfirstaccess|act=pcvideodownload|act=pcvideoupload|act=pmobilejoinchannelfailreport2|act=pmobilejoinchannelsuccreport2|act=pmobileloginfailreport2|act=pmobileloginsuccreport2|act=pushevent|act=rtmpdownload|act=saptaskquality|act=saptaskswitch|act=sdkuidevent|act=snrecordtaskquality|act=strategyetl|act=strategyqry|act=streamapaudio|act=streamapservice|act=streamaptask|act=streamapvideo|act=streamnodeaudio|act=streamnodeservice|act=streamnodetask|act=streamnodevideo|act=streamservermanager|act=streamservermanagernode|act=update|act=venus|act=videodownload|act=videoupload|act=webapservicestat|act=webapstat|act=webapuserlogin|act=webargohttpstatistics|act=webavpcpustat|act=webavpgroupinfo|act=webavppfainfo|act=webavppfastatinfo|act=webavppubliccharge|act=webavpstreamquality|act=webavpuserinfo|act=webcdnbackstreamstats|act=webcdnsourceusage|act=webcloudrecordfiletask|act=webdownfilesdkinfostat|act=webhlutransclientlinkqualitystat|act=webhlutransserverlinkqualitystat|act=webmedusaabnormalstat|act=webmedusaconnecteventsta|act=webonepiecesearchlog|act=webovstoavp|act=webpauserdetectresult|act=webrtcavpstreamquality|act=webrtcsdkmediastat|act=websdkdqaudiostatts|act=websdkdqotherstatts|act=websdkdqvideostatts|act=websdkinfostatts|act=websdkp2ppkgstatts|act=websdktransdqstat|act=websdktransflowstat|act=websdktransquality|act=websragentstatusstat|act=websrdetectstat|act=webtranssdkgmdelaystat|act=webvideorvpmonitor|act=webxunhuanperformance|act=ystapdelay|act=ystapffail|act=ystapfsucc|act=ystbroadcast|act=ystunicast|act=yyabtestactivateact|act=yyabtesteventact|act=yypushservice|act=yysignalserviceboradcast|act=yysignalservicecrc|act=yysignalserviceupdownlinkreport|act=zhuhaipasevent|act=zhwebevent|act=turnoverchargedata|act=webminiappheartbeat|act=webwxsdkpage|act=webwxsdkrun|act=webwxsdklogin|act=webwxsdklaunch|act=webwxsdkeven|act=webstat|act=webaction|act=webuniversalminisdkstat|act=mediapublish|act=webavpudpfainfo|act=webvideogatewayuidreq|act=appsecondindicator|act=webrtmpcenterforwardtask|act=rtmpforwardevent|act=websetbgrtmptask|act=webs3anchornotify|act=websdklosspkgstat|act=websdknorecvpkgstat|act=websenderlinkeventstat|act=websrpathqualitystat|act=websrflowstat|act=websrpkglossqualitystat|act=websragentqualitystat|act=webproxyjoingroupsummarystat|act=webproxyjoingroupdistributestat|act=webproxyjoingrouptop10stat|act=webgroupmembersummarystat|act=webgroupmemberdistributestat|act=webgroupmembertop10stat|act=webmprequeststat|act=webthreadcpustat|act=webgmallsdkstat|act=webtranssdkgmfailcasestat|act=webgmverifydiff|act=webrelaydaemonalloc|act=webrelayispquota|act=webnoroutereasonstat|act=webtranssdkbadtunnelstat|act=webmediacenterperformance|act=webmediacenteralloc|act=websdkstrategyp2ppkgstat|act=websdkstrategyispflowstat|act=hiidopush|act=mmetric|act=findyounetworkstatev2|act=pcentchndo|act=sjyychndo|act=webentchndo|act=websdkprotocol|act=currencyafpushapi|act=yyfictiondo|act=websraccessflowstat|act=webavpusernum|act=webcdnbackconnectstats|act=ystcheck|act=webrtmpforwardeventex|appkey=63e9db3b7193482ecce76090f0c6024b|appkey=7aa1e1cb6389b1c1487e4088f8954a87";
    LogFilter ft(pattern, "");
    ft.Init();

    // 不落hive表的数据
    string line = "58.248.229.155,200,00,act=mbsdkdata&smkdata=000000043686ff9c107223c2218350f67a1633bb&EC=0&appkey=bcc7fac95fc79fb9b9020cf6aac7d628&enc=b64&item=mbsdkreport&hiido_time=1637910626.000,_,00000564DKy2ATliwFGRy8oaJmrLUk/rkMZg9nbRBhLty5R75T9cCobzb5UCGqM6toG6yYJg5/P0AURjpihpml2q3OsO0Yb5+aaAggVsNJ29Fspxirkb0oUT7RK/EhQ8gcWP4ZsvfIVg7ZhtSw9sfGsBmQuRLRhNnMAS6//PTJqaHyruX4edlBPQmgA94o4GZi9YCjTNknvvHuxXjW1clcBlGvdRUh9xGsHDotseQsNo8nDcQeqEWXsSVWHYZbaHxoihdmW35GPYqlPERsg6IeYupfv7Pe5nn73z2k47JklNjM6R18AvAVNZyPLWSE8e4aYVFkE2zei58slyJcPwVq8t+PAAOHM0ujd5idZoNDOrsG10DVz6NJG/VCkd5cxPc/nbTPVG3PJ+Gtvcr9SHBOtS59wwyxvqrLO9bX32ubiJHG+1wWK0EwZN9rzeBPgj0yeHvXnpdmagNo5aErmMLv+fJTcXZrkp4KAr4sHCY/jt8GU28GWX3CwOUUayPOkRtctIdpL9Z3YvyBfvDwJzLYJF24zvATsK8fCjO+5To6MKOuuGoSeboTWujhDfRgrvwytukryhZRK29IXD3ak51405fotJo+iIt2lJFbpdFutdwkZmmgwqP5/anY6JGGSH4z2io3tOyMyfMxEH/jeGro7esuMD2Iz4cgUEQZNCA7U1SNEycVjvgAnpavsEMyrhznw6MjhdnrodcWXC3ROMNpCD2pzY8u37x8Kyl4vAiIP8YfdTdZDAyIk7hrPDCXGmca1XTnwp";

    // 落了hive表的数据
    // string line = "58.248.229.147,200,00,act=hahaha&smkdata=00000004af43c79d8b20d96569749a92b99fd988&EC=0&appkey=bcc7fac95fc79fb9b9020cf6aac7d628&enc=b64&item=mbsdkreport&host_appkey=3e717f93417d1edb434e35753ea44680&host_ver=5.43.0.2&hiido_time=1638261008.000,_,00000641dsel6T3Rm+yKd4RlwgLUcSWPdSdzjWI0hZb9whe+ZpHeBcVycDpK3RzjWOAbJDGmSyZsVb/R/d/29342Nad+snnWrTGAldb3ggr/U2roJpu5celKai8Sqck+TPIkoceIrInOQeeXjio+JWPjIFxaWAN9DB9gWu0+DuMTXslM9kONYddeEIGc937NOWVtwaN7d+WK/WoGSx11MNWXct8dIGI9PAIylfoc0LJszcEpuhhjVwx4YnbdlKS2ybOlH3X4QXBLbHUX1nueY6ilp5Z2DjH7TkARoEDTUECxpUdsb4/QHCzZb+Lzwf+Li0Qezi3jXfAJDfjKyYJ0+LVlAW2uKaE3E4uZrOyKe24YVilxs4SUbVZro/aaB+zOxdvXSsgyuA03HhcP86SY1omSImCWWcV2t6I3MQ7ZlcSCheiZpdQ6DMRm3sucBQ1scoc/ovg8zzeNvIMpA8EuMFy138Ce6GZniFMQaFK2hpz7UJsOKqS2uVwR2T4IXHdj4zl08w0GHVG1fFqc6WOj0h2Mi5tduCLqev5QRy4/E/OqSaFFhUxGnafYmR/l7z+Fzybgc90WF+dtmbcUlpm2qnQgZCGGn9ppJj/y/sVQoRUdOStspUCg7yggwaKKKQAEVZEfFkvZnFiePew4diikmQOTAeEQsxLjUhl0c12q90Sg4akJ6B/dSpHLmHuuufBRhuwkCvGMp7XTxbbGvjca7CZ0MfGYnseRngBK4kVtYYldnjL2PdWG4Ckxu6u2wv0X48UO0GUnUhQSzOrDePtpTsxwsXWp5F9cpSQF1EUnK3YepCT8wegte0s5dVlsOS9lWXwEtjgG9D2+SH29ygT/hb5UZe3CVHN3o9oewE7arO8Hl+aQYAQ=";

    // pattern代表要匹配的字段，line代表日志中的一行
    if (ft.Match(line))  // 匹配到了
        cout << "matched!" << endl;
    else
        cout << "Not matched!" << endl;

    string front = "58.248.229.147,200,00,act=hahaha&smkdata=00000004af43c79d8b20d96569749a92b99fd988&EC=0&";
    string tail = "&enc=b64&item=mbsdkreport&host_appkey=3e717f93417d1edb434e35753ea44680&host_ver=5.43.0.2&hiido_time=1638261008.000,_,00000641dsel6T3Rm+yKd4RlwgLUcSWPdSdzjWI0hZb9whe+ZpHeBcVycDpK3RzjWOAbJDGmSyZsVb/R/d/29342Nad+snnWrTGAldb3ggr/U2roJpu5celKai8Sqck+TPIkoceIrInOQeeXjio+JWPjIFxaWAN9DB9gWu0+DuMTXslM9kONYddeEIGc937NOWVtwaN7d+WK/WoGSx11MNWXct8dIGI9PAIylfoc0LJszcEpuhhjVwx4YnbdlKS2ybOlH3X4QXBLbHUX1nueY6ilp5Z2DjH7TkARoEDTUECxpUdsb4/QHCzZb+Lzwf+Li0Qezi3jXfAJDfjKyYJ0+LVlAW2uKaE3E4uZrOyKe24YVilxs4SUbVZro/aaB+zOxdvXSsgyuA03HhcP86SY1omSImCWWcV2t6I3MQ7ZlcSCheiZpdQ6DMRm3sucBQ1scoc/ovg8zzeNvIMpA8EuMFy138Ce6GZniFMQaFK2hpz7UJsOKqS2uVwR2T4IXHdj4zl08w0GHVG1fFqc6WOj0h2Mi5tduCLqev5QRy4/E/OqSaFFhUxGnafYmR/l7z+Fzybgc90WF+dtmbcUlpm2qnQgZCGGn9ppJj/y/sVQoRUdOStspUCg7yggwaKKKQAEVZEfFkvZnFiePew4diikmQOTAeEQsxLjUhl0c12q90Sg4akJ6B/dSpHLmHuuufBRhuwkCvGMp7XTxbbGvjca7CZ0MfGYnseRngBK4kVtYYldnjL2PdWG4Ckxu6u2wv0X48UO0GUnUhQSzOrDePtpTsxwsXWp5F9cpSQF1EUnK3YepCT8wegte0s5dVlsOS9lWXwEtjgG9D2+SH29ygT/hb5UZe3CVHN3o9oewE7arO8Hl+aQYAQ=";

    vector<string> vec;

    vec = splitWithStl(pattern, "|");
	string line1;

    // for (string middle : vec)
    // {
        // line1 =  front + middle + tail;
        // if (ft.Match(line))  // 匹配到了
            // cout << "matched!" << endl;
        // else
            // cout << "Not matched!" << endl;
    // }


}

