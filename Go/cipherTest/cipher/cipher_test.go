package cipher

import (
	"reflect"
	"testing"

	"git.duowan.com/bigdata/baichuan/lugu/bpool"
)

func TestRsaCipher_Decrypt(t *testing.T) {
	cfg := RsaCipherConfig{
		RsaPrivKeyFile: "../data/rsa.key",
		RichBytePoolCfg: bpool.Config{
			SmallSize: 128,
			StartSize: 512,
			MaxSize:   1024 * 10,
		},
	}

	rsacipher, err := NewRsaCipher(cfg)

	if err != nil {
		t.Fatalf("failed to create rsa cipher, err:%s", err)
	}

	type args struct {
		orgLen int
		src    []byte
	}
	tests := []struct {
		name    string
		args    args
		want    []byte
		wantErr bool
	}{
		{
			"-1-",
			args{
				4,
				[]byte("2586a0247f52801cf762237c11571a3d"),
			},
			[]byte("ywxN"),
			false,
		},

		{
			"-2-",
			args{
				4,
				[]byte("606663f395162cb45e0072334612a41c"),
			},
			[]byte("GKaK"),
			false,
		},

		{
			"-3-",
			args{
				4,
				[]byte("123456"),
			},
			nil,
			true,
		},

		{
			"-4-",
			args{
				4,
				[]byte("2586a0247f52801cf762237c11571a3d3"), //比case 1 末尾多了1个
			},
			nil,
			true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {

			got, err := rsacipher.Decrypt(tt.args.orgLen, tt.args.src)
			if (err != nil) != tt.wantErr {
				t.Errorf("RsaCipher.Decrypt() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("RsaCipher.Decrypt() = %v, want %v", got, tt.want)
			}
		})
	}
}

// func Test_smkdataHexBufPool(t *testing.T) {

// for i := 0; i < 100; i++ {
// needSize := rand.Intn(100)
// ret1 := acquireSmkdataHexBuf(needSize)
// tmp := ret1
// releaseSmkdataHexBuf(ret1)

// ret2 := acquireSmkdataHexBuf(needSize)
// if tmp != ret2 {
// t.Fatalf("needSize:%d, not same buf.", needSize)
// }
// }
// }

// func TestDecryptAes(t *testing.T) {
// type args struct {
// b64          bool
// plainTextLen int
// aeskey       []byte
// src          []byte
// }
// tests := []struct {
// name    string
// args    args
// want    []byte
// wantErr bool
// }{
// {
// "case1",
// args{
// true,
// 851,
// []byte("aM6Q"),
// []byte("rzXzduKKtorSICHvng/6O6937mwBmEUIaKxMPd9M6x00LFcLyHvGTotOYsDVkyFn9uDx/9vK8kGPJjbg4zVm1Ww248RT5JoJF9xdLihzVhlDiFWwA/yvHFiFSFbMBV4TuOjq+NhtavwpVudFNnYyWKwZPSrcYu7XUCtLoS+d+m1eHKmfniaN6roY11Mbqs8tB5nxNe2Xa/P8PRXkIYdbo4gF14w73ogDy2hzKPF0TK507eYS2mbKjqV/CYT1txtWktcwfOrv+Rf+X/odY3IPrhlxeoCE1x8Jnrn+gTOticz8+T4I1M7r3fAFMdb3aYnApy56LNwHVZHod7/x0cQLGHAexCcXKu608ZENzgl9az50Ba+u+VIUeu8FjVZf0hemLQAiq/5kWzXIDkd86gZFHudLG2jc1sqctHlVYSz3lMWcT1QO3KgPHGYMBjwXkqRtGmXGWgZj4NY/drRKnyScNSGkm20b6fKz8ezXIGLXJQNTbkrL7c3tcng33Ch3krfihu4EZFdAEOjri7MsPZfzIgnhoXUYC2v/mXPN5N4LpxeFtHSYHgVamMEr94hTNe4hzFCLqk5Yz+egGrpjrf2emS3nysuGNXr/Lv2yyNSM8gZ8U20FH+imQPAT5vBcSJv6SOSbAy/6SNd/tOW9dcaGWi1rzuDYCfFATFd/De6yKJqaV5koG360ixbH1nv5KSPYVA/rM4G5/T5I8z/gSeT9fNfwH8UZnVhwh0SXoxaKoadsm6F+AWiCbl8EeQwwLacoIzHMlwAQPm5f8vkMInbHpUzhX4s59tdtvziDeKYn5ssYJ3ttVmry0DTqsqSe/C0SS/+XT5bqUernX0i0pH6zSNi3Wbwpu9F3ZP+31DiI5dGWKkFe3NOfDrKUndwoZmWHK9/1ezBO7yUJHNUp90fAm/4MJlP2MkLXKJgkDtfhkLNaSo1tI2jTXE+LgoMGWqEhSqPtmeSb9WRo2xmMpxzrQxDLYTgmrj5w0LdOXOB5RNEncreeMJ391uBUUxB62WyyCv53PNCtPxco+EHtPBE9IKJ1kxyKtpAUHiZV4ixFGSDCBnFQXINY1zzjxwZIJQJWX/+wsP3lvK58AWlKRYnkz5is8WImPi9Ji/aE0GsNSzoghzUA3kks7Khf1ErWUyGG"),
// },
// []byte("act=mbsdkprotocol&app=yym-hago-and&appkey=7c74186bd3a1e25806e3e2a11c1f30b7&arid=603c1da55c212483&eventid=20023805&from=official&gaid=b0564966-0ed1-4b67-84ab-075cfb8a602b&guid=1ad2cbc2-d2d3-438e-9&hdid=a5ef4b819d5ca948ff60104529469d44&idfv=28f02b3c0247404aae4c6f2b733322d8&imc=null%2Cnull&key=2c2931c113a4041cea73ac778673cea1&mbl=en-GB&mbos=Android8.0.0&moreinfo=%7B%22referer%22%3A%22HomePage%22%2C%22event_xxx_cur_user%22%3A%224316488922%22%2C%22function_id%22%3A%22recommend_people_show%22%2C%22page%22%3A%22DiscoverPeople%22%2C%22event_time%22%3A%221583143072508%22%7D&net=4&ntm=405%3A857&opid=biffffffffc95e7666ffffffff95ef12af&prodid=friend&region=1&sdkver=3.4.81&sessionid=f13a75b5bbac21b8177d&sjm=SM-C701F&sjp=samsung&sr=1080x1920&sys=2&time=1583143073&timezone=GMT%2B5&type=judge&uid=4316488922&value=1&ver=3.15.7&hd_p=E&hd_stime=1583143198600"),
// false,
// },
// {
// "case2",
// args{
// true,
// 851,
// []byte("aM6Q"),
// []byte("rzXzduKKtorSICHvng/6O6937mwBmEUIaKxMPd9M6x00LFcLyHvGTotOYsDVkyFn9uDx/9vK8kGPJjbg4zVm1Ww248RT5JoJF9xdLihzVhlDiFWwA/yvHFiFSFbMBV4TuOjq+NhtavwpVudFNnYyWKwZPSrcYu7XUCtLoS+d+m1eHKmfniaN6roY11Mbqs8tB5nxNe2Xa/P8PRXkIYdbo4gF14w73ogDy2hzKPF0TK507eYS2mbKjqV/CYT1txtWktcwfOrv+Rf+X/odY3IPrhlxeoCE1x8Jnrn+gTOticz8+T4I1M7r3fAFMdb3aYnApy56LNwHVZHod7/x0cQLGHAexCcXKu608ZENzgl9az50Ba+u+VIUeu8FjVZf0hemLQAiq/5kWz"),
// },
// nil,
// true,
// },
// }
// for _, tt := range tests {
// t.Run(tt.name, func(t *testing.T) {
// var aesCompressedData []byte
// var b64Buffer *[]byte
// if tt.args.b64 {
// b64Data := tt.args.src
// b64Buffer = B64RichBytePool.Get(b64StdEncoding.DecodedLen(len(b64Data)))
// b64SrcLen, err := b64StdEncoding.Decode(*b64Buffer, b64Data)
// defer B64RichBytePool.Put(b64Buffer)
// if err != nil {
// t.Errorf("failed to base64 encode, err:%s", err)
// }

// aesCompressedData = (*b64Buffer)[:b64SrcLen]
// } else {
// aesCompressedData = tt.args.src
// }

// got, err := DecryptAes(tt.args.plainTextLen, tt.args.aeskey, aesCompressedData)

// if (err != nil) != tt.wantErr {
// t.Errorf("DecryptAes() error = %v, wantErr %v", err, tt.wantErr)
// return
// }
// if !reflect.DeepEqual(got, tt.want) {
// t.Errorf("DecryptAes() = %v, want %v", got, tt.want)
// }
// })
// }
// }
