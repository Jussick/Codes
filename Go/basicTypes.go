/* 三种基本类型：array、slice、map*/

package main

import "fmt"

func main() {

	/* --------------------切片-------------------- */

	// var myslice = make([]int)
	// var myslice1 []int
	// myslice2 := []byte{'a', 'b', 'c', 'd'}

	var ar = []byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}
	myslice3 := ar[0:5] // 左闭右开
	for _, elem := range myslice3 {
		fmt.Printf("%c ", elem)
	}

	fmt.Println("myslice3.len: ", len(myslice3))
	fmt.Println("myslice3.cap: ", cap(myslice3))

	// var slice1 []int
	// slice2 := []int{1, 2, 3}
	// slice3 := ar[:]
	// slice4 := make([]int, 10)

	workdirs := make([][]string, 2)

	row_data := []string{"xlog", "ylog", "doip"}
	row_data2 := []string{"mlog", "log", "logip"}

	// workdirs[0] = row_data
	// workdirs[1] = row_data2

	workdirs = append(workdirs, row_data)
	workdirs = append(workdirs, row_data2)

	fmt.Println(workdirs)
	fmt.Println(len(workdirs))

	/* --------------------map-------------------- */
}
