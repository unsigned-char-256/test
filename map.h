extern int m_initmap[][50];                                 //全局地图
class CMap
{
public:
    CMap()                                                  //无参构造,设置地图边框,1代表边框
    {
        for (int i = 1; i < 49; i++)
        {   
            m_initmap[i][1] = 1;     
            m_initmap[i][48] = 1;      
        }
        for (int i = 1; i < 49; i++)
        {
            m_initmap[1][i] = 1;  
            m_initmap[48][i] = 1;  
        }
    }

    void printInitmap();                                    //绘制地图

    int editorMap(int n, int isEdited, int isRead);         // 0代表默认地图，1代表绘制玩家编辑的地图

    int traversePoint(int x, int y);                        // 自定义地图时避免重复添加
};

