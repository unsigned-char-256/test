#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define PATHMUSSTART "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\GameStart.wav"
#define PATHMUSEAT "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\�Ե�ʳ��.wav"
#define PATHCRUSH "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\ײǽ.wav"
#define PATHSELECT "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\����ģʽѡ��.wav"
#define PATHSELECTED "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\ѡ��.wav"
#define PATHFILE "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\file\\temp.txt"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winMM.Lib") 

#include "controller.h"
#include "tools.h"
#include "startInterface.h" 
extern int isEditor;                                          // �Ƿ�༭���ı�ǣ��ݴ˴�ӡ��ͬ�ĵ�ͼ


/**************************************** ��ʼ���� *************************************************/
// 1.����: ����������ʾ��ӭ����
// 2.����: ��
// 3.����ֵ: ��
// 4.����ֵ�� setWindowSize();              �����෽�����ô��ڴ�С
//            setCursorPosition(22, 36);    �����෽�����ÿ���̨���λ��
//            setBackColor();               �����෽����������ǰ����ɫ������ɫ
// 5.ʵ�ַ�ʽ����CStartInterface����޲ι����д�ӡͼ�Σ��ڴ˺����д���һ�������������delete
/***************************************************************************************************/
void CController::showStart() 
{
    system("color 72");
    PlaySound(PATHMUSSTART, NULL, SND_FILENAME | SND_ASYNC);
	setWindowSize(70, 50);                                     
	CStartInterface* start = new CStartInterface();
	delete start;                                             
    setCursorPosition(22, 36); 
    setBackColor();
    std::cout << "press any key to start......\n";
    setCursorPosition(22, 37);
    system("pause");
}


/**************************************** �޸ķ��� *************************************************/
// 1.����: �޸���ʾ�ķ���
// 2.����: ��
// 3.����ֵ: ��
// 4.����ֵ��setColor(10);   �����෽������������ֵ���ɫ����Ϊ��ͬ�׶εķ�����ʾ����ɫ��ͬ
// 5.ʵ�ַ�ʽ������Ϸ���߳Ե�ʳ����ã����ݵ�ǰ���ٶȵȼ���ԭ���ķ��������Ӳ���������������Ϊ6λ��
//             �����յ�ǰ������λ�����ڷ���ǰ���ӡ�ո�ʼ�ձ����Ҷ��룬Ȼ�����������
/***************************************************************************************************/
void CController::updateScore()
{
    switch (m_speed)
    {
    case 150:
        m_score += 7;
        break;
    case 100:
        m_score += 13;
        break;
    case 70:
        m_score += 20;
        break;
    case 50:
        m_score += 50;
        break;
    default:
        break;
    }
    setCursorPosition(60, 8);

    if (m_score < 100)
    {
        setColor(15);
    }
    else if (m_score > 99 && m_score < 300)
    {
        setColor(6);
    }
    else if (m_score > 299 && m_score < 500)
    {
        setColor(10);
    }
    else
    {
        setColor(4);
    }

    int bit = 0;
    int tmp = m_score;
    while (tmp != 0)
    {
        ++bit;
        tmp /= 10;
    }
    for (int i = 0; i < (6 - bit); ++i)
    {
        std::cout << " ";
    }
    std::cout << m_score;
}


/**************************************** �޸��ٶ� *************************************************/
// 1.����: �����޸ĺ�ķ����޸�˯���ٶ�
// 2.����: ��
// 3.����ֵ: ��
// 4.����ֵ����
// 5.ʵ�ַ�ʽ�������޸ĺ�ķ����޸�˯���ٶȣ���ʵ�ֲ�ͬ���ٶȣ��ٵ����޸���ʾ�Ѷȵķ��� showSpeed();
//             ȥ�޸���ʾ���Ѷ�
/***************************************************************************************************/
void CController::updateDifficulty()
{
    setCursorPosition(36, 5);
    if (m_score < 100)
    {
        m_speed = 150;
    }
    else if (m_score > 99 && m_score < 300)
    {
        m_speed = 100;
    }
    else if (m_score > 299 && m_score < 500)
    {
        m_speed = 70;
    }
    else
    {
        m_speed = 50;
    }
    setCursorPosition(59, 6);
    showSpeed();
}


/**************************************** �޸��Ѷ� *************************************************/
// 1.����: �޸���ʾ���Ѷ�
// 2.����: ��
// 3.����ֵ: ��
// 4.����ֵ��m_speed Ϊ˯���ٶȣ���CController�ĳ�Ա����
// 5.ʵ�ַ�ʽ������ʵʱ�޸ĵ��ٶ�ȥƥ�䲻ͬ���Ѷȣ��������ʾ
/***************************************************************************************************/
void CController::showSpeed()
{
    switch (m_speed)
    {
    case 150:
        std::cout << "��ģʽ";
        break;
    case 100:
        std::cout << "��ͨģʽ";
        break;
    case 70:
        std::cout << "����ģʽ";
        break;
    case 50:
        std::cout << "����ģʽ";
        break;
    default:
        break;
    }
}


/**************************************** ѡ����� *************************************************/
// 1.����: ��ʾ��Ϸѡ�����
// 2.����: ��
// 3.����ֵ: ��
// 4.����ֵ�����·����ѡ��Ľ��;���������Ĵ�����
// 5.ʵ�ַ�ʽ���κ�������Ϊ�������� /*��ʾѡ�����ģ��*/ �� /*���·����ѡ��ģ��*/ ������ֱ�������
//      /*��ʾѡ�����ģ��*/:������ӭ�����snake����ͼ����Ȼ�Ǵ��������Ȼ��delete��Ȼ�󽫹�궨λ��
//                          ��ͬ��λ�ö������ѡ�Ȼ�����ѡ�������
//      /*���·����ѡ��ģ��*/: �˴�˼��������
//                         1.һ������ѡ�������ԭ��λ�õ����ݲ���ӡ��û�б�����ɫ��ѡ�����֣�
//                              Ȼ���ٵ�ǰλ�����ԭ��û�б��������֣���ӡ���б��������֡�
//                         2.������CController��ĳ�Ա����keyֵ����������ÿһ��ѡ���������
//                              ��ʱ��++����--�������˳�����ʱ��ʲôֵ�ͽ�����Ӧ�Ĳ���
/***************************************************************************************************/
void CController::showSelect()
{
    /*��ʾѡ�����ģ��*/
    system("cls");
    system("color 3");
    CStartInterface* start = new CStartInterface();
    delete start;
    setCursorPosition(22, 30);
    std::cout << "��ѡ����Ϸ�Ѷȣ�";
    setCursorPosition(22, 31);
    std::cout << "(���¼�ѡ��,�س�ȷ��)";
    setCursorPosition(43, 31);
    std::cout << "��ʼ��Ϸ";
    setCursorPosition(43, 33);
    setColor(3);
    std::cout << "�༭��ͼ";
    setCursorPosition(43, 35);
    std::cout << "��ȡ�浵";

    /*���·����ѡ��ģ��*/
    int ch;                         // ����ֵ
    m_key = 1;                      // ѡ�����ʼѡ���һ��
    bool flag = false;              // �Ƿ����Enter����ǣ���ʼ��Ϊ��
    while ((ch = _getch()))
    {

        switch (ch)                 // ��������
        {
        case 72:                    // UP�Ϸ����
            PlaySound(PATHSELECT, NULL, SND_FILENAME | SND_ASYNC);
            if (m_key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
            {
                switch (m_key)
                {
                case 2:
                    setCursorPosition(43, 31);//����ѡ�������ñ���ɫ
                    setBackColor();
                    std::cout << "��ʼ��Ϸ";

                    setCursorPosition(43, 33);//����ѡ����ȡ������ɫ
                    setColor(3);
                    std::cout << "�༭��ͼ";

                    --m_key;
                    break;
                case 3:
                    setCursorPosition(43, 33);
                    setBackColor();
                    std::cout << "�༭��ͼ";

                    setCursorPosition(43, 35);
                    setColor(3);
                    std::cout << "��ȡ�浵";

                    --m_key;
                    break;
                }
            }
            break;

        case 80:                    // DOWN�·����
            PlaySound(PATHSELECT, NULL, SND_FILENAME | SND_ASYNC);
            if (m_key < 3)
            {
                switch (m_key)
                {
                case 1:
                    setCursorPosition(43, 33);
                    setBackColor();
                    std::cout << "�༭��ͼ";
                    setCursorPosition(43, 31);
                    setColor(3);  
                    std::cout << "��ʼ��Ϸ";

                    ++m_key;
                    break;
                case 2:
                    setCursorPosition(43, 35);
                    setBackColor();
                    std::cout << "��ȡ�浵";
                    setCursorPosition(43, 33);
                    setColor(3);
                    std::cout << "�༭��ͼ";

                    ++m_key;
                    break;
                }
            }
            break;

        case 13:                    // Enter�س���
            PlaySound(PATHSELECTED, NULL, SND_FILENAME | SND_ASYNC);
            flag = true;
            break;
        default:                    // ��Ч����
            break; 
        }
        if (flag) break;            // ����Enter�س���ȷ�ϣ��˳��������ѭ��
    }
    Sleep(1500);
}


/************************************** ������Ϸ���� ***********************************************/
// 1.����: ��ӡ��ͬ�ĵ�ͼ�Լ��ұ���Ϸ��Ϣ�͹�����
// 2.����: CMap* init_map ��ͼ���ָ�룬ȫ�ֹ���һ�ŵ�ͼ
// 3.����ֵ: ��
// 4.����ֵ��editorMap(0, isEditor, m_isRead);  CMap�෽�����༭��ͼ����ϰ����߿�Ĭ�Ͼ���
//           printInitmap();                    CMap�෽������ӡ��ͼ��ı߿�� 
// 5.ʵ�ַ�ʽ����Ҫ�ǵ��õ�ͼ�ຯ��ʵ�֣�������ȷ�Ĳ���
/***************************************************************************************************/
void CController::drawMap(CMap* init_map)//������Ϸ�����Լ���Ϸ��Ϣ
{
    /*���Ƶ�ͼ*/
    system("cls");
    setColor(3);
    if (m_key == 1)
    {
        init_map->editorMap(0, isEditor, m_isRead); 
    }
    m_isRead == 0;
    init_map->printInitmap();

    /*����ѡ�����Ϣ��*/
    setColor(3);
    setCursorPosition(53, 1);
    std::cout << "����������������������������������������������";
    setCursorPosition(53, 3);
    std::cout << "|  ��������������������������������   |";
    setCursorPosition(53, 2);
    std::cout << "|                     |";
    setCursorPosition(53, 5);
    std::cout << "|  ��������������������������������   |";
    setCursorPosition(53, 4);
    std::cout << "|                     |";
    setCursorPosition(53, 6);
    std::cout << "|                     |";
    setCursorPosition(53, 7);
    std::cout << "|                     |";
    setCursorPosition(53, 8);
    std::cout << "|                     |";
    setCursorPosition(53, 9);
    std::cout << "����������������������������������������������";
    setColor(6);
    setCursorPosition(56, 2);
    std::cout << "Greedy Snake";
    setColor(14);
    setCursorPosition(56, 4);
    std::cout << "�÷���Ϣ��";
    setCursorPosition(55, 6);
    std::cout << "�Ѷȣ�";
    setCursorPosition(58, 6);
    setCursorPosition(55, 8);
    setColor(14);
    std::cout << "�÷֣�";
    setColor(13);
    setCursorPosition(57, 42);
    std::cout << "����˵��";
    setCursorPosition(50, 43);
    std::cout << "��������������������������������������������������������������������������";
    setCursorPosition(51, 46);
    std::cout << " ������ƶ�";
    setCursorPosition(62, 46);
    std::cout << " ESC����ͣ";
}


/**************************************** ѡ��ִ�� *************************************************/
// 1.����: ����ѡ���ִֵ����Ӧ�Ĳ���
// 2.����: ��
// 3.����ֵ:  
//            CSnake* snake     ����ָ��,����һ����
//            CFood* food       ʳ����ָ��,����һ��ʳ��
//            CMap* init_map    ��ͼ��ָ��,����һ�ŵ�ͼ
// 4.����ֵ�� fileReading(snake, food); ��ȡ�浵����
// 5.ʵ�ַ�ʽ��������һ����showSelect���������õ�m_key��ֵ��������Ӧ�Ĳ���
//              1��ֱ�ӽ���Ĭ�ϵ�ͼ�ϰ�
//              2�Ǳ༭��ͼ����һ��������CMap�ຯ��editorMap();����1
//              3�ǽ��ж�ȡ�浵���������ñ���fileReading()����
/***************************************************************************************************/
int CController::beforeGame(CSnake* snake, CFood* food, CMap* init_map){
    switch (m_key)
    {
    case 1:
        break;
    case 2:
        isEditor = init_map->editorMap(1, 0, 0);
        return isEditor;
    case 3:
        return fileReading(snake, food);
        system("pause");
    default:
        break;
    }
}


/**************************************** ��Ϸ���� *************************************************/
// 1.����: ��ͷײ����ͼ�߿�����ϰ��Լ����������Ϸ����������һ����ѡ��
// 2.����: ��
// 3.����ֵ: ����1���¿�ʼ�� ����2�˳���Ϸ
// 4.����ֵ�� ��
// 5.ʵ�ַ�ʽ���������ù������꣬����
/***************************************************************************************************/
int CController::gameEnd()
{
    /*������Ϸ��������*/
    Sleep(500);
    setColor(2);
    setCursorPosition(50, 15);
    std::cout << "��������������������������������������������������������������������������";
    Sleep(30);
    setCursorPosition(49, 16);
    std::cout << " ��           Game Over !!!            ��";
    Sleep(30);
    setCursorPosition(49, 17);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 18);
    std::cout << " ��          ���ź��������            ��";
    Sleep(30);
    setCursorPosition(49, 19);
    std::cout << " ��          ����һ�ְ�ͬ־��          ��";
    Sleep(30);
    setCursorPosition(49, 20);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 21);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 22);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 23);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 24);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 25);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 26);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(50, 27);
    std::cout << "��������������������������������������������������������������������������";
    Sleep(100);
    setCursorPosition(52, 25);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "��ð��ð�";
    setCursorPosition(59, 25);
    setColor(11);
    std::cout << "  �������˰�";

    /*ѡ�񲿷�*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))
    {
        switch (ch)
        {
        case 75://LEFT
            if (tmp_key > 1)
            {
                setCursorPosition(52, 25);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "��ð��ð�";
                setCursorPosition(59, 25);
                setColor(11);
                std::cout << "  �������˰�";
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                setCursorPosition(59, 25);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "�ﻹ�����˰�";
                setCursorPosition(52, 25);
                setColor(11);
                std::cout <<  "  �ð��ð�";
                ++tmp_key;
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        if (flag) {
            break;
        }
    }
    switch (tmp_key)
    {
    case 1:
        return 1;//���¿�ʼ
    case 2:
        return 2;//�˳���Ϸ
    }
}


/**************************************** ��Ϸ��ͣ *************************************************/
// 1.����: ��ʾ��Ϸ��ͣ��Ϣ����ȡ��һ���Ĳ���
// 2.����: ��
// 3.����ֵ: ����1ȥ�浵������2�˳���Ϸ
// 4.����ֵ����ESC������Ϸ
// 5.ʵ�ַ�ʽ��
/***************************************************************************************************/
int CController::gamePause()
{
    /*������Ϸ��ͣ����*/
    Sleep(500);
    setColor(2);
    setCursorPosition(50, 15);
    std::cout << "��������������������������������������������������������������������������";
    Sleep(30);
    setCursorPosition(49, 16);
    std::cout << " ��          What happened???          ��";
    Sleep(30);
    setCursorPosition(49, 17);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 18);
    std::cout << " ��          ������Ϸ�밴ESC           ��";
    Sleep(30);
    setCursorPosition(49, 19);
    std::cout << " ��          �浵���˳���ѡ��          ��";
    Sleep(30);
    setCursorPosition(49, 20);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 21);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 22);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 23);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 24);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 25);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(49, 26);
    std::cout << " ��                                    ��";
    Sleep(30);
    setCursorPosition(50, 27);
    std::cout << "��������������������������������������������������������������������������";
    Sleep(100);
    setCursorPosition(52, 25);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "��浵�ļ�";
    setCursorPosition(59, 25);
    setColor(11);
    std::cout << "  ���ǲ�����";

    /*ѡ�񲿷�*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))
    {
        switch (ch)
        {
        case 27:// ESC
            setCursorPosition(50, 27);
            std::cout << "                                        ";
            setCursorPosition(50, 25);
            std::cout << "                                    ";
            for (int i = 15; i < 27; i++)
            {
                setCursorPosition(49, i);
                std::cout << "                                        ";
            }
            return 0;
        case 75://LEFT
            if (tmp_key > 1)
            {
                setCursorPosition(52, 25);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "��浵�ļ�";
                setCursorPosition(59, 25);
                setColor(11);
                std::cout << "  ���ǲ�����";
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                setCursorPosition(59, 25);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "�ﻹ�ǲ�����";
                setCursorPosition(52, 25);
                setColor(11);
                std::cout << "  �浵�ļ�";
                ++tmp_key;
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        if (flag) {
            break;
        }
    }
    switch (tmp_key)
    {
    case 1:
        return 1; //�浵
        break;
    case 2:
        return 2;//�˳���Ϸ
    default:
        break;
    }
}


/**************************************** �浵���� *************************************************/
// 1.����: ������Ϸ״̬�������ļ����´ο��Զ�ȡ������Ϸ
// 2.����: CSnake* snake ��
//         CFood* food   ʳ��
// 3.����ֵ: ����2���浵���ֱ���˳���Ϸ
// 4.����ֵ��GAMEINFO�������ж���Ľṹ�壬������ʱ�����Ϸ��Ϣ���ڶ�ȡ�ļ�������������
// 5.ʵ�ַ�ʽ������Ϊ��������
//    /*��������Ϸ��Ϣ��ŵ��ṹ����*/:�����ṹ�����������Ϸ��Ϣ����һ�ݵ�����    
//    /*���ṹ���е���Ϣ�����ļ���*/:���ļ������ṹ���е���Ϣ���룬ʹ�á�ab+���ķ�ʽ��
//                       ���ļ�β��д�룬��Ϊ���ܻ��ж�����Ϸ��Ϣ,���ر��ļ���new�ռ�
/***************************************************************************************************/
int CController::keepFile(CSnake* snake, CFood* food)
{
    /*��������Ϸ��Ϣ��ŵ��ṹ����*/
    GAMEINFO* gameInfo = new GAMEINFO[1];
    setCursorPosition(50, 28);
    std::cout << "������浵������ƣ�";
    std::cin >> gameInfo->name;
    memcpy(gameInfo->mapCopy, m_initmap, sizeof(gameInfo->mapCopy));
    gameInfo->foodPosition.X = food->getFoodPsition()->X; 
    gameInfo->foodPosition.Y = food->getFoodPsition()->Y;
    gameInfo->score = m_score;   
    gameInfo->moveSpeed = m_speed;
    gameInfo->snakeLength = snake->getSankeLength(); 
    gameInfo->snakeDirection = snake->getMoveDirection();
    snake->copySnake(gameInfo->snake);

    /*���ṹ���е���Ϣ�����ļ���*/
    FILE* pfile = NULL;
    int err = fopen_s(&pfile, PATHFILE, "ab+");
    int result = fwrite(gameInfo, sizeof(GAMEINFO), 1, pfile);
    setCursorPosition(50, 32);
    setColor(4);
    if (pfile != NULL || err == 0)
    {
        printf("�浵�ɹ���");
        setColor(11);
        std::cout << "3����˳���Ϸ......";
        Sleep(3000);
    }
    else {
        setColor(4);
        printf("�浵ʧ�ܣ�");
        setColor(11);
        std::cout << "3����˳���Ϸ......";
        Sleep(3000);
    }
    fclose(pfile);
    delete[] gameInfo;
    return 2;
}


/**************************************** ��ȡ�浵 *************************************************/
// 1.����: ��ȡ�ļ��б������Ϸ��Ϣ�����ص�������Ϸ��
// 2.����: CSnake* snake ��
//         CFood* food   ʳ��
// 3.����ֵ: ����ֵ1����beforeGame�з���һ��1���ڴ�ѭ�����ٴο�ʼ��Ϸ��ʹ�ö�ȡ������Ϣ
// 4.����ֵ��m_isRead������Ϊ1��������editorMap()�����в���ӡĬ�ϵ�ͼ�����е�ͼ�༭��ʹ�ñ��ֵ�ͼ
//           int i; �����±�
//           int nCol; ��ӡ��Ϣʱ������
//           int n; n�������ѡ��Ĵ浵����ţ�Ҳ���ǽṹ��������±꣬�����Ѿ�����- 1 ����
// 5.ʵ�ַ�ʽ��������ʵ��
//  /*�����ṹ��������ڽ����ļ��ڵ���Ϣ*/������һ���ṹ�����������ӡ��ؽ�����Ϣ
//  /*�����ѡ�����ŵĴ浵������Ϸ��*/����һ���ļ���ѭ����ȡ�ļ�������Щ��Ϣ���뵽�ṹ�������У�
//       ͬʱ����Щ��Ϣ��ӡ�����������ѡ��Ȼ�������ѡ�����Ž���Ϸ��Ϣ���ص�������Ϸ��ͬʱ
//       �ر��ļ���delete�ṹ������ռ�,��󷵻����¿�ʼ��Ϸ��ֵ1
/***************************************************************************************************/
int CController::fileReading(CSnake* snake, CFood* food)
{
    m_isRead = 1; 
    /*�����ṹ��������ڽ����ļ��ڵ���Ϣ*/
    system("cls");
    GAMEINFO* temp = new GAMEINFO[30];
    int i = 0;
    int nCol = 8; 
    FILE* pfile = NULL;
    fopen_s(&pfile, PATHFILE, "rb+");
    setCursorPosition(21, nCol);
    setColor(12);
    std::cout << "���     " << "    �浵������      " << "    ��ǰ����";
    setColor(10);
    while (1 == fread(&temp[i], sizeof(GAMEINFO), 1, pfile))
    {
        setCursorPosition(21, nCol + 2);
        printf("%d.           %s", i + 1, temp[i].name);
        setCursorPosition(38, nCol + 2);
        printf("%d", temp[i].score);
        i++;
        nCol++;
    }

    int n = -1;
    while (true)
    {
        setCursorPosition(21, nCol + 4);
        setColor(11);
        std::cout << "��������Ҫѡ��Ĵ浵����ţ�";
        std::cin >> n;
        if (n > -1 && n < i + 1)
        {
            n -= 1;
            break;
        }
        setCursorPosition(21, nCol + 4);
        setColor(4);
        std::cout << "û�д˴浵��ţ����������룡           ";
        Sleep(3000);
        std::cout << "                                ";
    }

    /*�����ѡ�����ŵĴ浵������Ϸ��*/
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (temp[n].mapCopy[i][j] == 2)
            {
                m_initmap[i][j] = 2;
            }
        }
    }
    food->setFoodPosition(temp[n].foodPosition.X, temp[n].foodPosition.Y);
    m_score = temp[n].score;
    m_speed = temp[n].moveSpeed;
    snake->resetSnakeLength(temp[n].snakeLength);
    snake->setMoveDirection(temp[n].snakeDirection);
    snake->resetSnake(temp[n].snake);
    /*��ENTER��ʼ��Ϸ*/
    setColor(4);
    setCursorPosition(20, 1);
    std::cout << "������������������������������������������������������������������������������������������";
    Sleep(30);
    setCursorPosition(20, 2);
    printf(" ��  �浵�����Ϊ %d ���밴ENTER��ʼ��Ϸ    ��", n + 1);   
    setCursorPosition(20, 3);
    std::cout << "������������������������������������������������������������������������������������������";
    while (true)
    {
        int cinkey = _getch();
        if (cinkey == 13)
        {
            break;
        }
        continue;
    }
    fclose(pfile);
    delete[] temp;
    return 1;
}


/**************************************** �ȴ����� *************************************************/
// 1.����: ��ϷСѭ���м�����������
// 2.����:  
//          moveDirection�������д������н������
//          CSnake* snake ��
//          CFood* food   ʳ��
// 3.����ֵ: ����2���˳���Ϸ������1���¿�ʼ��Ϸ�������Ķ��Ƿ����������Ҵ���ķ���
// 4.����ֵ����
// 5.ʵ�ַ�ʽ����Ϊ�������֣�ʹ��_kbhit()�����������ļ��������¼�
//     ��һ�����Ǽ�����ESC��ͣʱ������gamePause()����������ѡ���ִֵ�м�����Ϸ���浵���˳���Ϸ����
//     �ڶ������Ǽ������������ң�ͬ������෴�������κζ���
/***************************************************************************************************/
int CController::waitKey(int moveDirection, CSnake* snake, CFood* food)
{
    /*���������������¼�*/
    if (_kbhit())
    {
        int ch = 0;
        do
        {
            ch = _getch();
        } while (_kbhit() != 0);
        if (ch == 27) 
        {
            switch (gamePause())
            {
            case 0: 
                break;
            case 1:
                return keepFile(snake, food);
            case 2:
                return 2;
            default:
                break;
            }
        }

        /*�жϰ����Ƿ������������ĸ�����������ǻ��߷��������Ч*/
        if (ch == 72 || ch == 75 || ch == 77 || ch == 80)
        {
            if (ch == 72 && moveDirection == 80)
            {
                return moveDirection;
            }
            else if (ch == 80 && moveDirection == 72)
            {
                return moveDirection;
            }
            else if (ch == 75 && moveDirection == 77)
            {
                return moveDirection;
            }
            else if (ch == 77 && moveDirection == 75)
            {
                return moveDirection;
            }
            return ch;
        }
    }
    return moveDirection;
}


/**************************************** ��ϷСѭ�� **********************************************/
// 1.����: ��Ϸ���Ļ��ڣ�ʵ���ߵ��ƶ�������ı仯��ʳ��������֣���ײǽ�ͳԵ�ʳ��ٶȵı仯
// 2.����:  CSnake* snake ��
//          CFood* food   ʳ��
// 3.����ֵ: ����ѭ�����ص�ֵ��1�����¿�ʼ��Ϸ��2���˳���Ϸ
// 4.����ֵ��
// 5.ʵ�ַ�ʽ��
//     1.�ߵ��ƶ��������ߵ����꽫ԭ�е�λ����գ������н������������������꣬�Ƚ�������ͷ�����λ�õ�����
//        ���ó�ǰһ����������꣬�������н�������ͷ�ĺ����������������£�����ӡ���ߵ�λ��
//     2.����仯�����ݼ��̼������ķ���ֵ������ͷ��λ������ı䣬���������ÿһ��������ת����Ϊ
//     3.ʳ��������֣�ʳ������������ж���ʽ��ÿһ��ʳ����ֶ��Ὣ��һ�γ��ֵ�λ����գ�
//        һ������һ�����foodFlag����ʳ�ﱻ�Ե����Ƿ����ı䣬�´�ѭ���жϱ�������µ�ʳ��
//        ��������һ��ʱ����foodFlagConut�����ʳ����ֵ�λ�ò����룬һ��ʱ�����Ҳ��������һ��ʳ��
//     4.��ײǽ���߳Ե�ʳ��ж���ͷ����Ϊ�͸��ϰ����Լ���������λ�������Ƿ���ͬ
//     5.�ٶȵı仯�����ݷ����ı�˯���ٶ�m_speed,ʵ���ٶȵı仯
/***************************************************************************************************/
int CController::playGame(CSnake* snake, CFood* food) 
{
    int foodFlag = food->getFoodFlag();
    int foodFlagConut = 0; 
    food->drawOldFood();
    /*����ѭ��*/
    while (true)   
    {  
        /*ʳ���������*/
        if (foodFlag == 0 || foodFlagConut == 1000)
        {
            foodFlagConut = 0;
            food->drawFood();
        }
        foodFlag++;
        /*��ײǽ��ײ�Լ�*/
        if (snake->isCollision(snake->getSnake()[0].X, snake->getSnake()[0].Y))
        {
            PlaySound(PATHCRUSH, NULL, SND_FILENAME | SND_ASYNC);
            m_speed = 150;
            m_score = 0;
            return gameEnd();
        }
        /*����*/
        snake->writeSnake(0);
        /*��������*/
        snake->updateCoordinates();
        /*�߳�ʳ��*/
        for (int i = 0; i < snake->getSankeLength() ; i++)
        {
            if (snake->getSnake()[i].X == food->getFoodPsition()->X && snake->getSnake()[i].Y == food->getFoodPsition()->Y)
            {
                PlaySound(PATHMUSEAT, NULL, SND_FILENAME | SND_ASYNC);
                foodFlag = 0;
                updateScore();
                updateDifficulty();
                snake->setSnakeLength(1);
                break;
            }
        }
        /*����*/
        snake->writeSnake(1);
        /*��������*/
        int result = waitKey(snake->getMoveDirection(), snake, food);
            if (result == 2)
            {
                return 2;
            }
            else if (result == 1)
            {
                return 1;
            }
        snake->setMoveDirection(result);
        foodFlagConut += 10;
        Sleep(m_speed);
    }
    m_speed = 150;
    return 2;
}


/*************************************** ��Ϸ��ѭ�� *************************************************/
// 1.����:  ʵ������Ϸ�����¿�ʼ����
// 2.����:   ��
// 3.����ֵ: ��
// 4.����ֵ��
// 5.ʵ�ַ�ʽ�������������ʾ��ʼ���棬����������ȫ�ֹ��õĶ���Ȼ�����ѭ��
//             ѭ��˳��
// showSelect();//ѡ����� ����>  drawMap(init_map);//������Ϸ���桪��>playGame(snake, food);//������Ϸѭ��
// �����˳�֮ǰdelete��������ռ�                
/***************************************************************************************************/
void CController::game()
{
    showStart();
    CSnake* snake = new CSnake(); 
    CFood* food = new CFood();
    CMap* init_map = new CMap();
    /*��Ϸѭ��*/
    while (true)
    {
        /*ѡ�����*/
        showSelect();
        /*ִ��ѡ��*/
        if (1 == beforeGame(snake, food, init_map) )
        {
            continue;
        }
        /*����ͼ*/
        drawMap(init_map);
        /*��ϷСѭ��*/
        int tmp = playGame(snake, food);
        if (tmp == 1) 
        {
            system("cls");
            continue;
        }
        else if (tmp == 2)
        {
            break;
        }
        else
        {
            break;
        }
    }
    delete snake;
    snake = NULL;
    delete food;
    food = NULL;
    delete init_map;
    init_map = NULL;
}
