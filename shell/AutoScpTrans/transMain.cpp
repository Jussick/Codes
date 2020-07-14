//C++ file
/***********************************************
#
#      Filename: ttt.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-12-31 10:17:27
#**********************************************/
#include <iostream>
#include <map>
#include <stdlib.h>



void help()
{
    std::cout << "Usage: [program] moduleName" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        help();
        exit(1);
    }

    static std::map<std::string, std::string> g_map;
    g_map["AudioControl"] = "AUDIO";
    g_map["FaceDetect"] = "FACE";
    g_map["NavigationCommuication"] = "NAVICOMM";
    g_map["PhoenixCore"] = "ZMQ";
    g_map["ServerCommuication"] = "SCOMM";
    g_map["ServerCommuication-offline"] = "SCOMM";
    g_map["StateManage"] = "STATEMG";
    g_map["BoardCommunication"] = "BOARD";
    g_map["RobotCore"] = "CORE";
    g_map["SynthesisCommunication"] = "SYCOMM";
    g_map["VideoManage"] = "VDS";
    g_map["AudioControl-1"] = "AUDIO";
    g_map["FaceDetect-1"] = "FACE";
    g_map["NavigationCommuication-1"] = "NAVICOMM";
    g_map["PhoenixCore-1"] = "ZMQ";
    g_map["ServerCommuication-1"] = "SCOMM";
    g_map["StateManage-1"] = "STATEMG";
    g_map["BoardCommunication-1"] = "BOARD";
    g_map["RobotCore-1"] = "CORE";
    g_map["SynthesisCommunication-1"] = "SYCOMM";
    g_map["VideoManage-1"] = "VDS";

    std::string moduleName = argv[1];
    std::string moduleDir  = g_map[moduleName];
    std::string program    = "./trans.exp";

    std::string cmd = program + " " + moduleName + " " + moduleDir;
    system(cmd.c_str());
}
