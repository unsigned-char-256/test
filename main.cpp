#include "controller.h"
#include <stdlib.h>
#include <windows.h>
#include "tools.h"
int m_initmap[50][50];             //����ȫ�ֵ�ͼ
int isEditor = 0;
int main()
{
	/*��ǰ���ع����������������*/
	premise(); 
	/*��ʼ��Ϸ*/
	CController c;
	c.game();
	return 0;
}