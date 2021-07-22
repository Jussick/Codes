#!/bin/bash

# network=$1
# str="interfaces-"$network

# test(){
    # echo $1
# }
# test 'haha'

# echo $str

# NETWORK="asdsa"
# if [ $NETWORK != "home" -a $NETWORK != "office" -a $NETWORK != "8floor" ];then
    # echo "error"
    # exit 1                                        
# fi

# type ls
# if [ $? -eq 0 ];then
    # echo "ls is exist."
# else
    # echo "Not exist ls!"
# fi

# while true
    # do 
        # echo "hahaha"
        # sleep 1
    # done

create_time="0000-00-00"
get_dir_create_time(){
    create_time=`stat $1 | sed -n '6p' | awk '{print $2}'`
}

get_dir_create_time .
echo $create_time

date1=`date "+%Y-%m-%d"`
echo $date1
