/*
 * Copyright (c) 2018 YY.com, Inc. All Rights Reserved
 *
 * @file patition_date.cc
 * @author zhongting(zhongting@yy.com)
 * @date 20189/06/15 09:00:00
 * @brief
 *
*/

#include "partition_date.h"
#include "util.h"

namespace cim {
namespace common {

Week::Week(int64_t timestamp) {
    time_t tt = timestamp / 1000;
    struct tm *ttime;
    ttime = localtime(&tt);
    time_t week_timestamp = tt - ttime->tm_wday*24*3600 - ttime->tm_hour*3600 - ttime->tm_min*60 - ttime->tm_sec;
    timestamp_ = week_timestamp * 1000;
}

std::string Week::GetPartitionDate() const {
    time_t tt = timestamp_ / 1000;
    struct tm *ttime;
    ttime = localtime(&tt);
    char week_first_day[64];
    strftime(week_first_day, 64, "%Y%m%d", ttime);
    return std::string(week_first_day);
}

Week Week::Next(uint32_t offset) {
    return Week(timestamp_ + offset*7*24*3600*1000);
}

Week Week::Prev(uint32_t offset) {
    return Week(timestamp_ > offset*7*24*3600*1000 ? timestamp_ - offset*7*24*3600*1000 : 0);
}

bool Week::operator==(const Week& week) {
    if (GetPartitionDate() == week.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Week::operator!=(const Week& week) {
    if (GetPartitionDate() != week.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Week::operator<(const Week& week) {
    if (GetPartitionDate() < week.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Week::operator>(const Week& week) {
    if (GetPartitionDate() > week.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Week::operator<=(const Week& week) {
    if (GetPartitionDate() <= week.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Week::operator>=(const Week& week) {
    if (GetPartitionDate() >= week.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

Month::Month(int64_t timestamp) {
    time_t tt = timestamp / 1000;
    struct tm *ttime;
    ttime = localtime(&tt);
    year_ =  ttime->tm_year+1900;
    month_ = ttime->tm_mon+1;
}

Month::Month(int32_t year, int32_t month) {
    year_ = year;
    month_ = month;
}

std::string Month::GetPartitionDate() const {
    return common::StringPrintf("%04d%02d", year_, month_);
}

static void NextMonth(int32_t* year, int32_t* month) {
    if (*month + 1 > 12) {
        *year = *year + 1;
        *month = 1;
        return;
    }
    *month = *month + 1;
}

static void PreMonth(int32_t* year, int32_t* month) {
    if (*month - 1  <= 0) {
        *year = *year - 1;
        *month = 12;
        return;
    }
    *month = *month - 1;
}

Month Month::Next(uint32_t offset) {
    int32_t year = year_;
    int32_t month = month_;
    for (int32_t i = 0; i < offset; i++) {
        NextMonth(&year, &month);
    }
    return Month(year, month);
}

Month Month::Prev(uint32_t offset) {
    int32_t year = year_;
    int32_t month = month_;
    for (int32_t i = 0; i < offset; i++) {
        PreMonth(&year, &month);
    }
    return Month(year, month);
}

bool Month::operator==(const Month& month) {
    if (GetPartitionDate() == month.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Month::operator!=(const Month& month) {
    if (GetPartitionDate() != month.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Month::operator<(const Month& month) {
    if (GetPartitionDate() < month.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Month::operator>(const Month& month) {
    if (GetPartitionDate() > month.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Month::operator<=(const Month& month) {
    if (GetPartitionDate() <= month.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

bool Month::operator>=(const Month& month) {
    if (GetPartitionDate() >= month.GetPartitionDate()) {
        return true;
    } else {
        return false;
    }
}

}
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
