package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

/***********************************************
#      函数名称: ReadfileContent
#
#   Description: 读取文件内容并按行打印出来
#     parameter: filepath: 文件路径
#   returnValue: err: 错误信息
#   	 Author: luhg
#        Create: 2021-11-28 12:40:53
#**********************************************/
func ReadfileContent(filepath string) (err error) {
	// open file
	file, err := os.OpenFile(filepath, os.O_RDWR, 0666)
	if err != nil {
		panic(err)
		return
	}

	defer file.Close()

	// print file size
	stat, err := file.Stat()
	if err != nil {
		panic(err)
	}
	fmt.Println("file size: ", stat.Size())

	// print content by line
	buf := bufio.NewReader(file)

	var linenum = 0
	for {
		line, err := buf.ReadString('\n') // 以换行符分隔
		line = strings.TrimSpace(line)    // 去掉首尾空格
		if err != nil {
			if err == io.EOF {
				// fmt.Printf("line%d: %s\n", linenum, line)
				fmt.Println("file read to end!!!")
				break
			} else {
				panic(err)
				break
			}
		} else {
			fmt.Printf("line%d: %s\n", linenum, line)
		}
		linenum++
	}
	return err
}

func main() {

	ReadfileContent("out.log")
}
