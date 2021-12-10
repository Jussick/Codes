//C++ file
/***********************************************
#
#      Filename: protobufTest.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: protobuf的序列化和反序列化，以及数组的使用
#        Create: 2019-05-06 16:52:10
#**********************************************/
#include <iostream>
#include <string>
//#include <message_lite.h>
#include "include/Test.pb.h"
#include "include/PlayerPos.pb.h"
#define MAXSIZE 1024

using namespace std;
using namespace Test::protobuf;
using namespace Player::protobuf;

int main() {
	char buf[MAXSIZE];
	HeartInfo mybuf;

    // 序列化
	mybuf.set_type("client");
	mybuf.set_port(9999);
	mybuf.set_ip("localhost");
    // 数组元素赋值
    mybuf.add_memo("hahaha");
    mybuf.add_memo("hahaha2");
    // 或者这样
    // std::string *mm1 = mybuf.add_memo();
    // std::string *mm2 = mybuf.add_memo();
    // mm1->assign("hahaha", 6);
    // mm2->assign("hehehe", 6);
	mybuf.SerializeToArray(buf, MAXSIZE);


    // 反序列化
	HeartInfo mybuf1;
	mybuf1.ParseFromArray(buf, MAXSIZE);

	cout << "Type:"<<mybuf1.type() << "\t"
         << "IP:" << mybuf1.ip() << "\t"
         << "Port:" << mybuf1.port() << endl;
    // 数组元素解析
    for (int i = 0; i < mybuf1.memo().size(); ++i)
    {
        cout << mybuf1.memo()[i] << endl;
    }

    // proto嵌套赋值 
    PlayerPos player;
    Pos *pos = player.mutable_pos();    
    pos->set_x(1.1);
    pos->set_y(2.2);
    pos->set_z(3.3);

    player.set_playerid(1);

    // 打印一下
    if (player.has_pos())  // 先判断proto中有无此变量
    {
        cout << "--------------------------------\n";
        cout << "player.pos().msgs_size(): " << player.pos().msgs_size() << endl;
        cout << "player.id: " << player.playerid() << endl;
        cout << "player.pos.x: " << player.pos().x() << endl;
        cout << "player.pos.y: " << player.pos().y() << endl;
        cout << "player.pos.z: " << player.pos().z() << endl;
    }


	return 0;
}
