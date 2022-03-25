#include <windows.h>
#include "food.h"
#include "snake.h"
#include "map.h"
extern int m_initmap[][50];                                      // 导入全局地图
typedef struct _GAMEINFO                                         // 存档读档结构体
{                                        
	char name[10];												 // 存档点名称
	int mapCopy[50][50];										 // 拷贝的地图
	COORD foodPosition;											 // 食物位置
	int score;													 // 拷贝的分数
	int moveSpeed;												 // 拷贝的移动速度
	int snakeLength;											 // 拷贝的蛇的长度
	int snakeDirection;											 // 拷贝的行进方向
	COORD snake[200];											 // 拷贝的蛇身坐标
}GAMEINFO, *PGAMEINFO;
class CController
{
public:
	CController():m_speed(150), m_key(1), m_score(0){}			 // Controller类无参构造
	void showStart();											 // 开始界面
	void showSelect();											 // 选项界面
	int beforeGame(CSnake* snake, CFood* food, CMap* init_map);  // 选项操作
	void drawMap(CMap* init_map);								 // 画地图
	void game();												 // 游戏大循环
	int playGame(CSnake* snake, CFood* food);					 // 打印消除蛇身小循环
	void showSpeed();											 // 根据速度显示难度
	void updateScore();											 // 实时修改分数
	void updateDifficulty();									 // 以分数修改行进速度
	int waitKey(int moveDirection, CSnake* snake, CFood* food);  // 等待键盘输入
	int gameEnd();                                               // 游戏结束选项
	int gamePause();											 // 游戏暂停选项
	int keepFile(CSnake* snake, CFood* food);                    // 存档游戏
	int fileReading(CSnake* snake, CFood* food);                 // 读档游戏
private:
	int m_speed;												 // 速度
	int m_key;													 // 键盘输入按键
	int m_score;												 // 分数
	int m_isRead;												 // 是否读取存档记号
};

