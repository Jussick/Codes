// struct在go中扮演了如c++中类或者命名空间的角色，可以把一个函数的作用域限定在某个struct中，
// 然后在那个函数中就可以使用该struct定义的变量了；不同的函数可以通过这种方式共享同一片数据。

package main

import "fmt"

/* ------------------------- basic ----------------------------- */
type myType struct {
	ch   chan int
	name string
}

func (mt *myType) init() {
	mt.ch = make(chan int, 10)
	mt.name = "Edward"
}

func (mt *myType) fun1() {
	fmt.Println("In fun1, name is ", mt.name)
	go func(ch chan int) {
		ch <- 100
	}(mt.ch)
	fmt.Println("send 100 to ch...")
}

func (mt *myType) fun2() {
	fmt.Println("In fun2, name is", mt.name, ", too.")
	rec_val := <-mt.ch
	fmt.Println("recv from ch: ", rec_val)
}

/* ------------------------- 结构体匿名成员 ----------------------------- */
type AnnomousTest struct {
	*mytype
}

func main() {
	// mt := myType{}
	// mt.init()
	// mt.fun1()
	// mt.fun2()

	/* ------------------------------------------- */

	var obj AnnomousTest
	AnnomousTest.name = "haha"
}
