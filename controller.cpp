#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define PATHMUSSTART "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\GameStart.wav"
#define PATHMUSEAT "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\吃到食物.wav"
#define PATHCRUSH "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\撞墙.wav"
#define PATHSELECT "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\上下模式选择.wav"
#define PATHSELECTED "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\voice\\选定.wav"
#define PATHFILE "E:\\WorkSpace\\VS2019Space\\CLanguage\\GreedySnake\\file\\temp.txt"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winMM.Lib") 

#include "controller.h"
#include "tools.h"
#include "startInterface.h" 
extern int isEditor;                                          // 是否编辑过的标记，据此打印不同的地图


/**************************************** 开始界面 *************************************************/
// 1.功能: 进入程序后显示欢迎界面
// 2.参数: 无
// 3.返回值: 无
// 4.其他值： setWindowSize();              工具类方法设置窗口大小
//            setCursorPosition(22, 36);    工具类方法设置控制台光标位置
//            setBackColor();               工具类方法设置文字前景红色背景白色
// 5.实现方式：在CStartInterface类的无参构造中打印图形，在此函数中创建一个这个类对象，随后delete
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


/**************************************** 修改分数 *************************************************/
// 1.功能: 修改显示的分数
// 2.参数: 无
// 3.返回值: 无
// 4.其他值：setColor(10);   工具类方法设置输出文字的颜色，因为不同阶段的分数显示的颜色不同
// 5.实现方式：在游戏中蛇吃到食物调用，根据当前的速度等级给原来的分数做增加操作，最大分数设置为6位，
//             并按照当前分数的位数，在分数前面打印空格，始终保持右对齐，然后再输出分数
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


/**************************************** 修改速度 *************************************************/
// 1.功能: 根据修改后的分数修改睡眠速度
// 2.参数: 无
// 3.返回值: 无
// 4.其他值：无
// 5.实现方式：根据修改后的分数修改睡眠速度，以实现不同的速度，再调用修改显示难度的方法 showSpeed();
//             去修改显示的难度
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


/**************************************** 修改难度 *************************************************/
// 1.功能: 修改显示的难度
// 2.参数: 无
// 3.返回值: 无
// 4.其他值：m_speed 为睡眠速度，是CController的成员变量
// 5.实现方式：根据实时修改的速度去匹配不同的难度，在输出显示
/***************************************************************************************************/
void CController::showSpeed()
{
    switch (m_speed)
    {
    case 150:
        std::cout << "简单模式";
        break;
    case 100:
        std::cout << "普通模式";
        break;
    case 70:
        std::cout << "困难模式";
        break;
    case 50:
        std::cout << "炼狱模式";
        break;
    default:
        break;
    }
}


/**************************************** 选项界面 *************************************************/
// 1.功能: 显示游戏选项界面
// 2.参数: 无
// 3.返回值: 无
// 4.其他值：上下方向键选择的解释具体在下面的代码中
// 5.实现方式：次函数共分为两个部分 /*显示选项界面模块*/ 和 /*上下方向键选择模块*/ ，下面分别作解释
//      /*显示选项界面模块*/:保留欢迎界面的snake大字图，依然是创建类对象然后delete，然后将光标定位到
//                          不同的位置对齐各个选项，然后输出选项的文字
//      /*上下方向键选择模块*/: 此处思想有两个
//                         1.一是上下选择是清除原来位置的内容并打印上没有背景颜色的选项文字，
//                              然后再当前位置清除原来没有北京的文字，打印上有背景的文字。
//                         2.二是用CController类的成员变量key值，用来代表每一个选择项，上下移
//                              动时做++或者--操作，退出函数时是什么值就进行相应的操作
/***************************************************************************************************/
void CController::showSelect()
{
    /*显示选项界面模块*/
    system("cls");
    system("color 3");
    CStartInterface* start = new CStartInterface();
    delete start;
    setCursorPosition(22, 30);
    std::cout << "请选择游戏难度：";
    setCursorPosition(22, 31);
    std::cout << "(上下键选择,回车确认)";
    setCursorPosition(43, 31);
    std::cout << "开始游戏";
    setCursorPosition(43, 33);
    setColor(3);
    std::cout << "编辑地图";
    setCursorPosition(43, 35);
    std::cout << "读取存档";

    /*上下方向键选择模块*/
    int ch;                         // 键入值
    m_key = 1;                      // 选中项，初始选择第一个
    bool flag = false;              // 是否键入Enter键标记，初始置为否
    while ((ch = _getch()))
    {

        switch (ch)                 // 检测输入键
        {
        case 72:                    // UP上方向键
            PlaySound(PATHSELECT, NULL, SND_FILENAME | SND_ASYNC);
            if (m_key > 1)//当此时选中项为第一项时，UP上方向键无效
            {
                switch (m_key)
                {
                case 2:
                    setCursorPosition(43, 31);//给待选中项设置背景色
                    setBackColor();
                    std::cout << "开始游戏";

                    setCursorPosition(43, 33);//将已选中项取消背景色
                    setColor(3);
                    std::cout << "编辑地图";

                    --m_key;
                    break;
                case 3:
                    setCursorPosition(43, 33);
                    setBackColor();
                    std::cout << "编辑地图";

                    setCursorPosition(43, 35);
                    setColor(3);
                    std::cout << "读取存档";

                    --m_key;
                    break;
                }
            }
            break;

        case 80:                    // DOWN下方向键
            PlaySound(PATHSELECT, NULL, SND_FILENAME | SND_ASYNC);
            if (m_key < 3)
            {
                switch (m_key)
                {
                case 1:
                    setCursorPosition(43, 33);
                    setBackColor();
                    std::cout << "编辑地图";
                    setCursorPosition(43, 31);
                    setColor(3);  
                    std::cout << "开始游戏";

                    ++m_key;
                    break;
                case 2:
                    setCursorPosition(43, 35);
                    setBackColor();
                    std::cout << "读取存档";
                    setCursorPosition(43, 33);
                    setColor(3);
                    std::cout << "编辑地图";

                    ++m_key;
                    break;
                }
            }
            break;

        case 13:                    // Enter回车键
            PlaySound(PATHSELECTED, NULL, SND_FILENAME | SND_ASYNC);
            flag = true;
            break;
        default:                    // 无效按键
            break; 
        }
        if (flag) break;            // 输入Enter回车键确认，退出检查输入循环
    }
    Sleep(1500);
}


/************************************** 绘制游戏界面 ***********************************************/
// 1.功能: 打印不同的地图以及右边游戏信息和功能区
// 2.参数: CMap* init_map 地图类的指针，全局共用一张地图
// 3.返回值: 无
// 4.其他值：editorMap(0, isEditor, m_isRead);  CMap类方法，编辑地图里的障碍，边框默认就有
//           printInitmap();                    CMap类方法，打印地图里的边框和 
// 5.实现方式：主要是调用地图类函数实现，传入正确的参数
/***************************************************************************************************/
void CController::drawMap(CMap* init_map)//绘制游戏界面以及游戏信息
{
    /*绘制地图*/
    system("cls");
    setColor(3);
    if (m_key == 1)
    {
        init_map->editorMap(0, isEditor, m_isRead); 
    }
    m_isRead == 0;
    init_map->printInitmap();

    /*绘制选项和信息栏*/
    setColor(3);
    setCursorPosition(53, 1);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━";
    setCursorPosition(53, 3);
    std::cout << "|  ━━━━━━━━━━━━━━━━   |";
    setCursorPosition(53, 2);
    std::cout << "|                     |";
    setCursorPosition(53, 5);
    std::cout << "|  ━━━━━━━━━━━━━━━━   |";
    setCursorPosition(53, 4);
    std::cout << "|                     |";
    setCursorPosition(53, 6);
    std::cout << "|                     |";
    setCursorPosition(53, 7);
    std::cout << "|                     |";
    setCursorPosition(53, 8);
    std::cout << "|                     |";
    setCursorPosition(53, 9);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━";
    setColor(6);
    setCursorPosition(56, 2);
    std::cout << "Greedy Snake";
    setColor(14);
    setCursorPosition(56, 4);
    std::cout << "得分信息板";
    setCursorPosition(55, 6);
    std::cout << "难度：";
    setCursorPosition(58, 6);
    setCursorPosition(55, 8);
    setColor(14);
    std::cout << "得分：";
    setColor(13);
    setCursorPosition(57, 42);
    std::cout << "操作说明";
    setCursorPosition(50, 43);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    setCursorPosition(51, 46);
    std::cout << " 方向键移动";
    setCursorPosition(62, 46);
    std::cout << " ESC键暂停";
}


/**************************************** 选项执行 *************************************************/
// 1.功能: 根据选项的值执行相应的操作
// 2.参数: 无
// 3.返回值:  
//            CSnake* snake     蛇类指针,共用一条蛇
//            CFood* food       食物类指针,共用一个食物
//            CMap* init_map    地图类指针,共用一张地图
// 4.其他值： fileReading(snake, food); 读取存档函数
// 5.实现方式：根据上一步在showSelect函数中设置的m_key的值，进行相应的操作
//              1是直接进入默认地图障碍
//              2是编辑地图，第一个参数给CMap类函数editorMap();传入1
//              3是进行读取存档操作，调用本类fileReading()函数
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


/**************************************** 游戏结束 *************************************************/
// 1.功能: 蛇头撞击地图边框或者障碍以及自身结束游戏，并进行下一步的选择
// 2.参数: 无
// 3.返回值: 返回1重新开始， 返回2退出游戏
// 4.其他值： 无
// 5.实现方式：重新设置光标的坐标，绘制
/***************************************************************************************************/
int CController::gameEnd()
{
    /*绘制游戏结束界面*/
    Sleep(500);
    setColor(2);
    setCursorPosition(50, 15);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    setCursorPosition(49, 16);
    std::cout << " ┃           Game Over !!!            ┃";
    Sleep(30);
    setCursorPosition(49, 17);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 18);
    std::cout << " ┃          很遗憾！你挂了            ┃";
    Sleep(30);
    setCursorPosition(49, 19);
    std::cout << " ┃          再来一局吧同志！          ┃";
    Sleep(30);
    setCursorPosition(49, 20);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 21);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 22);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 23);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 24);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 25);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 26);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(50, 27);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(100);
    setCursorPosition(52, 25);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "★好啊好啊";
    setCursorPosition(59, 25);
    setColor(11);
    std::cout << "  还是算了吧";

    /*选择部分*/
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
                std::cout << "★好啊好啊";
                setCursorPosition(59, 25);
                setColor(11);
                std::cout << "  还是算了吧";
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                setCursorPosition(59, 25);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "★还是算了吧";
                setCursorPosition(52, 25);
                setColor(11);
                std::cout <<  "  好啊好啊";
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
        return 1;//重新开始
    case 2:
        return 2;//退出游戏
    }
}


/**************************************** 游戏暂停 *************************************************/
// 1.功能: 显示游戏暂停信息并获取下一步的操作
// 2.参数: 无
// 3.返回值: 返回1去存档，返回2退出游戏
// 4.其他值：按ESC继续游戏
// 5.实现方式：
/***************************************************************************************************/
int CController::gamePause()
{
    /*绘制游戏暂停界面*/
    Sleep(500);
    setColor(2);
    setCursorPosition(50, 15);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    setCursorPosition(49, 16);
    std::cout << " ┃          What happened???          ┃";
    Sleep(30);
    setCursorPosition(49, 17);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 18);
    std::cout << " ┃          继续游戏请按ESC           ┃";
    Sleep(30);
    setCursorPosition(49, 19);
    std::cout << " ┃          存档或退出请选择          ┃";
    Sleep(30);
    setCursorPosition(49, 20);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 21);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 22);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 23);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 24);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 25);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(49, 26);
    std::cout << " ┃                                    ┃";
    Sleep(30);
    setCursorPosition(50, 27);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(100);
    setCursorPosition(52, 25);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "★存档文件";
    setCursorPosition(59, 25);
    setColor(11);
    std::cout << "  还是不玩了";

    /*选择部分*/
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
                std::cout << "★存档文件";
                setCursorPosition(59, 25);
                setColor(11);
                std::cout << "  还是不玩了";
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                setCursorPosition(59, 25);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "★还是不玩了";
                setCursorPosition(52, 25);
                setColor(11);
                std::cout << "  存档文件";
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
        return 1; //存档
        break;
    case 2:
        return 2;//退出游戏
    default:
        break;
    }
}


/**************************************** 存档进度 *************************************************/
// 1.功能: 保存游戏状态，存入文件，下次可以读取继续游戏
// 2.参数: CSnake* snake 蛇
//         CFood* food   食物
// 3.返回值: 返回2，存档完毕直接退出游戏
// 4.其他值：GAMEINFO，本类中定义的结构体，用于临时存放游戏信息，在读取文件是起到桥梁作用
// 5.实现方式：共分为两个部分
//    /*将本局游戏信息存放到结构体中*/:创建结构体变量，将游戏信息复制一份到里面    
//    /*将结构体中的信息存入文件中*/:打开文件，将结构体中的信息存入，使用“ab+”的方式，
//                       在文件尾部写入，因为可能会有多组游戏信息,最后关闭文件和new空间
/***************************************************************************************************/
int CController::keepFile(CSnake* snake, CFood* food)
{
    /*将本局游戏信息存放到结构体中*/
    GAMEINFO* gameInfo = new GAMEINFO[1];
    setCursorPosition(50, 28);
    std::cout << "请输入存档点的名称：";
    std::cin >> gameInfo->name;
    memcpy(gameInfo->mapCopy, m_initmap, sizeof(gameInfo->mapCopy));
    gameInfo->foodPosition.X = food->getFoodPsition()->X; 
    gameInfo->foodPosition.Y = food->getFoodPsition()->Y;
    gameInfo->score = m_score;   
    gameInfo->moveSpeed = m_speed;
    gameInfo->snakeLength = snake->getSankeLength(); 
    gameInfo->snakeDirection = snake->getMoveDirection();
    snake->copySnake(gameInfo->snake);

    /*将结构体中的信息存入文件中*/
    FILE* pfile = NULL;
    int err = fopen_s(&pfile, PATHFILE, "ab+");
    int result = fwrite(gameInfo, sizeof(GAMEINFO), 1, pfile);
    setCursorPosition(50, 32);
    setColor(4);
    if (pfile != NULL || err == 0)
    {
        printf("存档成功！");
        setColor(11);
        std::cout << "3秒后退出游戏......";
        Sleep(3000);
    }
    else {
        setColor(4);
        printf("存档失败！");
        setColor(11);
        std::cout << "3秒后退出游戏......";
        Sleep(3000);
    }
    fclose(pfile);
    delete[] gameInfo;
    return 2;
}


/**************************************** 读取存档 *************************************************/
// 1.功能: 读取文件中保存的游戏信息，加载到本局游戏中
// 2.参数: CSnake* snake 蛇
//         CFood* food   食物
// 3.返回值: 返回值1，在beforeGame中返回一个1，在大循环中再次开始游戏，使用读取到的信息
// 4.其他值：m_isRead，设置为1，用于在editorMap()函数中不打印默认地图不进行地图编辑，使用本局地图
//           int i; 数组下标
//           int nCol; 打印信息时的行数
//           int n; n代表玩家选择的存档的序号，也就是结构体数组的下标，下面已经作了- 1 处理
// 5.实现方式：分两步实现
//  /*创建结构体变量用于接收文件内的信息*/：创建一个结构体变量，并打印相关界面信息
//  /*将玩家选择的序号的存档存入游戏中*/：打开一个文件，循环读取文件并将这些信息放入到结构体数组中，
//       同时将这些信息打印出来，供玩家选择，然后按照玩家选择的序号将游戏信息加载到本局游戏，同时
//       关闭文件和delete结构体数组空间,最后返回重新开始游戏的值1
/***************************************************************************************************/
int CController::fileReading(CSnake* snake, CFood* food)
{
    m_isRead = 1; 
    /*创建结构体变量用于接收文件内的信息*/
    system("cls");
    GAMEINFO* temp = new GAMEINFO[30];
    int i = 0;
    int nCol = 8; 
    FILE* pfile = NULL;
    fopen_s(&pfile, PATHFILE, "rb+");
    setCursorPosition(21, nCol);
    setColor(12);
    std::cout << "序号     " << "    存档点名称      " << "    当前分数";
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
        std::cout << "请输入你要选择的存档点序号：";
        std::cin >> n;
        if (n > -1 && n < i + 1)
        {
            n -= 1;
            break;
        }
        setCursorPosition(21, nCol + 4);
        setColor(4);
        std::cout << "没有此存档编号！请重新输入！           ";
        Sleep(3000);
        std::cout << "                                ";
    }

    /*将玩家选择的序号的存档存入游戏中*/
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
    /*按ENTER开始游戏*/
    setColor(4);
    setCursorPosition(20, 1);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    setCursorPosition(20, 2);
    printf(" ┃  存档点序号为 %d ，请按ENTER开始游戏    ┃", n + 1);   
    setCursorPosition(20, 3);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
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


/**************************************** 等待按键 *************************************************/
// 1.功能: 游戏小循环中监听键盘输入
// 2.参数:  
//          moveDirection：本类中代表蛇行进方向的
//          CSnake* snake 蛇
//          CFood* food   食物
// 3.返回值: 返回2，退出游戏，返回1重新开始游戏，其他的都是返回上下左右代表的方向
// 4.其他值：无
// 5.实现方式：分为两个部分，使用_kbhit()函数无阻塞的监听键盘事件
//     第一部分是监听到ESC暂停时，调用gamePause()函数，根据选项返回值执行继续游戏、存档和退出游戏功能
//     第二部分是监听到上下左右，同方向和相反方向不做任何动作
/***************************************************************************************************/
int CController::waitKey(int moveDirection, CSnake* snake, CFood* food)
{
    /*无阻塞监听键盘事件*/
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

        /*判断按键是否是上下左右四个键，如果不是或者反方向就无效*/
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


/**************************************** 游戏小循环 **********************************************/
// 1.功能: 游戏核心环节，实现蛇的移动，方向的变化，食物随机出现，蛇撞墙和吃到食物，速度的变化
// 2.参数:  CSnake* snake 蛇
//          CFood* food   食物
// 3.返回值: 给大循环返回的值，1是重新开始游戏，2是退出游戏
// 4.其他值：
// 5.实现方式：
//     1.蛇的移动：根据蛇的坐标将原有的位置清空，根据行进方向设置蛇身新坐标，先将除了蛇头以外的位置的坐标
//        设置成前一个蛇身的坐标，并根据行进方向将蛇头的横坐标挥着纵坐标更新，最后打印新蛇的位置
//     2.方向变化：根据键盘监听到的返回值，将蛇头的位置坐标改变，带动后面的每一节蛇身发生转弯行为
//     3.食物随机出现：食物出现有两种判定方式，每一次食物出现都会将上一次出现的位置清空，
//        一是设置一个标记foodFlag，当食物被吃掉后标记发生改变，下次循环判断标记生成新的食物
//        二是设置一个时间标记foodFlagConut，如果食物出现的位置不理想，一段时间过后也会生成另一个食物
//     4.蛇撞墙或者吃到食物：判断蛇头坐标为和个障碍物以及自身其他位置做吧是否相同
//     5.速度的变化：根据分数改变睡眠速度m_speed,实现速度的变化
/***************************************************************************************************/
int CController::playGame(CSnake* snake, CFood* food) 
{
    int foodFlag = food->getFoodFlag();
    int foodFlagConut = 0; 
    food->drawOldFood();
    /*开启循环*/
    while (true)   
    {  
        /*食物随机出现*/
        if (foodFlag == 0 || foodFlagConut == 1000)
        {
            foodFlagConut = 0;
            food->drawFood();
        }
        foodFlag++;
        /*蛇撞墙和撞自己*/
        if (snake->isCollision(snake->getSnake()[0].X, snake->getSnake()[0].Y))
        {
            PlaySound(PATHCRUSH, NULL, SND_FILENAME | SND_ASYNC);
            m_speed = 150;
            m_score = 0;
            return gameEnd();
        }
        /*清蛇*/
        snake->writeSnake(0);
        /*更新坐标*/
        snake->updateCoordinates();
        /*蛇吃食物*/
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
        /*画蛇*/
        snake->writeSnake(1);
        /*监听键盘*/
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


/*************************************** 游戏大循环 *************************************************/
// 1.功能:  实现在游戏中重新开始功能
// 2.参数:   无
// 3.返回值: 无
// 4.其他值：
// 5.实现方式：进入程序先显示开始界面，并创建三个全局共用的对象，然后进入循环
//             循环顺序：
// showSelect();//选择界面 ——>  drawMap(init_map);//绘制游戏界面——>playGame(snake, food);//开启游戏循环
// 程序退出之前delete三个对象空间                
/***************************************************************************************************/
void CController::game()
{
    showStart();
    CSnake* snake = new CSnake(); 
    CFood* food = new CFood();
    CMap* init_map = new CMap();
    /*游戏循环*/
    while (true)
    {
        /*选择界面*/
        showSelect();
        /*执行选择*/
        if (1 == beforeGame(snake, food, init_map) )
        {
            continue;
        }
        /*画地图*/
        drawMap(init_map);
        /*游戏小循环*/
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
