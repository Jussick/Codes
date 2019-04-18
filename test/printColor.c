//C file
/***********************************************
#
#      Filename: printColor.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 
				设置打印信息的字体颜色，在终端类型为"linux"下测试通过。
				格式：<ESC>[{attr};{fg}此处为打印信息<ESC>[{gb}m
				另一种格式
				<ESC>[{attr};{fg};{bg}m
				此处为打印信息
				<ESC>[RESET;{fg};{bg}m <--此处是复位属性，否则会影响后面的输出信息
				0x1b为转义字符"^[" {attr}为字体属性 {fg}为字体颜色 "[0m"为黑色背景
				前景色(字体)
				30      Black
				31      Red
				32      Green
				33      Yellow
				34      Blue
				35      Magenta
				36      Cyan
				37      White
				背景色
				bg:
				40      Black
				41      Red
				42      Green
				43      Yellow
				44      Blue
				45      Magenta
				46      Cyan
				47      White
				注：两种颜色索引值一致，一个是30开始，一个是40开始
#        Create: 2018-09-04 10:42:03
#**********************************************/

 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
 
#define RESET           0
#define BRIGHT          1
#define DIM             2
#define UNDERLINE       4
#define BLINK           5
#define REVERSE         7
#define HIDDEN          8
 
#define BLACK           0
#define RED             1
#define GREEN           2
#define YELLOW          3
#define BLUE            4
#define MAGENTA         5
#define CYAN            6
#define WHITE           7
 
// ===================================
void textcolor(int attr, int fg, int bg)
{
    char command[13];
 
    /* Command is the control command to the terminal */
    sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
    printf("%s", command);
}
 
void color_test(void)
{
    textcolor(BRIGHT, RED, GREEN);  
    printf("hello %d\n", 250);
    textcolor(RESET, WHITE, BLACK); 
}
 
//==================================
#define BUG_LEN 1024
void my_vprint(char* fmt, va_list va_args)
{
	char buffer[BUG_LEN] = {0};
	vsnprintf(buffer, BUG_LEN-1, fmt, va_args);
	printf("%s", buffer);
}
 
// 不使用背景色
void _print_color(int attr, int color, const char* fmt,...)
{
    char buffer[BUG_LEN] = {0};
    va_list marker;
    va_start(marker, fmt);
 
    // 背景色为0时，不影响后面的信息，其它值会影响
    snprintf(buffer, BUG_LEN-1, "\x1b[%d;%dm%s\x1b[0m", attr, color+30, fmt);
    my_vprint(buffer, marker);  // 一定要这个函数才能使用可变参数
    va_end(marker);
}
 
// 要用宏，用函数的话，不能用可变参数
#define print_color(attr, color, fmt,...) _print_color(attr, color, fmt, ##__VA_ARGS__)
#define warn(fmt, ...) _print_color(BRIGHT, YELLOW, fmt, ##__VA_ARGS__)
#define err(fmt, ...) _print_color(BRIGHT, RED, fmt, ##__VA_ARGS__)
 
#if 01
int main(void)
{
    int i = 0;
    for (i =0 ; i < 7; i++)
    {
        print_color(1, i, "color info test hello %s\n", "world");
    }
    //warn("warn: hello %s %d \n", "world", 250);
    //err("err: hello %s %d\n", "world", 250);
    return 0;
}
#endif
