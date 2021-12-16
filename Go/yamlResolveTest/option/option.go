package option

import (
	"fmt"
	"io/ioutil"

	"gopkg.in/yaml.v2"
)

func NewOptionBuddy(path string) (*BuddyOption, error) {
	ymalFile, err := ioutil.ReadFile(path)
	if err != nil {
		fmt.Println("readfile err")
		return nil, err
	}

	opt := new(BuddyOption)

	err = yaml.Unmarshal(ymalFile, opt)
	if err != nil {
		fmt.Println("Unmarshal err")
		return nil, err
	}
	opt.Service.ProfilePort = opt.Service.ServicePort + 1

	return opt, nil
}

type BuddyOption struct {
	Service Service `yaml:"service"`
	Consul  Consul  `yaml:"consul"`
	Mongo   Mongo   `yaml:"mongo"`
	Redis   Redis   `yaml:"redis"`
	IDC     IDC     `yaml:"idc"`
	Appconf Appconf `yaml:"appconf"`
	Log     Log     `yaml:"log"`
	Metrics Metrics `yaml:"metrics"`
}

type Service struct {
	Endpoint    string `yaml:"endpoint"`
	ServicePort int32  `yaml:"servicePort"`
	ProfilePort int32  `yaml:"profilePort"`
}

type Consul struct {
	ServiceNamePrefix string `yaml:"serviceNamePrefix"`
}

type Mongo struct {
	DbName                        string   `yaml:"dbName"`
	BuddyCollectiongShardCount    int32    `yaml:"buddyCollectionShardCount"`
	BlackListCollectionShardCount int32    `yaml:"blacklistCollectionShardCount"`
	InstanceCount                 int32    `yaml:"instanceCount"`
	MongoEndPointList             []string `yaml:"mongoEndPointList"`
}

type Redis struct {
	UrlList []string `yaml:"uriList"`
}

type IDC struct {
	GroupId int32 `yaml:"groupId"` // 机房id
	// 电信
	CtlIp string `yaml:"ctlIp"`
	// 网通
	CncIp string `yaml:"cncIp"`
	// 铁通
	CniiIp string `yaml:"cniiIp"`
	// 教育网
	EduIp string `yaml:"eduIp"`
	// 长城宽带
	WbnIp string `yaml:"wbnIp"`
	// 移动
	MobIp string `yaml:"mobIp"`
	// BGP
	BgpIp string `yaml:"bgpIp"`
	// 亚洲
	AsiaIp string `yaml:"asiaIp"`
	// 香港
	HkIp string `yaml:"hkIp"`
	// 南美
	SaIspIp string `yaml:"saIspIp"`
	// 巴西
	BraIp string `yaml:"braIp"`
	// 欧洲
	EuIp string `yaml:"euIp"`
	// 北美
	NaIp string `yaml:"naIp"`
	// 大洋洲
	OaIp string `yaml:"oaIp"`
	// 非洲
	AfIp string `yaml:"afIp"`
	// 内网
	interIp string `yaml:"interIp"`
}

type Appconf struct {
	AppConfUrl        string `yaml:"appConfUrl"`
	AppConfModuleType string `yaml:"appConfModuleType"`
	AppConfIntervalMs int32  `yaml:"appConfIntervalMs"`
}

type Log struct {
	LogLevel  string `yaml:"logLevel"`
	LogTarget string `yaml:"logTarget"`
	LogDir    string `yaml:"logDir"`
}

type Metrics struct {
	AppName     string `yaml:"appName"`
	AppVersion  string `yaml:"appVersion"`
	ServiceName string `yaml:"serviceName"`
}
