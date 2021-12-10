/* 在此目录下执行go test即可执行单元测试。
注意：想要测试的文件需以_test命名 */

package main

import "testing"

func Hello() string {
	return "Hello, world."
}

func TestHello(t *testing.T) {
	want := "Hello, world."
	if got := Hello(); got != want {
		t.Errorf("Hello() = %q, want %q", got, want)
	}
}
