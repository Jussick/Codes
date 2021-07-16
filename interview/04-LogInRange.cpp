//C++ file
/***********************************************
#
#      Filename: LogInRange.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 百度面试题: 问题描述见./LogInrange.png
#        Create: 2021-04-28 20:05:26
#**********************************************/
#include <iostream>
#include <vector>
#include <string>

typedef long u64;

// 命中则返回下标，否则返回右边界下标
int BinarySearch(const std::vector<std::pair<u64, std::string> >& origin_list, u64 search_time)
{
    int left = 0;
    u64 right = origin_list.size() - 1;

    while (left < right)
    {
        u64 mid = (left + right) / 2;
        u64 mid_time_stamp = origin_list[mid].first;

        if (mid_time_stamp == search_time)
        {
            return mid;
        }
        else if (mid_time_stamp > search_time)
        {
            right = mid - 1;
        }
        else if (mid_time_stamp < search_time)
        {
            left = mid + 1;
        }
    }
    return right;
}

std::vector<std::pair<u64, std::string> > cutLog(const std::vector<std::pair<u64, std::string> >& origin_list, u64 start_time, u64 end_time)
{
    int start_index = BinarySearch(origin_list, start_time);
    int end_index = BinarySearch(origin_list, end_time);
    std::vector<std::pair<u64, std::string> > ret_vec;

    ret_vec.reserve(end_index-start_index+10);
    for (int i = start_index; i < end_index; ++i)
    {
        ret_vec.push_back(origin_list[i]);
    }
    return ret_vec;
}


int main()
{

}
