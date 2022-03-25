#include "tools.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>
/*������غ����ͳ�ʼ�����ֵ����*/
void premise(){   
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    srand((unsigned int)time(NULL)); 
}


/*���ô��ڴ�С�����ڱ���*/
void setWindowSize(int cols, int lines)
{
    system("title ̰����");
    char cmd[30];  //һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
    sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
    system(cmd);
}


/*���ù��λ��*/
void setCursorPosition(const int x, const int y)
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


/*�����ı���ɫ*/
void setColor(int colorID)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}


/*�����ı�����ɫ*/
void setBackColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_RED |
        BACKGROUND_BLUE |
        BACKGROUND_GREEN |
        BACKGROUND_RED);
}