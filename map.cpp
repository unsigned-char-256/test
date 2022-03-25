#include <iostream>
#include "map.h"
#include "tools.h"
#include <conio.h>


/**************************************** �༭��ͼ *************************************************/
// 1.����: �༭�Զ����ͼ��Ĭ�ϵ�ͼ�Լ���ȡ�浵ʱ��ִ�б༭����
// 2.����: n�������ʱ��ӡ����Ĭ�ϵĻ���������
//         isEdited �����Ƿ�༭�����༭���Ͳ���ӡĬ�ϵ�15PB,��ӡ��ұ༭�ĵ�ͼ
//         isRead�����Ƿ��ȡ���浵����ȡ���Ļ�����ͼ���Ѿ������ˣ�����Ҫ���б༭��ֱ���˳�
// 3.����ֵ: ��
// 4.����ֵ�� ����ͼ�����ֵΪ2ʱ�������ϰ��1����߿�
// 5.ʵ�ַ�ʽ��
/***************************************************************************************************/
// ���ڱ༭Ĭ�ϵ�ͼ���Զ����ͼ���Լ���ȡ�浵�󲻱༭��ͼ��
int CMap::editorMap(int n, int isEdited, int isRead) // ֵΪ2�����м��ϰ�������ò�ͬ����ɫ��ʾ
{
    int nCount = 0;      // �Զ������ʱ�����
    int x = 2;           // ���������
    int y = 2; 
    int addFlag = 0;     // 0û��ȷ����ӣ����ǰһ���㣬1��ȷ����ӣ������
    int ch = 0;          // �������һ�ΰ�����ֵ
    switch (n)
    {
    /*�༭��Ĭ�ϵ�*/
    case 0:  
        if (isRead == 1)
        {
            return 99;  
        }
        if (isEdited == 1)
        {
            break;
        }
        for (int i = 8; i < 21; i++) // Ĭ��1
        {
            m_initmap[i][12] = 2;
            m_initmap[i][13] = 2;
        }


        for (int j = 28; j < 39; j++)  // Ĭ��P
        {
            m_initmap[j][12] = 2;
        }
        for (int i = 29; i < 32; i++)   
        {
            m_initmap[i][17] = 2;
        }
        for (int i = 12; i < 18; i++)
        {
            m_initmap[28][i] = 2;
            m_initmap[32][i] = 2;
        }


        for (int i = 31; i < 37; i++)       // Ĭ��5
        {
            m_initmap[8][i] = 2;
            m_initmap[13][i] = 2;
            m_initmap[19][i] = 2;
        }
        for (int i = 8; i < 14; i++)
        {
            m_initmap[i][31] = 2;
        }
        for (int i = 13; i < 19; i++)
        {
            m_initmap[i][36] = 2;
        }


        for (int i = 28; i < 39; i++)    // Ĭ��B
        {
            m_initmap[i][31] = 2;
        }
        for (int i = 32; i < 36; i++)    
        {
            m_initmap[28][i] = 2;
            m_initmap[33][i] = 2;
            m_initmap[38][i] = 2;
        }
        m_initmap[29][36] = 2;
        m_initmap[30][37] = 2;
        m_initmap[31][37] = 2;
        m_initmap[32][36] = 2;
        m_initmap[34][36] = 2;
        m_initmap[35][37] = 2;
        m_initmap[36][37] = 2;
        m_initmap[37][36] = 2;
        break;
    /*����ұ༭���ĵ�ͼд������*/
    case 1:  
        for (int i = 2; i < 48; i++)
        {
            for (int j = 2; j < 48; j++)
            {
                if (m_initmap[i][j] == 2)
                {
                    m_initmap[i][j] = 0;
                }
            }
        }
        system("cls");
        printInitmap();
        setColor(7);
        setCursorPosition(54, 6);
        std::cout << "������ƶ���ɫ����ѡ����ӵ�";
        setCursorPosition(54, 7);
        std::cout << "�س���ȷ�����";
        setCursorPosition(54, 8);
        std::cout << "ESC����������";
        
        while (true) // �������ѭ��
        {
            for (int i = 2; i < 48; i++)   // �������飬�����ӹ���ֵ����2�������Ҳ��������
            {
                for (int j = 2; j < 48; j++)
                {
                    if (m_initmap[i][j] == 2)
                    {
                        setColor(2);
                        setCursorPosition(54, 10);
                        std::cout << "����� " << nCount << " ��Ԫ��";
                        setCursorPosition(j,i); // ��ǰ����
                        std::cout << "��";
                    }
                }
            }
            setCursorPosition(x, y); // ��ǰ����
            setColor(6);
            if (addFlag == 0)  std::cout << "��";
            do
            {
                ch = _getch();
            } while (_kbhit() != 0);  // ��������İ�������ֵ
            setCursorPosition(x, y); // ��������¶�λ��ǰһ���㣬��������ո���߷���
            addFlag = 0;
                switch (ch)
                {
                case 27:   // ESC���������ӣ��˳�
                    return 1;
                case 72:
                    std::cout << "  ";
                    if ((y - 1 == 1) || (traversePoint(x, y - 1) == 0))
                    {
                        break;
                    }
                    y -= 1;
                    break;
                case 80:
                    std::cout << "  ";
                    if (y + 1 == 48 || (traversePoint(x, y + 1) == 0))
                    {
                        break;
                    }
                    y += 1;
                    break;
                case 75:
                    std::cout << "  ";
                    if (x - 1 == 1 || (traversePoint(x - 1, y) == 0))
                    {
                        break;
                    }
                    x -= 1;
                    break;
                case 77:
                    std::cout << "  ";
                    if (x + 1 == 48 || (traversePoint(x + 1, y) == 0))
                    {
                        break;
                    }
                    x += 1;
                    break;
                case 13:
                    addFlag = 1;
                    if(traversePoint(x,y)) nCount++;
                    m_initmap[y][x] = 2;
                    break;
                default:
                    break;
                }
        }
        break;
    default:
        break;
    }
}


/**************************************** ��ӡ��ͼ *************************************************/
// 1.����: ����Ļ�д�ӡ��ͼ
// 2.����: ��
// 3.����ֵ: ��
// 4.����ֵ�� 
// 5.ʵ�ַ�ʽ��������ͼ���飬��1����2�ʹ�ӡ�����Ұ��ղ�ͬ����ɫ�����ֱ߿���ϰ���
/***************************************************************************************************/
void CMap::printInitmap()//���Ƶ�ͼ
{
    int pNum = 0;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (m_initmap[i][j] == 1)
            {
                setColor(3);
                setCursorPosition(j, i);
                std::cout << "��";
                pNum++;
            }
            else if (m_initmap[i][j] == 2)
            {
                setColor(6);
                setCursorPosition(j, i);
                std::cout << "��";
                pNum++;
            }
        }
    }
}


/**************************************** ����ϰ� *************************************************/
// 1.����: �������Զ����ͼ�У��жϵ�ǰ�н������Ƿ��Ѿ���ӹ�
// 2.����: ��
// 3.����ֵ: ��
// 4.����ֵ�� 
// 5.ʵ�ַ�ʽ��0�����ظ���������ǰ����1�����ظ�������ǰ��
/***************************************************************************************************/
int CMap::traversePoint(int x, int y)
{
    for (int i = 2; i < 48; i++)
    {
        for (int j = 2; j < 50; j++)
        {
            if (m_initmap[i][j] == 2)
            {
                if (x == j && y == i)
                {
                    return 0;  //��ʱ�ظ��ˣ����ܽ����ƶ�����
                }
            }
        }
    }
}