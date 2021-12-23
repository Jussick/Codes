package main

import (
	"context"
	"log"

	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
	"go.mongodb.org/mongo-driver/mongo/readpref"
)

type BlackList struct {
	Appid     int64 `bson:"app_id"`
	Uid       int64 `bson:"uid"`
	Black_uid int64 `bson:"blacklisted_uid"`
}

const (
	KKeyAppid    = "app_id"
	KKeyUid      = "uid"
	KKeyBlackUid = "blacklisted_uid"
)

func main() {
	log.SetFlags(log.Llongfile | log.LstdFlags)

	opts := options.Client().ApplyURI("mongodb://localhost:27017")

	// 连接数据库
	client, err := mongo.Connect(context.Background(), opts)
	if err != nil {
		log.Fatal(err)
		return
	}

	// 判断服务是否可用
	if err = client.Ping(context.Background(), readpref.Primary()); err != nil {
		log.Fatal(err)
		return
	}

	// 获取集合
	collection := client.Database("test").Collection("blacklist")

	// 插入一条数据
	// doc := bson.M{KKeyAppid: 123123, KKeyUid: 321312, KKeyBlackUid: 233333}
	// insertOneResult, err := collection.InsertOne(context.Background(), doc)
	// log.Println("insertOneResult: ", insertOneResult)

	// 删除一条数据
	deleteResult, err := collection.DeleteOne(context.Background(), bson.M{KKeyAppid: 123123})
	log.Println("deleteResult: ", deleteResult)

	// 查询单条数据
	var one BlackList
	query := bson.M{KKeyAppid: 1396745405, KKeyUid: 2158001841, KKeyBlackUid: 2158001846}
	err = collection.FindOne(context.Background(), query).Decode(&one)
	if err != nil {
		log.Fatal(err)
	}
	log.Println("collection.FindOne: ", one)
}
