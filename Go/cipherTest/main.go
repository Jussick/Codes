package main

import (
	"ciphertest/bpool"
	"ciphertest/cipher"
	"fmt"
)

func main() {
	cfg := cipher.RsaCipherConfig{
		RsaPrivKeyFile: "./rsa.key",
		RichBytePoolCfg: bpool.Config{
			SmallSize: 128,
			StartSize: 512,
			MaxSize:   1024 * 10,
		},
	}
	rsaCipher, err := cipher.NewRsaCipher(cfg)
	if err != nil {
		fmt.Println("NewRsaCipher failed, err: ", err)
		return
	}

	decryptData, err := rsaCipher.Decrypt(4, []byte("2586a0247f52801cf762237c11571a3d"))
	if err != nil {
		fmt.Println("Decrypt err: ", err)
		return
	}
	fmt.Println("Decrypt data: ", string(decryptData[:]))
}
