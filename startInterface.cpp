#include "startInterface.h"
#include "tools.h"
#include <iostream>
#include <windows.h>
#define REDL SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY)
#define BLUEL SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY)
#define GREENL SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY)
#define YELLOWL SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN |FOREGROUND_INTENSITY)
#define PURPLRL SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE |FOREGROUND_INTENSITY)
CStartInterface::CStartInterface()
{
	REDL;
	Print(22, 24);   // S
	Print(22, 21);
	Print(23, 22);
	Print(23, 20);
	Print(23, 24);
	Print(24, 20);
	Print(24, 23);
	BLUEL;
	Print(26, 20);   // N
	Print(26, 21);
	Print(26, 22);
	Print(26, 23);
	Print(26, 24);
	Print(27, 21);
	Print(28, 22);
	Print(29, 23);   
	Print(30, 24);
	Print(30, 23);
	Print(30, 22);
	Print(30, 21);
	Print(30, 20);
	GREENL;
	Print(32, 24);   // A
	Print(33, 23);
	Print(34, 22);
	Print(35, 21);
	Print(36, 20);
	Print(37, 21);
	Print(38, 22);
	Print(39, 23);
	Print(40, 24);
	Print(35, 22);
	Print(36, 22);
	Print(37, 22);
	YELLOWL;
	Print(42, 20);   // K
	Print(42, 21);
	Print(42, 22);
	Print(42, 23);
	Print(42, 24);
	Print(43, 22);
	Print(44, 21);
	Print(44, 23);
	Print(45, 20);
	Print(45, 24);
	PURPLRL;
	Print(47, 22);   // E
	Print(47, 20);
	Print(47, 21);
	Print(47, 24);
	Print(47, 23);
	Print(48, 20);
	Print(48, 22);
	Print(48, 24);
	Print(49, 20);
	Print(49, 22);
	Print(49, 24);
}
void CStartInterface::Print(int x, int y) // ´òÓ¡snakeµÄº¯Êý
{
	setCursorPosition(x, y);
	std::cout << "¡ö";
}