package main

import "fmt"

func add(args ...int) (sum int) { // 代码中的args是一个数组切片，而且只能放在参数中的最后面
	sum = 0
	for _, num := range args {
		sum += num
	}
	return sum
}

/*
任意类型的不定参数，用interface{}表示
*/
func MyPrintf(args ...interface{}) {
	for _, arg := range args { //迭代不定参数
		switch arg.(type) {
		case int:
			fmt.Println(arg, "is int")
		case string:
			fmt.Println(arg, "is string")
		case float64:
			fmt.Println(arg, "is float64")
		case bool:
			fmt.Println(arg, " is bool")
		default:
			fmt.Println("未知的类型")
		}
	}
}

func main() {
	fmt.Println(add(1, 2, 3, 4)) // 10
	MyPrintf(1, "haha", 1.32, true)
}
