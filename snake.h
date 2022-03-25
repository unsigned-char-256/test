#include <windows.h>

class CSnake
{
public:
	CSnake() : m_sankeLength(4), m_moveDirection(77)                      // �޲ι���
	{
		for (int i = 0; i < 4; i++)
		{	// ��ʼ�ߵ�����
			m_snake[i].X = 18 - i;
			m_snake[i].Y = 25;
		}
	}  
	void writeSnake(int n);                                              // ��ӡ��
	int getSankeLength();												 // ��ȡ�ߵĳ���
	COORD* getSnake();													 // ��ȡCOORD�����ߵ�ָ��
	int getMoveDirection();												 // ��ȡ�н�����
	void setMoveDirection(int newMoveDirection);						 // �����н�����
	void setSnakeLength(int addN);									     // �����ߵĳ���
	void updateCoordinates();											 // �ı���������
	bool isCollision(int x, int y);										 // �ж�ײǽ����ײ������
	void resetSnakeLength(int n);										 // ��ȡ�ĵ������賤��
 	void resetSnake(COORD(*p));											 // ��ȡ�ĵ��������ߵ�����	
	void copySnake(COORD(*p));											 // �浵����������Ž��ṹ��������							
private:
	int m_sankeLength;													 // �����鳤��
	int m_moveDirection;												 // �н�����
	COORD m_snake[200];													 // ������������  
};

