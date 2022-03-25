#include <windows.h>

class CSnake
{
public:
	CSnake() : m_sankeLength(4), m_moveDirection(77)                      // 无参构造
	{
		for (int i = 0; i < 4; i++)
		{	// 初始蛇的坐标
			m_snake[i].X = 18 - i;
			m_snake[i].Y = 25;
		}
	}  
	void writeSnake(int n);                                              // 打印蛇
	int getSankeLength();												 // 获取蛇的长度
	COORD* getSnake();													 // 获取COORD类型蛇的指针
	int getMoveDirection();												 // 获取行进方向
	void setMoveDirection(int newMoveDirection);						 // 设置行进方向
	void setSnakeLength(int addN);									     // 设置蛇的长度
	void updateCoordinates();											 // 改变蛇身坐标
	bool isCollision(int x, int y);										 // 判断撞墙或者撞到自身
	void resetSnakeLength(int n);										 // 读取文档后重设长度
 	void resetSnake(COORD(*p));											 // 读取文档后重设蛇的坐标	
	void copySnake(COORD(*p));											 // 存档将蛇身坐标放进结构体数组中							
private:
	int m_sankeLength;													 // 蛇数组长度
	int m_moveDirection;												 // 行进方向
	COORD m_snake[200];													 // 蛇身坐标数组  
};

