package main

import (
        "fmt"
        "bytes"
)

func main() {
        data := []byte("1,2\n3,4\n5,6\n7,89")
        lines := bytes.Split(data, []byte{10})
        line := bytes.Split(lines[0], []byte(","))

        fmt.Println(data)
        fmt.Println(lines)
        fmt.Println(line)

}
