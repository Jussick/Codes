package main

import (
	"fmt"
	"test/option"
)

func main() {
	opt, err := option.NewOptionBuddy("./conf/buddy.yaml")
	if err != nil {
		fmt.Println("err: ", err)
		return
	}
	fmt.Println("metrics.AppName: ", opt.Metrics.AppName)
	fmt.Println("redis.UrlList[0]: ", opt.Redis.UrlList[0])
}
