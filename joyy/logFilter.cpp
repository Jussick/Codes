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
#include <sys/types.h>
#include <regex.h>
#include <stdio.h>

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
        return 0 == regexec(&match_regex_, &log[0], nmatch, pmatch, 0);
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

int main() {
    string pattern = "appkey=63e9db3b7193482ecce76090f0c6024b|appkey=7aa1e1cb6389b1c1487e4088f8954a87";
    LogFilter ft(pattern, "");
    ft.Init();

    string line = "58.248.229.155,200,00,act=mbsdkdata&smkdata=000000046d4a7d6466883278953af550ccc2e59c&EC=0&appkey=7aa1e1cb6389b1c1487e4088f8954a87&enc=b64&item=mbsdkreport&hiido_time=1637916493.000,_,00000564JUneoDqae5oJwu6WaAcbh0BNAU4hdyUbAXZor5E+V6gM4JAcPoBLEg8uTGLf/Puk8d3VkaHQQFxCQmBvJOvIbrqswRHVmdZRkmAP3FJApLr2Pxh2XiXcKna6p3Y3cR527PClH5R4JazfEYfe3CFHtbRsf2PzOd0R73aWY7+TrGvF3NHX2ri1Las/0zERAKGPnwDy2ttKQXvh1kmwMElv4gHd2wV4zE9fTsdJ2aWFW377SLjROEeLQU0FHqO/mUd4Bhu2ZNca/LUK9xA5A9Fvw5Y4qsmyrYPbQLEvG6EGDzwI4Vv/rFCjmf39Q5FpDnyv/A9D08xL/G6SbZkCbbeIa2SneE6Ax+MRTva1/h7ywROu3dFSZ4B48KSbJd1fgXlbj+geyaZdQ6n86q/qegVpe5u5sTvW4/Y0UN174cWO7/W/Cn0Y4ErBSPpKQcsW7+ttCKI/NVU5s8QlNhUh9ed6GxgFDRfDS1b5IbnAgzJDsbs+tszzejCRjXAZs70C+tZ/OgEm5GWZehXs33tik2194RbnQ+Y95ueP+WLrh2gIjQ4eMh5ly8hXrwps0ZylG3dHsKiFHOfhjjKVyCy8K9fW0nCjefInwGrB2qfyvX1qlMLaSBOImRwb3nak3AQP8BpK2VPeMvPhu2Qoec+icm3ZADHA0ehCLeNfqQ4JVsfDl4EE1W48qLT6QaNZtASeN5frRhuCW1A36+tn7l43qeihz9QaGMYcjvuQHv4PAYgONlo5IEenTtmh3xEoMdu3jMBm";

    // pattern代表要匹配的字段，line代表日志中的一行
    if (ft.Match(line))  // 匹配到了
        cout << "matched!" << endl;
    else
        cout << "Not matched!" << endl;
}
