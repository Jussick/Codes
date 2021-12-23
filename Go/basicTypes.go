/* 三种基本类型：array、slice、map*/

package main

import "fmt"

func main() {

	/* 数组定义了大小就无法改变，用的不多 */

	/* --------------------切片-------------------- */

	// var myslice = make([]int)
	// var myslice1 []int
	// myslice2 := []byte{'a', 'b', 'c', 'd'}

	var ar = []byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}
	myslice3 := ar[0:5] // 左闭右开
	// range用于map返回key，value；
	// range用于slice返回index，value
	// range用于[][]int这种二维slice时返回"一维数据，二维数据“"
	for _, elem := range myslice3 {
		fmt.Printf("%c ", elem)
	}

	fmt.Println("\nmyslice3.len: ", len(myslice3))
	fmt.Println("myslice3.cap: ", cap(myslice3))

	myslice4 := make([]int, 0, 10)   // 0表示slice的len是0，10表示slice的capacity是10，这样定义后的变量是不会占用内存的
	myslice4 = append(myslice4, 100) // append方法向切片最后添加元素，添加后的切片长度为1
	fmt.Println("myslice4.len: ", len(myslice4))
	fmt.Println("myslice4.cap: ", cap(myslice4))

	// var slice1 []int
	// slice2 := []int{1, 2, 3}
	// slice3 := ar[:]
	// slice4 := make([]int, 10)

	/* 二维切片的定义方法 */
	workdirs := make([][]string, 2)

	row_data := []string{"xlog", "ylog", "doip"}
	row_data2 := []string{"mlog", "log", "logip"}

	workdirs[0] = row_data
	workdirs[1] = row_data2

	// workdirs = append(workdirs, row_data)  // append方法是把元素追加到末尾
	// workdirs = append(workdirs, row_data2)

	fmt.Println(workdirs)
	fmt.Println(len(workdirs))

	/* --------------------map-------------------- */
	cityMap := make(map[int]string)
	cityMap[1] = "beijing"
	cityMap[2] = "shanghai"
	cityMap[3] = "guangzhou"

	city, ok := cityMap[3]
	if ok {
		fmt.Println("city is", city)
	} else {
		fmt.Println("mo such city!")
	}
	// 删除元素
	delete(cityMap, 1)
	fmt.Println("map len after delete one element: ", len(cityMap))

}
