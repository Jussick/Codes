package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
	"time"
	"strconv"
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
func readfileContent(filepath string) (err error) {
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
	for i := 100; i > 0; i-- {
		time.Sleep(time.Duration(1) * time.Second)
		fmt.Printf("time remain: %ds\n", i)
	}
	return err
}

func findSmkData(line string) string {
	posBegin := strings.Index(line, "smkdata")
	smkDataLen := strings.Index(line[posBegin+8:], "&")
	smkdata := line[posBegin+8:posBegin+8+smkDataLen]
	return smkdata
}

// GetAeskeyFromSmkdata ...
func GetAeskeyFromSmkdata(rsaCipher *cipher.RsaCipher, smkdata []byte) ([]byte, error) {

	if len(smkdata) < 9 {
		return nil, errors.New("len(smkdata) < 9")
	}

	aeskeyLen, err := strconv.Atoi(string(smkdata[:8]))
	if err != nil {
		return nil, fmt.Errorf("failed to get aes key len, err:%s", err)
	}

	aesKey, err := rsaCipher.Decrypt(aeskeyLen, smkdata[8:])
	if err != nil {
		return nil, fmt.Errorf("failed to decrypt smkdata, err:%s", err)
	}

	return aesKey, nil
}

func main() {
	// ReadfileContent("out.log")
	smkdata := findSmkData("act=mbsdkdata&smkdata=0000000421d0055ef1436c417bd4da10f528f1a9&EC=37&appkey=44b8f2b988e258e1d036acd459af")
	fmt.Println("smkdata: ", smkdata)
}
