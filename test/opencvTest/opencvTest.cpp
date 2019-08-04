//C++ file
/***********************************************
#
#      Filename: opencvTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 打开一张图片，输出大小；再导出一张其复制
#        Create: 2019-08-01 09:09:44
#**********************************************/
#include <iostream>
#include <cstring>
#include <sstream>
#include <typeinfo>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "Base64.h"

using namespace std;
using namespace cv;

template <typename old_type, typename new_type>
new_type convert(old_type &data) {
    stringstream ss;
    ss << data;
    new_type out_data;
    ss >> out_data;

    return out_data;
}

void CopyPicture(string &pic_path) {
    Mat facePic = imread(pic_path);
    int size = facePic.elemSize() * facePic.cols * facePic.rows;
    cout << "图片大小为：" << size << "px" << endl;


    // Mat facePic1(facePic.size(), CV_8UC3);
    Mat facePic1(facePic.rows, facePic.cols, CV_8UC3);
    facePic1.data = facePic.data;
    imwrite("dst.jpg", facePic1);

    cout << pic_path << " has copied." << endl;
}


void Base64CopyPicture(string &pic_path) {
    Mat picMat = imread(pic_path);
    // 把picMat.data转换成string再操作
    stringstream ss;
    ss << picMat.data;
    string matStr = ss.str();
    cout << "matStr.length()" << matStr.length() << endl;
    cout << "strlen picMat: " << strlen((const char *)picMat.data) << endl;
    string encodeMatStr = base64_encode((unsigned const char *)matStr.c_str(), matStr.length());

    Mat newMat(picMat.size(), CV_8UC3);
    string decodeMatStr = base64_decode(encodeMatStr);
    newMat.data = (unsigned char *)(decodeMatStr.c_str());

    imwrite("baseDst.jpg", newMat);

    cout << "Base64 encode and decode copy of " << pic_path << " is over." << endl;

}

void Base64CopyPicture1(string &pic_path) {
    Mat picMat = imread(pic_path);
    // 直接使用picMat.data进行操作
    string encodeMatStr = base64_encode(picMat.data, strlen((const char *)picMat.data));  // strlen只能传入signed char*

    Mat newMat(picMat.size(), CV_8UC3);
    string decodeMatStr = base64_decode(encodeMatStr);
    newMat.data = (unsigned char *)(decodeMatStr.c_str());

    imwrite("baseDst.jpg", newMat);

    cout << "Base64 encode and decode copy of " << pic_path << " is over." << endl;

}


int main(int argc, char* argv[]) {
    string path = "ooo.png";
    // Base64CopyPicture1(path);
    
    CopyPicture(path);
    return 0;
}
