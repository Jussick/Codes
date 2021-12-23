package bpool

import (
	"math/rand"
	"reflect"
	"testing"
)

func TestNewBytePool(t *testing.T) {

	cfg := Config{
		SmallSize: 128,
		StartSize: 50,
		MaxSize:   1024,
	}

	tests := []struct {
		name    string
		cfg     Config
		want    *RichBytePool
		wantErr bool
	}{
		{
			name:    "config error",
			cfg:     cfg,
			want:    nil,
			wantErr: true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got, err := NewBytePool(tt.cfg)
			if (err != nil) != tt.wantErr {
				t.Errorf("NewBytePool() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("NewBytePool() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestBytePool(t *testing.T) {

	cfg := Config{
		SmallSize: 128,
		StartSize: 512,
		MaxSize:   1024 * 800,
	}

	bytePool, err := NewBytePool(cfg)
	if err != nil {
		t.Errorf("NewBytePool() error = %v, not wantErr", err)
		return
	}

	tests := []struct {
		name    string
		argSize int
		retCap  int
	}{
		{
			name:    "1",
			argSize: 10,
			retCap:  128,
		},

		{
			name:    "2",
			argSize: 128,
			retCap:  128,
		},

		{
			name:    "3",
			argSize: 300,
			retCap:  512,
		},

		{
			name:    "4",
			argSize: 512,
			retCap:  512,
		},

		{
			name:    "5",
			argSize: 513,
			retCap:  int(512 * 1.5),
		},

		{
			name:    "6",
			argSize: 1024 + 100,
			retCap:  int(512 * 1.5 * 1.5),
		},

		{
			name:    "7",
			argSize: int(512 * 1.5 * 1.5),
			retCap:  int(512 * 1.5 * 1.5),
		},

		{
			name:    "8",
			argSize: 29524,
			retCap:  29524,
		},

		{
			name:    "9",
			argSize: 1024*800*2 + 1,
			retCap:  1024*800*2 + 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			ret := bytePool.Get(tt.argSize)
			if len(*ret) != tt.argSize {
				t.Errorf("except len(*ret) size equals arg size, arg size:%d, ret len:%d", tt.argSize, len(*ret))
				return
			}

			if cap(*ret) != tt.retCap {
				t.Errorf("argSize:%d, except cap(*ret) equals retCap, cap(*ret):%d, ret len:%d", tt.argSize, cap(*ret), tt.retCap)
				return
			}
		})
	}

}

func TestGetPutBytePool(t *testing.T) {
	cfg := Config{
		SmallSize: 128,
		StartSize: 512,
		MaxSize:   1024 * 800,
	}

	bytePool, _ := NewBytePool(cfg)

	for i := 0; i < 1000; i++ {
		byteSize := rand.Intn(1024*800 + 100)
		ret1 := bytePool.Get(byteSize)
		tmp := ret1
		bytePool.Put(ret1)

		ret2 := bytePool.Get(byteSize)
		bytePool.Put(ret2)

		if tmp != ret2 && (byteSize <= cfg.MaxSize) {
			t.Errorf("i:%d, byteSize:%d, get different *[]byte, ret1:%p, ret2:%p\n", i, byteSize, ret1, ret2)
			return
		}
	}
}
