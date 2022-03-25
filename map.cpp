#include <iostream>
#include "map.h"
#include "tools.h"
#include <conio.h>


/**************************************** 编辑地图 *************************************************/
// 1.功能: 编辑自定义地图、默认地图以及读取存档时不执行编辑操作
// 2.参数: n代表进来时打印的是默认的还是其他的
//         isEdited 代表是否编辑过，编辑过就不打印默认的15PB,打印玩家编辑的地图
//         isRead代表是否读取国存档，读取过的话，地图就已经存在了，不需要进行编辑，直接退出
// 3.返回值: 无
// 4.其他值： 当地图坐标的值为2时，代表障碍物，1代表边框
// 5.实现方式：
/***************************************************************************************************/
// 用于编辑默认地图、自定义地图、以及读取存档后不编辑地图，
int CMap::editorMap(int n, int isEdited, int isRead) // 值为2代表中间障碍物，方便用不同的颜色表示
{
    int nCount = 0;      // 自定义添加时的序号
    int x = 2;           // 光标列坐标
    int y = 2; 
    int addFlag = 0;     // 0没有确认添加，清空前一个点，1是确认添加，不清空
    int ch = 0;          // 接收最后一次按键的值
    switch (n)
    {
    /*编辑成默认的*/
    case 0:  
        if (isRead == 1)
        {
            return 99;  
        }
        if (isEdited == 1)
        {
            break;
        }
        for (int i = 8; i < 21; i++) // 默认1
        {
            m_initmap[i][12] = 2;
            m_initmap[i][13] = 2;
        }


        for (int j = 28; j < 39; j++)  // 默认P
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


        for (int i = 31; i < 37; i++)       // 默认5
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


        for (int i = 28; i < 39; i++)    // 默认B
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
    /*将玩家编辑过的地图写进数组*/
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
        std::cout << "方向键移动黄色方块选择添加点";
        setCursorPosition(54, 7);
        std::cout << "回车键确认添加";
        setCursorPosition(54, 8);
        std::cout << "ESC本次添加完毕";
        
        while (true) // 开启添加循环
        {
            for (int i = 2; i < 48; i++)   // 遍历数组，如果添加过后值会变成2，就在右侧输出个数
            {
                for (int j = 2; j < 48; j++)
                {
                    if (m_initmap[i][j] == 2)
                    {
                        setColor(2);
                        setCursorPosition(54, 10);
                        std::cout << "已添加 " << nCount << " 个元素";
                        setCursorPosition(j,i); // 当前坐标
                        std::cout << "■";
                    }
                }
            }
            setCursorPosition(x, y); // 当前坐标
            setColor(6);
            if (addFlag == 0)  std::cout << "■";
            do
            {
                ch = _getch();
            } while (_kbhit() != 0);  // 消除多余的按键返回值
            setCursorPosition(x, y); // 将光标重新定位回前一个点，用来输出空格或者方块
            addFlag = 0;
                switch (ch)
                {
                case 27:   // ESC按键完成添加，退出
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


/**************************************** 打印地图 *************************************************/
// 1.功能: 在屏幕中打印地图
// 2.参数: 无
// 3.返回值: 无
// 4.其他值： 
// 5.实现方式：遍历地图数组，是1或者2就打印，并且按照不同的颜色，区分边框和障碍物
/***************************************************************************************************/
void CMap::printInitmap()//绘制地图
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
                std::cout << "■";
                pNum++;
            }
            else if (m_initmap[i][j] == 2)
            {
                setColor(6);
                setCursorPosition(j, i);
                std::cout << "■";
                pNum++;
            }
        }
    }
}


/**************************************** 添加障碍 *************************************************/
// 1.功能: 用于在自定义地图中，判断当前行进方向是否已经添加过
// 2.参数: 无
// 3.返回值: 无
// 4.其他值： 
// 5.实现方式：0代表重复，不可以前进，1代表不重复，可以前进
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
                    return 0;  //此时重复了，不能进行移动操作
                }
            }
        }
    }
}