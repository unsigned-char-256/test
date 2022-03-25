
#include <windows.h>
using namespace std;
class CFood
{
public:
	CFood() : m_foodFlag(1)													// 无参构造
	{
		m_foodPosition.X = 27;
		m_foodPosition.Y = 25;
	}                                                       
	int getFoodFlag();														// 获取食物被吃标记
	COORD* getFoodPsition();												// 获取食物指针
	void setFoodFlag(int foodFlag);											// 设置食物被吃标记
	void setFoodPosition(int x, int y);										// 设置食物的位置
	void writeFood(int col, int row, char* content, int y = 0);             // 打印食物
	void  drawFood();														// 生成新的食物
	void  drawOldFood();													// 初进游戏生成食物
private:
	int m_foodFlag;															// 食物被吃标记
	COORD m_foodPosition;													// 食物位置
};
