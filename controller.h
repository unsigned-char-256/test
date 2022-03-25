#include <windows.h>
#include "food.h"
#include "snake.h"
#include "map.h"
extern int m_initmap[][50];                                      // ����ȫ�ֵ�ͼ
typedef struct _GAMEINFO                                         // �浵�����ṹ��
{                                        
	char name[10];												 // �浵������
	int mapCopy[50][50];										 // �����ĵ�ͼ
	COORD foodPosition;											 // ʳ��λ��
	int score;													 // �����ķ���
	int moveSpeed;												 // �������ƶ��ٶ�
	int snakeLength;											 // �������ߵĳ���
	int snakeDirection;											 // �������н�����
	COORD snake[200];											 // ��������������
}GAMEINFO, *PGAMEINFO;
class CController
{
public:
	CController():m_speed(150), m_key(1), m_score(0){}			 // Controller���޲ι���
	void showStart();											 // ��ʼ����
	void showSelect();											 // ѡ�����
	int beforeGame(CSnake* snake, CFood* food, CMap* init_map);  // ѡ�����
	void drawMap(CMap* init_map);								 // ����ͼ
	void game();												 // ��Ϸ��ѭ��
	int playGame(CSnake* snake, CFood* food);					 // ��ӡ��������Сѭ��
	void showSpeed();											 // �����ٶ���ʾ�Ѷ�
	void updateScore();											 // ʵʱ�޸ķ���
	void updateDifficulty();									 // �Է����޸��н��ٶ�
	int waitKey(int moveDirection, CSnake* snake, CFood* food);  // �ȴ���������
	int gameEnd();                                               // ��Ϸ����ѡ��
	int gamePause();											 // ��Ϸ��ͣѡ��
	int keepFile(CSnake* snake, CFood* food);                    // �浵��Ϸ
	int fileReading(CSnake* snake, CFood* food);                 // ������Ϸ
private:
	int m_speed;												 // �ٶ�
	int m_key;													 // �������밴��
	int m_score;												 // ����
	int m_isRead;												 // �Ƿ��ȡ�浵�Ǻ�
};

