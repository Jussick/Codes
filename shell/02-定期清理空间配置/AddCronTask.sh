#!/bin/bash

CURUSER=`whoami`
TASK="\\\"* * * * * /home/Node/SCOMM/AutoDel.sh\\\""

OS=`uname -a | awk '{print $1}'`
if [ $OS == "Darwin" ];then
    PROMOT_CMD="sudo su -"
elif [ $OS == "linux" ];then
    PROMOT_CMD="su - root"
fi

if [ ! -f "/var/spool/cron/crontabs/$CURUSER" ];then
    FILE_STATUS="no"
else
    FILE_STATUS="yes"
fi


read -p "Input root password: " PASSWD

# 修改crontab必须要用root用户
expect <<- EOF
    spawn $PROMOT_CMD
    expect "*Password*" 
    send "$PASSWD\r"
    expect "*root*"
    if { $FILE_STATUS == "no" } {
        send "touch /var/spool/cron/crontabs/$CURUSER\r"
    }
    expect "*"
    send "echo $TASK >> /var/spool/cron/crontabs/$CURUSER\r"
    expect "*"
    send "exit\r"
    expect eof
EOF

if [ $? -eq 0 ];then
    echo "$CURUSER's crontab has been modified successfully."
    exit 0
else
    echo "$CURUSER's crontab modified failed."
    exit -1
fi
