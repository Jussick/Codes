package bpool

import "sync"

// Config for creating RichBytePool
type Config struct {
	SmallSize int
	StartSize int
	MaxSize   int
}

// RichBytePool represents byte buffer pool.
//
// Not high usage rate but avoiding allocating frequently.
type RichBytePool struct {
	bufs map[int]*sync.Pool
	keys []int // must sorted (asc)
}
