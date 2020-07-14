#!/bin/bash

echo "Please input password:"
read password

# 关闭服务
cd /home/Node/GSOMNode/Node/
echo ${password} | sudo ./stop.sh
cd /home/Node/GSOMNode/updater/
echo ${password} | sudo ./stop.sh

# 重置数据库字段
expect <<- EOF
    spawn sqlite3 /home/Node/GSOMNode/Node/omnode_v0.db
    expect "sqlite> "                                  
    send "update tb_app_guard set REBOOT_TIMES=0;\r"
    expect "sqlite> "                                  
    send "update tb_app_guard set REBOOT_TIMES=0;\r"   
    expect "sqlite> "                                  
    send ".quit\r"                                     
    expect eof                                         
    send_user "\nreset complete!!!\n\n"                
EOF

# 重新启动服务
cd /home/Node/GSOMNode/Node/
echo ${password} | sudo ./start.sh
cd /home/Node/GSOMNode/updater/
echo ${password} | sudo ./start.sh
