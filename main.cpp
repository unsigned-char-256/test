#include "controller.h"
#include <stdlib.h>
#include <windows.h>
#include "tools.h"
int m_initmap[50][50];             //定义全局地图
int isEditor = 0;
int main()
{
	/*提前隐藏光标和设置随机数种子*/
	premise(); 
	/*开始游戏*/
	CController c;
	c.game();
	return 0;
}