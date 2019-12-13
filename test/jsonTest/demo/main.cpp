
#include <iostream>
#include <json/json.h>

using namespace std;

int main1()
{
	/*write*/
	Json::FastWriter writer;
	Json::Value root;
	Json::Value array;
	Json::Value child;
	
	root["param1"]  = "param1";
	root["param2"] = 1;
	
	child["child1"] = "child1";
	child["child2"] = 2;
	array.append(child);//数组
	
	root["array"] = array;
	string json_str = writer.write(root);
	cout << "json str is: " << json_str << endl;
	
	/*read*/
	Json::Reader reader;  
	Json::Value root_json;

	if(reader.parse(json_str, root_json))
	{
		if(!root_json["param1"].isNull())
		{
			cout << root["param1"].asString() << endl;
		}
		if(!root_json["param2"].isNull())
		{
			cout << root["param2"].asInt() << endl;
		}
		if(!root_json["array"].isNull())
		{
			Json::Value child2 = root_json["array"];
			for(int i = 0; i < child2.size(); i++)
			{
				Json::Value tmp = child2[i];
				if(!tmp["child1"].isNull())
				{
					cout << tmp["child1"].asString() << endl;
				}
				if(!tmp["child2"].isNull())
				{
					cout << tmp["child2"].asInt() << endl;
				}
			}
			
		}
	}
    return 0;
}
int main()
{
    Json::FastWriter writer;
    Json::Value root;
    Json::Value FaceList;
    Json::Value subImageList;
    Json::Value cam1;
    Json::Value cam2;
    Json::Value cam3;
    Json::Value camsInfo;

    // 拼装json
    subImageList["ShotTime"] = "2018-09-06 08:59:14";
    subImageList["width"] = 240;
    subImageList["height"] = 272;
    subImageList["data"] = "asjhjsdkhfjkahj";

    cam1["id"] = "001";
    cam2["id"] = "002";
    cam3["id"] = "003";
    cam1["type"] = "高清";
    cam2["type"] = "红外";
    cam3["type"] = "紫外";
    cam1["status"] = true;
    cam2["status"] = false;
    cam3["status"] = true;
    camsInfo.append(cam1);
    camsInfo.append(cam2);
    camsInfo.append(cam3);

    root["SubImageList"] = subImageList;
    root["name"] = "edward";
    root["cameras"] = camsInfo;
    cout << root.toStyledString() << endl;
    cout << root << endl;

    string json_str = writer.write(root);
    cout << "json str is: " << json_str << endl;

    // 解析json
    Json::Reader reader;
    Json::Value parse_value;

    reader.parse(json_str, parse_value);
    if (parse_value.isMember("name"))
        cout << "name: " << parse_value["name"].asString() << endl;
    
    for (unsigned int i = 0; i < parse_value["cameras"].size(); ++i) {
        cout << "cam" << i << "-id" << parse_value["cameras"][i]["id"].asString() << endl;
        cout << "cam" << i << "-type" << parse_value["cameras"][i]["type"].asString() << endl;
        cout << "cam" << i << "-status" << parse_value["cameras"][i]["status"].asString() << endl;
        cout << endl;
    }
    
    return 0;
}

// int main()
// {
    // Json::Value j_root;
    // Json::FastWriter writer;
    // Json::Reader reader;

    // j_root["aaa"] = "张三";
    // cout << j_root.toStyledString() << endl;
// }
