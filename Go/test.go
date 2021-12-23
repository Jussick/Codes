package main

import (
	"fmt"
)

type shard int // 这里定义了一个新的类型，不是把定义一个int的别名，如果想定义别名要这样写：type shard = int

func (s shard) test() {
	fmt.Println("this is a test")
}

type shard2 struct {
	index int
}

func foo() (out []int) {
	for i := 0; i < 10; i++ {
		out = append(out, i)
	}
	return out
}

func foo3() (str string, err error) {
	str = "hahaha"
	err = nil
	return
}

func main() {
	str, err := foo3()
	fmt.Println(str)
	fmt.Println(err)
}
