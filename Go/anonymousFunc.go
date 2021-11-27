package main

import (
	"fmt"
	"time"
)

/* 匿名函数的使用 */

func main() {
	var num int = 100

	go func(number *int, str string) {
		fmt.Println("In anonymousFunc number: ", *number)
		fmt.Println("In anonymousFunc str: ", str)
		*number++
	}(&num, "haha") // 这里括号里的参数表示传入的实参

	for i := 0; i < 3; i++ {
		time.Sleep(time.Duration(2) * time.Second) // 休眠两秒
		fmt.Println("In main num: ", num)          // 101

	}
}
