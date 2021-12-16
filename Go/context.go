/* context包用法demo
context用于goroutine之间的信号同步，包含四个interface
	type Context interface {
		Deadline() (deadline time.Time, ok bool)
		Done() <-chan struct{}
		Err() error
		Value(key interface{}) interface{}
	}
1、Deadline — 返回 context.Context 被取消的时间，也就是完成工作的截止日期；
2、Done — 返回一个 Channel，这个 Channel 会在当前工作完成或者上下文被取消后关闭，多次调用 Done 方法会返回同一个 Channel；
3、Err — 返回 context.Context 结束的原因，它只会在 Done 方法对应的 Channel 关闭时返回非空的值；
如果 context.Context 被取消，会返回 Canceled 错误；
如果 context.Context 超时，会返回 DeadlineExceeded 错误；
4、Value — 从 context.Context 中获取键对应的值，对于同一个上下文来说，多次调用 Value 并传入相同的 Key 会返回相同的结果，该方法可以用来传递请求特定的数据；

下面的例子演示了context的使用方法。当handle的超时时间为500ms时，handle内没有超时，但在main中还是会等到ctx超时并打印；
若将超时时间改为1500ms，那么handle和main中就都超时 */

package main

import (
	"context"
	"fmt"
	"time"
)

func handle(ctx context.Context, duration time.Duration) {
	select {
	case <-ctx.Done():
		fmt.Println("handle ", ctx.Err())
	case <-time.After(duration):
		fmt.Println("process request with ", duration)
	}
}

func main() {
	ctx, cancle := context.WithTimeout(context.Background(), 1*time.Second)
	defer cancle()
	go handle(ctx, 1500*time.Millisecond) // 改这里
	select {
	case <-ctx.Done():
		fmt.Println("main ", ctx.Err())
	}
}
