//C++ file
/***********************************************
#
#      Filename: test.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-08-31 10:57:13
#**********************************************/
#include <ft2build.h>
#include <freetype.h>
#include <iostream>
using namespace std;
 
int main()
{
    FT_Library library;
    FT_Init_FreeType(&library);

    FT_Face face;
    FT_New_Face(library, "msyh.ttf", 0, &face);

    cout<<"num_glyphs:"<<face->num_glyphs<<endl;
    cout<<"num_faces:"<<face->num_faces<<endl;
    return 0;
}
