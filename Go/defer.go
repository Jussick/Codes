package main

import "fmt"

func main() {
	defer fmt.Println("func is over.")     // defer调用在本函数所有其他调用执行完毕后执行
	defer fmt.Println("after over heihei") // defer相当于压栈，有多个defer时，按照调用相反的顺序执行

	fmt.Println("hello")
}
