
#include <windows.h>
using namespace std;
class CFood
{
public:
	CFood() : m_foodFlag(1)													// �޲ι���
	{
		m_foodPosition.X = 27;
		m_foodPosition.Y = 25;
	}                                                       
	int getFoodFlag();														// ��ȡʳ�ﱻ�Ա��
	COORD* getFoodPsition();												// ��ȡʳ��ָ��
	void setFoodFlag(int foodFlag);											// ����ʳ�ﱻ�Ա��
	void setFoodPosition(int x, int y);										// ����ʳ���λ��
	void writeFood(int col, int row, char* content, int y = 0);             // ��ӡʳ��
	void  drawFood();														// �����µ�ʳ��
	void  drawOldFood();													// ������Ϸ����ʳ��
private:
	int m_foodFlag;															// ʳ�ﱻ�Ա��
	COORD m_foodPosition;													// ʳ��λ��
};
