#!/bin/bash

OFFLINEVIDEODIR=/home/Node/storage/video
THRESHOLD=1 # 单位 秒

# 判断目录是否为空
is_empty_dir(){
        return `ls -A $1|wc -w`
}

# 获取目录的创建时间
time_last_modify=
get_dir_create_time(){
    time_last_modify=`stat $1 | sed -n '6p' | awk '{print $2}'`
}

# 遍历父目录下的子目录，若子目录的创建时间在一天前且目录为空, 则删除此目录
for dir in `ls $OFFLINEVIDEODIR`
do
    if [ -d $dir ]
    then
        # 获取当前时间和目录最后修改时间的秒级时间戳
        time_now=`date "+%Y-%m-%d"`
        get_dir_create_time $dir  # get $time_last_modify
        t_now_seconds=`date -d $time_now +%s`
        t_modify_seconds=`date -d $time_last_modify +%s`

        if [ $(($t_now_seconds-$t_modify_seconds)) -gt $THRESHOLD ];then
            if is_empty_dir $dir;then
                echo "remove dir $dir"
                sudo rm -rf $dir
            fi
        fi
    fi
done
