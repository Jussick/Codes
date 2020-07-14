#!/bin/bash
MINSPACE=1000    # 单位MB(空间小于时开始删除)
MINUTEBEFORE=720    # 删除多少分钟以前的内容

df -m | sort -k 2n | awk '{print $1}' > diskfile

# 要清理的盘符是总空间最大的
targetDisk=`cat diskfile | awk 'END {print}'`
echo "Target disk is: $targetDisk"

remainSpace=`df -m | grep $targetDisk | awk '{print $2}'`
echo "Disk space: $remainSpace (MB)"

if [ $remainSpace -lt $MINSPACE];then
    echo "Start clean old pictures and packs..."
    find . -name "*.tgz" -o -name "*.jpg" -o -name "*.png" -mmin -$MINUTEBEFORE -exec rm -f {} \;
fi
rm -f diskfile
