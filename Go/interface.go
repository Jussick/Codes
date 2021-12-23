package main

import "fmt"

type Animal interface {
	Speak() string
}

type Dog struct {
}

func (d Dog) Speak() string { // 用值类型实现的方法
	return "Wang!"
}

type Cat struct {
}

func (c *Cat) Speak() string { // 用指针类型实现的方法
	return "Meow!"
}

type CppProgrammer struct {
}

func (p CppProgrammer) Speak() string { // 用值类型实现的方法
	return "Number one!"
}

/* ---------------------------------------------------------------------------------------- */
/* interface{} 类型，空接口，是导致很多混淆的根源。interface{} 类型是没有方法的接口。
由于没有 implements 关键字，所以所有类型都至少实现了 0 个方法，所以 所有类型都实现了空接口。
这意味着，如果您编写一个函数以 interface{} 值作为参数，那么您可以为该函数提供任何值。 */
func AcceptEverything(v interface{}) bool {
	fmt.Println("in func, parameter is: ", v)
	return true
}

func main() {
	Animals := []Animal{Dog{}, new(Cat), new(CppProgrammer)} // 用指针类型实现的方法只能通过指针调用，用值类型实现的方法既可以通过指针调用又可以通过值调用

	for _, ani := range Animals {
		fmt.Println(ani.Speak())
	}

	AcceptEverything("nihaowa")
}
