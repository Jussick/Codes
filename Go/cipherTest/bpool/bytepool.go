package bpool

import (
	"errors"
	"sync"
)

// NewBytePool creates a new BytePool with config.
func NewBytePool(cfg Config) (*RichBytePool, error) {

	if cfg.SmallSize > cfg.StartSize || cfg.StartSize > cfg.MaxSize {
		return nil, errors.New("create BytePool config error")
	}

	bytepool := new(RichBytePool)

	bytepool.bufs = make(map[int]*sync.Pool)

	bytepool.bufs[cfg.SmallSize] = new(sync.Pool)
	bytepool.keys = append(bytepool.keys, cfg.SmallSize)

	for i := cfg.StartSize; ; i = int(float32(i) * 1.5) {
		bytepool.bufs[i] = new(sync.Pool)
		bytepool.keys = append(bytepool.keys, i)

		if i > cfg.MaxSize {
			break
		}
	}

	return bytepool, nil
}

// Get ...
// Get returns an byte buffer sized by arg from pool
//
// Got byte buffer may be returned to the pool via Put call.
// This reduces the number of memory allocations required for byte buffer management.
func (p *RichBytePool) Get(size int) *[]byte {

	makeSize := size
	for _, sizeKey := range p.keys {
		if size > sizeKey {
			continue
		}

		syncpool := p.bufs[sizeKey]
		v := syncpool.Get()
		if v == nil {
			makeSize = sizeKey
			break
		}

		buf := v.(*[]byte)
		*buf = (*buf)[:size]
		return buf
	}

	buf := make([]byte, 0, makeSize)
	buf = buf[:size]

	return &buf
}

// Put returns byte buffer to the pool.
func (p *RichBytePool) Put(b *[]byte) {

	if syncpool, ok := p.bufs[cap(*b)]; ok {
		*b = (*b)[:0]
		syncpool.Put(b)
	}
}
