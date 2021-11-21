package main

import "fmt"
// import "go"

func sum(arr []int, c chan int) {
    sum := 0
    for _,v := range arr {
        sum += v

    }
    c <- sum
}

func main() {
    arr := []int{1,2,3,4,5}
    c := make(chan int)
    go sum(arr[:len(arr)/2], c)   // 3 
    go sum(arr[len(arr)/2:], c)   // 12
    go sum(arr, c)    // 15

    x := <-c  // 15
    y := <-c  // 3
    z := <-c  // 12
    // x, y := <-c, <-c

    fmt.Println(x, y, z)
}
