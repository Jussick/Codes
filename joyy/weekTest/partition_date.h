/*
 * Copyright (c) 2018 YY.com, Inc. All Rights Reserved
 *
 * @file patition_date.h
 * @author zhongting(zhongting@yy.com)
 * @date 20189/06/15 09:00:00
 * @brief
 *
*/

#pragma once

#include <stdlib.h>
#include <time.h>
#include <string>

namespace cim {
namespace common {

class Week {
public:
    Week(int64_t timestamp);

    int64_t GetTimestamp() {
        return timestamp_;
    };
    std::string GetPartitionDate() const;
    Week Next(uint32_t offset = 1);
    Week Prev(uint32_t offset = 1);

    bool operator==(const Week& week);
    bool operator!=(const Week& week);
    bool operator<(const Week& week);
    bool operator>(const Week& week);
    bool operator<=(const Week& week);
    bool operator>=(const Week& week);

private:
    // 注意，时间戳取到毫秒
    int64_t timestamp_;
};

class Month {
public:
    Month(int64_t timestamp);
    Month(int32_t year, int32_t month);
    int64_t GetTimestamp() {
        return timestamp_;
    };
    std::string GetPartitionDate() const;
    Month Next(uint32_t offset = 1);
    Month Prev(uint32_t offset = 1);

    bool operator==(const Month& month);
    bool operator!=(const Month& month);
    bool operator<(const Month& month);
    bool operator>(const Month& month);
    bool operator<=(const Month& month);
    bool operator>=(const Month& month);

private:
    // 注意，时间戳取到毫秒
    int64_t timestamp_;
    int32_t year_;
    int32_t month_;
};

}
}
