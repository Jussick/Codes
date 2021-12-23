package pkg1

import "fmt"

func Test2Func() {
	Test1Func()
}

func privateFunc() { // 小写开头的变量和方法，在同一个包下也都是可以访问的
	fmt.Println("this is a privateFunc.")
}
