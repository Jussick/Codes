package cipher

import (
	"crypto/rsa"

	"ciphertest/bpool"
)

// RsaCipherConfig : rsa private key file, bytepool size config
type RsaCipherConfig struct {
	RsaPrivKeyFile  string
	RichBytePoolCfg bpool.Config
}

// RsaCipher : decrypt rsa cipher text
type RsaCipher struct {
	rsaPrivKey *rsa.PrivateKey

	richBytePool *bpool.RichBytePool
}
