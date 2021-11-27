package main

import "fmt"

func test(str *string) {
	*str = "haha"
}

func main() {
	var ss string = "hehe"
	test(&ss)
	fmt.Println(ss)
}
