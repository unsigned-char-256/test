#include "tools.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>
/*光标隐藏函数和初始化随机值种子*/
void premise(){   
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    srand((unsigned int)time(NULL)); 
}


/*设置窗口大小、窗口标题*/
void setWindowSize(int cols, int lines)
{
    system("title 贪吃蛇");
    char cmd[30];  //一个图形■占两个字符，故宽度乘以2
    sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
    system(cmd);
}


/*设置光标位置*/
void setCursorPosition(const int x, const int y)
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


/*设置文本颜色*/
void setColor(int colorID)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}


/*设置文本背景色*/
void setBackColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_RED |
        BACKGROUND_BLUE |
        BACKGROUND_GREEN |
        BACKGROUND_RED);
}