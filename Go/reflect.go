package main

import (
	"fmt"
	"reflect"
)

type student struct {
	name string
	age  int
}

func main() {
	/* -------------------通过反射获取变量的类型和值------------------- */
	person := "Edward"
	fmt.Println("Typeof person: ", reflect.TypeOf(person))
	fmt.Println("Valueof person: ", reflect.ValueOf(person))

	/* -------------------把反射类型显式转换为真实类型------------------- */
	v := reflect.ValueOf(1)
	fmt.Println(reflect.TypeOf(v))
	a := v.Interface().(int)
	fmt.Println("TypeOf a:", reflect.TypeOf(a), " a: ", a)

	/* -------------------获取结构体的类型和值------------------- */
	stu := student{"Edward", 28}
	fmt.Println(reflect.TypeOf(stu))
	fmt.Println(reflect.ValueOf(stu))
}
