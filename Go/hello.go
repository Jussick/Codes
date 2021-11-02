package main

import "fmt"

func main() {
	// fmt.Println("Hello, World!")

	// const (
	// x = iota;
	// y = iota;
	// )
	// fmt.Println("x = ", x, "y = ", y)

	// var number = 1;
	// fmt.Println("number: ", number)

	var myArray [10]int = [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

	fmt.Println("Elements in myArray:")
	for _, v := range myArray {
		fmt.Print(v, " ")
	}

	var mySlice []int = myArray[:5]
	fmt.Println("\nElements in mySlice:")
	for _, v := range mySlice {
		fmt.Print(v, " ")
	}

	mySlice2 := make([]int, 5, 20)
	fmt.Println()
	fmt.Println("slice len: ", len(mySlice2))
	fmt.Println("slice cap: ", cap(mySlice2))

	func haha(ss string, num float64) {
		
	}
}
