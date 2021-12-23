package cipher

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/md5"
	"crypto/rsa"
	"crypto/x509"
	"encoding/base64"
	"encoding/hex"
	"encoding/pem"
	"errors"
	"fmt"
	"io/ioutil"
	"sync"

	"ciphertest/bpool"
)

// NewRsaCipher create a cipher which can decrypt rsa ciphertext.
func NewRsaCipher(cfg RsaCipherConfig) (*RsaCipher, error) {

	c := new(RsaCipher)

	err := c.initSelf(&cfg)

	if err != nil {
		return nil, err
	}

	return c, nil
}

func (c *RsaCipher) initSelf(cfg *RsaCipherConfig) error {
	// rsa private key
	err := c.initRsaPrivKey(cfg.RsaPrivKeyFile)
	if err != nil {
		return err
	}

	err = c.initBytePool(cfg.RichBytePoolCfg)

	if err != nil {
		return err
	}

	return nil
}

func (c *RsaCipher) initRsaPrivKey(rsaPrivFile string) error {
	content, err := ioutil.ReadFile(rsaPrivFile)

	if err != nil {
		return fmt.Errorf("failed to read rsa private key file:%s, err:%s", rsaPrivFile, err)
	}

	// 获取私钥
	block, _ := pem.Decode(content)
	if block == nil || block.Type != "RSA PRIVATE KEY" {
		return errors.New("failed to decode rsa key")
	}

	priv, err := x509.ParsePKCS8PrivateKey(block.Bytes)
	if err != nil {
		return errors.New("failed to parse PKCS8 private key")
	}

	rsaPrivKey, ok := priv.(*rsa.PrivateKey)
	if !ok {
		return errors.New("failed to type assert : key interface to rsa.PrivateKey")
	}

	c.rsaPrivKey = rsaPrivKey

	return nil
}

func (c *RsaCipher) initBytePool(cfg bpool.Config) error {
	// bufer
	richBytePool, err := bpool.NewBytePool(cfg)

	if err != nil {
		return err
	}

	c.richBytePool = richBytePool

	return nil
}

var smkdataHexBufPool sync.Pool

func acquireSmkdataHexBuf(byteSize int) *[]byte {
	v := smkdataHexBufPool.Get()
	if v == nil {
		buf := make([]byte, byteSize)
		buf = buf[:byteSize]
		return &buf
	}

	hexBuf := v.(*[]byte)
	if cap(*hexBuf) < byteSize {
		buf := make([]byte, byteSize)
		buf = buf[:byteSize]
		return &buf
	}

	*hexBuf = (*hexBuf)[:byteSize]

	return hexBuf
}

func releaseSmkdataHexBuf(v *[]byte) {
	smkdataHexBufPool.Put(v)
}

// Decrypt rsa cipther data specified plaintext len
func (c *RsaCipher) Decrypt(orgLen int, src []byte) ([]byte, error) {

	// 十六进制数据转为byte slice
	srcLen := len(src)
	if srcLen%2 == 1 {
		fmt.Println("转换16进制失败!!!")
		return nil, errors.New("rsa cipher : odd lenth of encrypted data")
	}

	hexBuf := acquireSmkdataHexBuf(hex.DecodedLen(srcLen))
	defer releaseSmkdataHexBuf(hexBuf)

	if _, err := hex.Decode(*hexBuf, src); err != nil {
		fmt.Println("hex.Decode failed!!!")
		return nil, err
	}

	orgData, err := rsa.DecryptPKCS1v15(nil, c.rsaPrivKey, *hexBuf)
	if err != nil {
		fmt.Println("DecryptPKCS1v15 failed!!!")
		return nil, err
	}

	if len(orgData) < orgLen {
		fmt.Println("长度校验失败！！！")
		return nil, fmt.Errorf("len of decrypted rsa data less than excepted, %d < %d", len(orgData), orgLen)
	}

	return orgData[:orgLen], nil
}

// AES  解密

var b64StdEncoding = base64.StdEncoding

// B64RichBytePool : Base64 decode byte pool
var B64RichBytePool = NewB64RichBytePool()

// NewB64RichBytePool generate common bytepool for base64 decoding.
func NewB64RichBytePool() *bpool.RichBytePool {

	pool, _ := bpool.NewBytePool(bpool.Config{
		SmallSize: 512,
		StartSize: 1024,
		MaxSize:   1024 * 10,
	})

	return pool
}

// DecryptAes ...
// src mustn't use after this because dst data in-place write in src under slice
func DecryptAes(plainTextLen int, aeskey []byte, src []byte) ([]byte, error) {

	// aes 解密
	aeskeyMd5Array := md5.Sum(aeskey)
	aeskeyMd5Slice := aeskeyMd5Array[:]

	aesBlock, err := aes.NewCipher(aeskeyMd5Slice)
	if err != nil {
		return nil, fmt.Errorf("failed to create aes cipher. err:%s", err)
	}

	blockSize := aesBlock.BlockSize()
	blockMode := cipher.NewCBCDecrypter(aesBlock, aeskeyMd5Slice[:blockSize])

	if len(src)%blockSize != 0 {
		return nil, errors.New("aes cipher text input error")
	}

	blockMode.CryptBlocks(src, src)

	if plainTextLen > len(src) {
		return nil, errors.New("client arg len > aes decrypted plain data")
	}

	return src[:plainTextLen], nil
}
