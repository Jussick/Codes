package main

import (
	"fmt"
	"time"
)

func sum(arr []int, c chan int) {
	sum := 0
	for _, v := range arr {
		sum += v

	}
	c <- sum
}

func fibonacci(n int, c chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		c <- x
		x, y = y, x+y
	}
	close(c)
}

/* 每次随机向通道中放入1或2 */
func channelFun() {
	for {
		ch := make(chan int, 1)
		select {
		case ch <- 1:
		case ch <- 2:
		default:
		}
		i := <-ch
		fmt.Println("recieve from ch: ", i)
		time.Sleep(time.Duration(1) * time.Second)
	}
}

func tikTok(timeout chan int, senonds int) { // 定时seconds后向通道写数据
	time.Sleep(time.Duration(senonds) * time.Second)
	timeout <- 1
}

/* 用select判断超时 */
func channelTimeout(ch chan int) {
	timeout := make(chan int)

	go tikTok(timeout, 3)
	for {
		select { // 同时监听timeout和其他通道数据，其中一个有数据时返回，这样就做到了超时返回的功效
		case cond := <-timeout:
			fmt.Println("timeout!!!", cond)
			return
		case value := <-ch:
			fmt.Println("value receive: ", value)
			return
		}
	}

}

func sendValue2Channel(ch chan int) {
	time.Sleep(1e9)
	ch <- 100
}

func main() {
	/* ----------------------------------------无缓冲的通道---------------------------------------- */
	// fmt.Println("无缓冲的通道")
	// arr := []int{1, 2, 3, 4, 5}
	// c := make(chan int)         // 无缓冲的通道在没有接收者从通道接收数据时，发送方会阻塞
	// go sum(arr[:len(arr)/2], c) // 3
	// go sum(arr[len(arr)/2:], c) // 12
	// go sum(arr, c)              // 15

	// x, y, z := <-c, <-c, <-c

	// fmt.Println(x, y, z)

	/* ---------------------------------------有缓冲的通道----------------------------------------- */
	// fmt.Println("有缓冲的通道")
	// c := make(chan int, 10) // make一个通道的时候，第二个参数为通道的缓冲大小
	// go fibonacci(cap(c), c)

	// for i := range c {
	// fmt.Println(i)
	// }

	/* ----------------------------------------select的有趣使用---------------------------------------- */
	// channelFun()

	/* ----------------------------------------select实现超时功能---------------------------------------- */
	// ch := make(chan int)

	// go channelTimeout(ch)
	// go sendValue2Channel(ch)

	// time.Sleep(1e9 * 5)
}
