#!/bin/bash

CURUSER=`whoami`
TASK='* * * * * /home/Node/SCOMM/AutoDel.sh'
read -p "Input root password: " PASSWD

# 修改crontab必须要用root用户
expect <<- EOF
    spawn su - root
    expect "*Password*" 
    send "$PASSWD\n"
    expect "*root*"
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
