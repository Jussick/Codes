package main

import "fmt"

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

func main() {
	fmt.Println("无缓冲的通道")
	arr := []int{1, 2, 3, 4, 5}
	c := make(chan int)         // 无缓冲的通道在没有接收者从通道接收数据时，发送方会阻塞
	go sum(arr[:len(arr)/2], c) // 3
	go sum(arr[len(arr)/2:], c) // 12
	go sum(arr, c)              // 15

	x := <-c // 15
	y := <-c // 3
	z := <-c // 12
	// x, y := <-c, <-c

	fmt.Println(x, y, z)

	fmt.Println("有缓冲的通道")
	c := make(chan int, 10) // make一个通道的时候，第二个参数为通道的缓冲大小
	go fibonacci(cap(c), c)

	for i := range c {
		fmt.Println(i)
	}
}
