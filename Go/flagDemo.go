/* flag包的用法演示 */
package main

import ( 
    "fmt"
    "flag"
)

/***********************************************
#      函数名称: flag.String(opt string, default_Value string, prompt string)
#
#   Description: 初始化一个flag string，用于命令行输入选项获取值
#     parameter: opt 选项名
                 default_Value 默认值
                 prompt 提示
#   returnValue: 一个flag string类型的指针
#        Author: luhg
#        Create: 2021-11-03 18:25:40
#**********************************************/
var cliName = flag.String("name", "Edward", "Input your name")  
var cliAge = flag.Int("age", 27, "Input your age")
var cliGender = flag.String("gender", "male", "Input your age")

var myFlag int
func Init() {
    flag.IntVar(&myFlag, "myFlag", 100, "Just for demo")  // flag.String可以先定义再初始化
}

func main() {
    Init()

    flag.Parse()

    fmt.Printf("args=%s, num=%d\n", flag.Args(), flag.NArg())  // Args表示未解析的参数，NArg代表未解析的参数个数
    for i := 0; i != flag.NArg(); i++ {
        fmt.Printf("arg[%d] = %s\n", 1, flag.Arg(i))
    }

    fmt.Printf("name = %s\n", *cliName)
    fmt.Printf("age = %d\n", *cliAge)
    fmt.Printf("gender = %s\n", *cliGender)
    fmt.Printf("myFlag = %d\n", myFlag)
}

/* 
    测试1：无输入参数
    测试2：输入-name Edward -age 18 -gender male
    测试3：输入-name Edward haha hehe
    测试4：输入-job it 
*/
