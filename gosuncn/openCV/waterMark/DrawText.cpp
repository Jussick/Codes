//C++ file
/***********************************************
#
#      Filename: DrawText.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 用opencv2给图片添加文字水印
#        Create: 2020-07-31 11:18:25
#**********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
#include <vector>
#include "CvxText.h"
#include "freetype.h"

#define FONT "/usr/share/fonts/myfonts/simhei.ttf"

//using namespace cv;
// using namespace std;
//去掉以上两行代码注释之后就可以不用在下面的代码中加上cv::和std::
//cv::为OpenCV的函数库
//std::为C++的标准函数库


int DrawTextTest() {
    const char* filename = "./me.jpg";

    cv::Mat mat = cv::imread(filename);
    if (mat.empty()) {
        throw("Faild open file.");
    }

    std::cout << "Rows: " << mat.rows << ", Cols: " << mat.cols << std::endl;

    cv::Point p = cv::Point(mat.cols / 15, mat.rows / 10);
    //加上字符的起始点
    cv::putText(mat, "Hello OpenCV", p, cv::FONT_HERSHEY_TRIPLEX, 0.8, cv::Scalar(255, 200, 200), 2, CV_AA);
    //在图像上加字符
    //第一个参数为要加字符的目标函数
    //第二个参数为要加的字符
    //第三个参数为字体
    //第四个参数为字的粗细
    //第五个参数为字符的颜色

    // cv::imshow("mat", mat);
    cv::imwrite("output.jpg", mat);

    cv::waitKey();

    return 0;
}

/* 读取图片到内存 */                           
std::string ReadPicture2Bytes(const std::string filename)
{                                              
    std::ifstream fin(filename, std::ios_base::binary);  
    // 计算图片大小                            
    fin.seekg(0, fin.end);                     
    int length = fin.tellg();                  
    fin.seekg(0, fin.beg);                     
                                               
    char *buffer = new char[length];           
    fin.read(buffer, length);                  
                                               
    return std::move(std::string(buffer, length));  
}                                              


static int ToWchar(char* &src, wchar_t* &dest, const char *locale = "zh_CN.utf8")
{
    if (src == NULL) {
        dest = NULL;
        return 0;
    }

    // 根据环境变量设置locale
    setlocale(LC_CTYPE, locale);

    // 得到转化为需要的宽字符大小
    int w_size = mbstowcs(NULL, src, 0) + 1;

    // w_size = 0 说明mbstowcs返回值为-1。即在运行过程中遇到了非法字符(很有可能使locale
    // 没有设置正确)
    if (w_size == 0) {
        dest = NULL;
        return -1;
    }

    //wcout << "w_size" << w_size << endl;
    dest = new wchar_t[w_size];
    if (!dest) {
        return -1;
    }

    int ret = mbstowcs(dest, src, strlen(src)+1);
    if (ret <= 0) {
        return -1;
    }
    return 0;
}


/***********************************************
#      函数名称: DrawTextTo(只能添加英文水印，中文的会乱码)
#
#   Description: 给一张二进制流图片添加水印，并返回该图片的二进制流
#     parameter: originPic --- string 原始图片的二进制流
                 appendText --- string 要添加的水印
#   returnValue: string 添加水印后的图片二进制流
#        Author: luhg
#        Create: 2020-08-25 19:39:06
#**********************************************/
std::string DrawTextTo(std::string &originPic, std::string appendText) 
{
    //转换格式,string转成mat
    std::vector<char> vec_data(originPic.c_str(), originPic.c_str()+originPic.size());

    cv::Mat mat = cv::imdecode(vec_data, CV_LOAD_IMAGE_UNCHANGED);
    if (mat.empty()) {
        throw("Faild open file.");
    }

    std::cout << "Rows: " << mat.rows << ", Cols: " << mat.cols << std::endl;

    //加上字符的起始点
    cv::Point p = cv::Point(mat.cols / 20, mat.rows / 20);
    cv::putText(mat, appendText.c_str(), p, cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(255, 200, 200), 2, /* CV_AA */ 8);
    // cv::putTextZH(mat, appendText.c_str(), p, cv::Scalar(255, 200, 200), 30, [> CV_AA <]"Arial");
    //在图像上加字符
    //第一个参数为要加字符的目标矩阵
    //第二个参数为要加的字符
    //第三个参数为要加的点的位置
    //第四个参数为字体
    //第五个参数为字的缩放系数
    //第六个参数为字符的颜色
    //第七个参数为子的粗细
    //第八个参数为字的线条类型

    // cv::imshow("mat", mat);
    // cv::imwrite("output.jpg", mat);

    cv::waitKey();

    // mat转成string
    std::vector<unsigned char> vec_out;
    std::string str;
    cv::imencode(".jpg", mat, vec_out);
    str.resize(vec_out.size());
    memcpy(&str[0], vec_out.data(), vec_out.size());
    
    return std::move(str);
}

/***********************************************
#      函数名称: DrawZHTextTo(能添加中文和英文的水印，需要freetype库)
#
#   Description: 给一张二进制流图片添加水印，并返回该图片的二进制流
#     parameter: originPic --- string 原始图片的二进制流
                 appendText --- string 要添加的水印
#   returnValue: string 添加水印后的图片二进制流
#        Author: luhg
#        Create: 2020-08-31 13:39:06
#**********************************************/
std::string DrawZHTextTo(std::string &originPic, std::string appendText) 
{
    //转换格式,string转成mat
    std::vector<char> vec_data(originPic.c_str(), originPic.c_str()+originPic.size());

    cv::Mat mat = cv::imdecode(vec_data, CV_LOAD_IMAGE_UNCHANGED);
    if (mat.empty()) {
        throw("Faild open file.");
    }

    std::cout << "Rows: " << mat.rows << ", Cols: " << mat.cols << std::endl;

    //加上字符的起始点
    cv::Point p = cv::Point(mat.cols / 20, mat.rows / 20);

    CvxText text(FONT);//这个是系统自带的宋体字体文件，可以选别的
    char *msg = (char *)appendText.c_str();
    wchar_t *w_str;
    ToWchar(msg, w_str);
    float p1 = 0.5;
    text.setFont(NULL, NULL, NULL, &p1);   // 透明处理（第二个参数可以设置字体大小旋转等）
    text.putText(mat, w_str, p, cv::Scalar(220, 20, 60));


    cv::waitKey();

    // mat转成string
    std::vector<unsigned char> vec_out;
    std::string str;
    cv::imencode(".jpg", mat, vec_out);
    str.resize(vec_out.size());
    memcpy(&str[0], vec_out.data(), vec_out.size());
    
    return std::move(str);
}


int main()
{
    //以下的方法如果想运行，直接把前头的注释去掉即可
    //运行代码的时候请改掉filename里的地址
    //我的opencv是安装在C盘目录下
    //一些目录地址请自行修改一下

        
    // DrawTextTest(); //在图像上添加文字水印

    std::string data = ReadPicture2Bytes("./me.jpg");
    std::string ret = DrawZHTextTo(data, "今天天气不错hahaha102309");

    std::ofstream fout("output.jpg");
    fout << ret;

    return 0;
}
